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

#ifndef _ESPTERM_UI_
#define _ESPTERM_UI_

#include "lvgl.h"

#define UI_WIDTH 256
#define UI_HEIGHT 64

typedef enum {
  FRAG_NONE = 0,
  FRAG_MAIN,
  FRAG_MENU,
  FRAG_ABOUT,
  FRAG_UART,
  FRAG_UART_BAUD,
  FRAG_MAX,
} ui_fragment_id_t;

typedef struct {
  lv_obj_t *(*create)(lv_obj_t *parent, lv_group_t *group);
  void (*show)(void);
} ui_fragment_t;

void ui_report_activity(void);

void ui_fragment_init(void);
void ui_fragment_show(ui_fragment_id_t id);

void ui_list_init(void);

void ui_main_init(ui_fragment_t *frag);
void ui_main_set_text(const char *text);

void ui_menu_init(ui_fragment_t *frag);

void ui_uart_init(ui_fragment_t *frag);
void ui_uart_baud_init(ui_fragment_t *frag);

void ui_about_init(ui_fragment_t *frag);

#endif // _ESPTERM_UI_
