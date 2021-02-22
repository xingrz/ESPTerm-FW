#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_system.h"

#include "lvgl.h"
#include "tasks.h"
#include "ui.h"

#define TAG "task_ui"

void ui_proc_task(void *arg) {
  ui_fragment_init();
  ui_fragment_show(FRAG_MAIN);
  vTaskDelete(NULL);
}
