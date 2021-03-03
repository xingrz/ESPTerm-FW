/**
 *  ESPTerm - A portable serial monitor
 *  Copyright (C) 2021 XiNGRZ <hi@xingrz.me>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_system.h"
#include "esp_timer.h"

#include "lvgl.h"
#include "tasks.h"
#include "ui.h"

#define TAG "task_ui"

#define SLEEP_TIMEOUT_MS 15000

static volatile int64_t last_active_ms = 0;
static volatile bool active = false;

void ui_proc_task(void *arg) {
  ui_fragment_init();
  ui_fragment_show(FRAG_MAIN);

  while (1) {
    if (active) {
      int64_t now = esp_timer_get_time() / 1000;
      if (now - last_active_ms >= SLEEP_TIMEOUT_MS) {
        active = false;
        ui_fragment_show(FRAG_NONE);
      }
    }
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }

  vTaskDelete(NULL);
}

void ui_report_activity(void) {
  last_active_ms = esp_timer_get_time() / 1000;
  if (!active) {
    active = true;
    ui_fragment_show(FRAG_MAIN);
  }
}
