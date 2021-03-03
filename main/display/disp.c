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

#include <stdint.h>

#include "disp.h"
#include "lvgl.h"
#include "sh1122.h"

#define TAG "disp"
#define DISP_DEBUG 0

#define DISP_BUF_SIZE SCREEN_PIXELS

#if DISP_DEBUG
#include "esp_log.h"
#endif

static void disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area,
                       lv_color_t *color_p) {
#if DISP_DEBUG
  ESP_LOGI(TAG, "flush x1:%d x2:%d y1:%d y2:%d", area->x1, area->x2, area->y1,
           area->y2);
#endif
  sh1122_draw(area->y1, area->y2, (uint8_t *)color_p);
  lv_disp_flush_ready(disp_drv);
}

static void disp_rounder(lv_disp_drv_t *disp_drv, lv_area_t *area) {
#if DISP_DEBUG
  ESP_LOGI(TAG, "rounder x1:%d x2:%d y1:%d y2:%d", area->x1, area->x2, area->y1,
           area->y2);
#endif
  area->x1 = 0;
  area->x2 = SCREEN_WIDTH - 1;
}

static void disp_set_px(lv_disp_drv_t *disp_drv, uint8_t *buf, lv_coord_t buf_w,
                        lv_coord_t x, lv_coord_t y, lv_color_t color,
                        lv_opa_t opa) {
  uint8_t scale = 0;
  if (color.full == 0) {
    scale = opa >> 4;
  }

  uint16_t i = (buf_w >> 1) * y + (x >> 1);
  if (x & 0x1) {
    buf[i] &= ~0x0F;
    buf[i] |= scale;
  } else {
    buf[i] &= ~0xF0;
    buf[i] |= (scale << 4);
  }
}

#if DISP_DEBUG
static void disp_monitor(lv_disp_drv_t *disp_drv, uint32_t time, uint32_t px) {
  ESP_LOGI(TAG, "%d px refreshed in %d ms\n", px, time);
}
#endif

void disp_init(void) {
  sh1122_init();

  static lv_color_t buf[DISP_BUF_SIZE];
  static lv_disp_buf_t disp_buf;
  lv_disp_buf_init(&disp_buf, buf, NULL, DISP_BUF_SIZE);

  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);

  disp_drv.flush_cb = disp_flush;
  disp_drv.rounder_cb = disp_rounder;
  disp_drv.set_px_cb = disp_set_px;
#if DISP_DEBUG
  disp_drv.monitor_cb = disp_monitor;
#endif
  disp_drv.buffer = &disp_buf;
  lv_disp_drv_register(&disp_drv);
}
