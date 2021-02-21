#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "readline.h"

struct _readline_t {
  char *buffer;
  uint32_t buffer_size;
  uint32_t max_lines;
  uint32_t max_chars;
  uint32_t offset;
  uint32_t lines;
  uint32_t chars;
  bool coloring;
};

static inline void readline_buffer_init(readline_t *rl) {
  rl->buffer = (char *)malloc(rl->buffer_size);
  memset(rl->buffer, 0, rl->buffer_size);
}

static inline uint32_t readline_buffer_shift(readline_t *rl) {
  char *first = strchr(rl->buffer, '\n');
  if (first != NULL) {
    char *second = first + 1;
    char *old = rl->buffer;
    readline_buffer_init(rl);
    memcpy(rl->buffer, second, strlen(second));
    free(old);
    return second - old;
  } else {
    return 0;
  }
}

readline_t *readline_init(uint32_t max_lines, uint32_t max_chars) {
  readline_t *rl = (readline_t *)malloc(sizeof(readline_t));
  memset(rl, 0, sizeof(readline_t));

  rl->buffer_size = max_chars * (max_lines + 1);
  rl->max_lines = max_lines;
  rl->max_chars = max_chars;

  readline_buffer_init(rl);

  return rl;
}

char *readline_put(readline_t *rl, char *data, uint32_t len) {
  bool changed = false;
  for (uint32_t i = 0; i < len; i++) {
    if (data[i] == '\033') {
      rl->coloring = true;
    } else if (rl->coloring && data[i] == 'm') {
      rl->coloring = false;
    } else if ((!rl->coloring && rl->chars <= rl->max_chars &&
                data[i] != '\r') ||
               data[i] == '\n') {
      rl->buffer[rl->offset] = data[i];
      rl->offset++;
      rl->chars++;
      changed = true;
    }
    if (data[i] == '\n') {
      rl->lines++;
      rl->chars = 0;
      changed = true;
    }
    if (rl->lines >= rl->max_lines) {
      uint32_t removed = readline_buffer_shift(rl);
      if (removed > 0) {
        rl->offset -= removed;
        rl->lines -= 1;
        changed = true;
      }
    }
  }
  if (changed) {
    return rl->buffer;
  } else {
    return NULL;
  }
}
