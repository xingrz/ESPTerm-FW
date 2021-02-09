#ifndef _ESPTERM_READLINE_
#define _ESPTERM_READLINE_

#include <stdint.h>

struct _readline_t;
typedef struct _readline_t readline_t;

readline_t *readline_init(uint32_t max_lines, uint32_t max_chars);
char *readline_put(readline_t *rl, char *data, uint32_t len);

#endif // _ESPTERM_READLINE_
