#ifndef _ESPTERM_TERM_
#define _ESPTERM_TERM_

#include <stdint.h>

#define TERM_BAUDRATE_DEFAULT 115200

void term_write_chars(char *buf, uint32_t len);
void term_write(const char *text);

uint32_t term_get_baudrate(void);
void term_set_baudrate(uint32_t baudrate);

#endif // _ESPTERM_TERM_
