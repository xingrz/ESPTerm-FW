#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/uart.h"

#include "esp_log.h"
#include "esp_system.h"
#include "nvs.h"

#include "lvgl.h"
#include "pinout.h"
#include "readline.h"
#include "tasks.h"
#include "term.h"
#include "ui.h"

#define TAG "task_uart"

#define TERM_WIDTH (64 + 1)
#define TERM_LINES (5)

#define TERM_NVS_NAME "espterm.uart"
#define TERM_NVS_KEY_BAUDRATE "baudrate"

nvs_handle nvs;
readline_t *rl;

void uart_proc_task(void *arg) {
  ESP_ERROR_CHECK(nvs_open(TERM_NVS_NAME, NVS_READWRITE, &nvs));

  uint32_t baudrate = term_get_baudrate();

  uart_config_t uart_config = {
      .baud_rate = baudrate,
      .data_bits = UART_DATA_8_BITS,
      .parity = UART_PARITY_DISABLE,
      .stop_bits = UART_STOP_BITS_1,
      .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
  };
  uart_param_config(UART_TERM, &uart_config);
  uart_driver_install(UART_TERM, TERM_WIDTH * 2, 0, 0, NULL, 0);

  rl = readline_init(TERM_LINES, TERM_WIDTH);

  char recv[TERM_WIDTH];
  sprintf(recv, "[ Inited with baud rate: %d ]\n", baudrate);
  term_write(recv);

  while (1) {
    int len = uart_read_bytes(UART_TERM, (unsigned char *)recv, sizeof(recv),
                              20 / portTICK_PERIOD_MS);
    term_write_chars(recv, len);
  }

  vTaskDelete(NULL);
}

void term_write_chars(char *buf, uint32_t len) {
  uart_write_bytes(UART_TERM, (const char *)buf, len);
  char *lines = readline_put(rl, buf, len);
  if (lines != NULL) {
    ui_main_set_text((const char *)lines);
  }
}

void term_write(const char *text) {
  term_write_chars((char *)text, strlen(text));
}

uint32_t term_get_baudrate(void) {
  uint32_t baudrate = 0;
  nvs_get_u32(nvs, TERM_NVS_KEY_BAUDRATE, &baudrate);
  if (baudrate == 0) baudrate = TERM_BAUDRATE_DEFAULT;
  return baudrate;
}

void term_set_baudrate(uint32_t baudrate) {
  ESP_ERROR_CHECK(nvs_set_u32(nvs, TERM_NVS_KEY_BAUDRATE, baudrate));
  ESP_ERROR_CHECK(uart_set_baudrate(UART_TERM, baudrate));

  char hint[TERM_WIDTH];
  sprintf(hint, "[ Baud rate changed to: %d ]\n", baudrate);
  term_write(hint);
}
