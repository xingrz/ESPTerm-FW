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

#include "driver/uart.h"
#include "esp_log.h"
#include "esp_system.h"

#include "term.h"
#include "ui.h"
#include "ui_list.h"

#define TAG "ui_uart"

static lv_obj_t *item_baud;

static void ui_uart_baud_on_event(lv_obj_t *obj, lv_event_t event);
static void ui_uart_back_on_event(lv_obj_t *obj, lv_event_t event);

static lv_obj_t *ui_uart_create(lv_obj_t *parent, lv_group_t *group) {
  lv_obj_t *menu = ui_list(parent);

  item_baud = ui_list_item(menu, group, "  Baud rate: ", ui_uart_baud_on_event);

  ui_list_item(menu, group, "< Back", ui_uart_back_on_event);
  return menu;
}

static void ui_uart_show() {
  lv_group_focus_obj(item_baud);

  lv_obj_t *label_baud = lv_list_get_btn_label(item_baud);
  lv_label_set_text_fmt(label_baud, "  Baud rate: %d", term_get_baudrate());
}

static void ui_uart_baud_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_UART_BAUD);
  }
}

static void ui_uart_back_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_MENU);
  }
}

void ui_uart_init(ui_fragment_t *frag) {
  frag->create = ui_uart_create;
  frag->show = ui_uart_show;
}
