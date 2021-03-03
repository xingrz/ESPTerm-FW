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

#include "ui.h"
#include "ui_list.h"

#define TAG "ui_about"

static void ui_about_back_on_event(lv_obj_t *obj, lv_event_t event);

static lv_obj_t *ui_about_create(lv_obj_t *parent, lv_group_t *group) {
  lv_obj_t *about = ui_list(parent);
  ui_list_item(about, NULL, "ESPTerm", NULL);
  ui_list_item(about, NULL, "  FW ver: " GIT_TAG " (" GIT_INCREMENT ")", NULL);
  ui_list_item(about, NULL, "  commit: " GIT_COMMIT, NULL);
  ui_list_item(about, group, "< Back", ui_about_back_on_event);
  return about;
}

static void ui_about_back_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_MENU);
  }
}

void ui_about_init(ui_fragment_t *frag) {
  frag->create = ui_about_create;
}
