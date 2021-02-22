#include <stdlib.h>

#include "esp_log.h"
#include "esp_system.h"
#include "nvs.h"
#include "nvs_flash.h"

#include "tasks.h"

#include "disp.h"
#include "lvgl.h"

#define TAG "main"

void app_main(void) {
  esp_err_t ret = nvs_flash_init();
  if (ret == ESP_ERR_NVS_NO_FREE_PAGES) {
    ESP_ERROR_CHECK(nvs_flash_erase());
    ret = nvs_flash_init();
  }
  ESP_ERROR_CHECK(ret);

  lv_init();
  disp_init();

  assert(pdPASS == xTaskCreate(lv_proc_task, "lv_proc_task", LV_PROC_STACK_SIZE,
                               NULL, tskIDLE_PRIORITY + 1, NULL));

  assert(pdPASS == xTaskCreate(input_proc_task, "input_proc_task",
                               INPUT_PROC_STACK_SIZE, NULL,
                               tskIDLE_PRIORITY + 1, NULL));

  assert(pdPASS == xTaskCreate(ui_proc_task, "ui_proc_task", UI_PROC_STACK_SIZE,
                               NULL, tskIDLE_PRIORITY + 1, NULL));

  vTaskDelay(500 / portTICK_PERIOD_MS);

  assert(pdPASS == xTaskCreate(uart_proc_task, "uart_proc_task",
                               UART_PROC_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1,
                               NULL));

  ESP_LOGI(TAG, "SYSTEM READY");
}
