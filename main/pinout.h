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

#ifndef _ESPTERM_PINOUT_
#define _ESPTERM_PINOUT_

#include "driver/gpio.h"

#define PIN_KEY_USER GPIO_NUM_0

#define PIN_OLED_DC GPIO_NUM_5
#define PIN_OLED_RES GPIO_NUM_4

#define UART_TERM UART_NUM_0

#endif // _ESPTERM_PINOUT_
