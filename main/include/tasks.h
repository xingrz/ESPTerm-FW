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

#ifndef _ESPTERM_TASKS_
#define _ESPTERM_TASKS_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LV_PROC_STACK_SIZE (2 * 1024)
#define UI_PROC_STACK_SIZE (10 * 1024)
#define INPUT_PROC_STACK_SIZE (2 * 1024)
#define UART_PROC_STACK_SIZE (2 * 1024)

void lv_proc_task(void *arg);
void ui_proc_task(void *arg);
void input_proc_task(void *arg);
void uart_proc_task(void *arg);

#endif // _ESPTERM_TASKS_
