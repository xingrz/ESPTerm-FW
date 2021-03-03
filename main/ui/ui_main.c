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

#include "ui.h"

static lv_obj_t *term;

static void ui_main_term_on_event(lv_obj_t *obj, lv_event_t event);

static lv_obj_t *ui_main_create(lv_obj_t *parent, lv_group_t *group) {
  term = lv_label_create(parent, NULL);
  lv_obj_set_pos(term, 0, 0);
  lv_obj_set_event_cb(term, ui_main_term_on_event);
  lv_label_set_long_mode(term, LV_LABEL_LONG_CROP);

  lv_group_add_obj(group, term);

  ui_main_set_text("");

  return term;
}

static void ui_main_show() {
  lv_group_focus_obj(term);
}

void ui_main_set_text(const char *text) {
  if (term != NULL) {
    lv_label_set_text(term, text);
    lv_obj_set_size(term, UI_WIDTH, UI_HEIGHT);
  }
}

static void ui_main_term_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_MENU);
  }
}

void ui_main_init(ui_fragment_t *frag) {
  frag->create = ui_main_create;
  frag->show = ui_main_show;
}
