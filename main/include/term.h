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

#ifndef _ESPTERM_TERM_
#define _ESPTERM_TERM_

#include <stdint.h>

#define TERM_BAUDRATE_DEFAULT 115200

void term_write_chars(char *buf, uint32_t len);
void term_write(const char *text);

uint32_t term_get_baudrate(void);
void term_set_baudrate(uint32_t baudrate);

#endif // _ESPTERM_TERM_
