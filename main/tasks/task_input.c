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
#include "freertos/queue.h"

#include "driver/gpio.h"
#include "esp_log.h"

#include "input.h"
#include "pinout.h"
#include "tasks.h"

#include "lvgl.h"

#define TAG "task_input"

#define LONG_PRESS_TIMEOUT_MS 500

static xQueueHandle input_q = NULL;
static TickType_t btn_down_ticks = 0;

static void btn_on_pressed(void) {
  ESP_LOGV(TAG, "Pressed");
  input_on_next();
}

static void btn_on_long_pressed(void) {
  ESP_LOGV(TAG, "Long pressed");
  input_on_enter();
}

static void btn_on_down(void) {
  ESP_LOGV(TAG, "Down");
}

static void btn_on_up(void) {
  ESP_LOGV(TAG, "Up");
}

static void input_gpio_event(void *arg) {
  uint32_t num = (uint32_t)arg;
  xQueueSendFromISR(input_q, &num, NULL);
}

void input_proc_task(void *arg) {
  input_q = xQueueCreate(3, sizeof(uint32_t));

  gpio_config_t input = {
      .intr_type = GPIO_INTR_NEGEDGE,
      .pin_bit_mask = (1UL << PIN_KEY_USER),
      .mode = GPIO_MODE_INPUT,
      .pull_up_en = GPIO_PULLUP_ENABLE,
  };

  gpio_config(&input);

  gpio_install_isr_service(0);
  gpio_isr_handler_add(PIN_KEY_USER, input_gpio_event, (void *)PIN_KEY_USER);

  uint32_t num, hold_ms;
  int val;
  while (1) {
    if (btn_down_ticks > 0) {
      val = gpio_get_level(num);
      if (val) {
        btn_down_ticks = 0;
        btn_on_pressed();
      } else {
        TickType_t ticks = xTaskGetTickCount();
        hold_ms = (ticks - btn_down_ticks) * portTICK_PERIOD_MS;
        if (hold_ms >= LONG_PRESS_TIMEOUT_MS) {
          btn_down_ticks = 0;
          btn_on_long_pressed();
        } else {
          goto next;
        }
      }
    }

    if (xQueueReceive(input_q, &num, portMAX_DELAY) != pdPASS) {
      goto next;
    }

    val = gpio_get_level(num);
    if (!val) {
      btn_down_ticks = xTaskGetTickCount();
      btn_on_down();
    } else {
      btn_down_ticks = 0;
      btn_on_up();
    }

  next:
    vTaskDelay(10);
  }

  vTaskDelete(NULL);
}
