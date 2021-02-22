#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/uart.h"

#include "esp_log.h"
#include "esp_system.h"

#include "lvgl.h"
#include "readline.h"
#include "tasks.h"
#include "ui.h"

#define TAG "task_uart"

#define TERM_WIDTH (64 + 1)
#define TERM_LINES (5)

void uart_proc_task(void *arg) {
  uart_config_t uart_config = {
      .baud_rate = 115200,
      .data_bits = UART_DATA_8_BITS,
      .parity = UART_PARITY_DISABLE,
      .stop_bits = UART_STOP_BITS_1,
      .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
  };
  uart_param_config(UART_NUM_0, &uart_config);
  uart_driver_install(UART_NUM_0, TERM_WIDTH * 2, 0, 0, NULL, 0);

  readline_t *rl = readline_init(TERM_LINES, TERM_WIDTH);

  char recv[TERM_WIDTH];
  while (1) {
    int len = uart_read_bytes(UART_NUM_0, (unsigned char *)recv, sizeof(recv),
                              20 / portTICK_PERIOD_MS);
    uart_write_bytes(UART_NUM_0, (const char *)recv, len);
    char *lines = readline_put(rl, recv, len);
    if (lines != NULL) {
      ui_main_set_text((const char *)lines);
    }
  }

  vTaskDelete(NULL);
}
