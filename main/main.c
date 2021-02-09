#include <stdlib.h>

#include "esp_log.h"
#include "esp_system.h"

#include "tasks.h"

#include "disp.h"
#include "lvgl.h"

#define TAG "main"

void app_main(void) {
  lv_init();
  disp_init();

  BaseType_t ret = pdFALSE;

  ret = xTaskCreate(gui_proc_task, "gui_proc_task", GUI_PROC_STACK_SIZE, NULL,
                    tskIDLE_PRIORITY + 1, NULL);
  if (ret != pdPASS) {
    ESP_LOGE(TAG, "Failed xTaskCreate(gui_proc_task): %d", ret);
  }

  ret = xTaskCreate(uart_proc_task, "uart_proc_task", UART_PROC_STACK_SIZE,
                    NULL, tskIDLE_PRIORITY + 1, NULL);
  if (ret != pdPASS) {
    ESP_LOGE(TAG, "Failed xTaskCreate(uart_proc_task): %d", ret);
  }

  ESP_LOGI(TAG, "SYSTEM READY");
}
