#ifndef _ESPTERM_SH1122_
#define _ESPTERM_SH1122_

#include <stdint.h>

#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 64

#define SCREEN_PIXELS (SCREEN_WIDTH * SCREEN_HEIGHT)

void sh1122_init(void);

void sh1122_fill(uint8_t color);
void sh1122_draw(uint8_t y1, uint8_t y2, uint8_t *src);

#endif // _ESPTERM_SH1122_
