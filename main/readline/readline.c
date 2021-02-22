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

static void readline_buffer_init(readline_t *rl) {
  rl->buffer = (char *)malloc(rl->buffer_size);
  memset(rl->buffer, 0, rl->buffer_size);
}

static bool readline_buffer_shift(readline_t *rl) {
  uint32_t removed = 0;

  char *first = strchr(rl->buffer, '\n');
  if (first != NULL) {
    char *second = first + 1;
    char *old = rl->buffer;
    readline_buffer_init(rl);
    memcpy(rl->buffer, second, strlen(second));
    free(old);
    removed = second - old;
  }

  if (removed > 0) {
    rl->offset -= removed;
    rl->lines -= 1;
    return true;
  } else {
    return false;
  }
}

static void readline_buffer_put(readline_t *rl, char c) {
  rl->buffer[rl->offset] = c;
  rl->offset++;
  rl->chars++;
}

static void readline_buffer_del(readline_t *rl) {
  if (rl->chars > 0) {
    rl->offset--;
    rl->chars--;
    rl->buffer[rl->offset] = 0;
  }
}

static void readline_buffer_reset(readline_t *rl) {
  rl->offset -= rl->chars;
  rl->chars = 0;
}

static void readline_buffer_new_line(readline_t *rl) {
  rl->lines++;
  rl->chars = 0;
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
    char c = data[i];
    switch (c) {
      case '\033': {
        rl->coloring = true;
        break;
      }
      case 'm': {
        if (rl->coloring) {
          rl->coloring = false;
        } else {
          readline_buffer_put(rl, c);
          changed = true;
        }
        break;
      }
      case '\r': {
        readline_buffer_reset(rl);
        changed = true;
        break;
      }
      case '\n': {
        if (rl->offset > 0 && rl->buffer[rl->offset - 1] != '\n') {
          readline_buffer_put(rl, c);
          readline_buffer_new_line(rl);
          changed = true;
        }
        break;
      }
      case 0x08: { // back space
        readline_buffer_del(rl);
        changed = true;
        break;
      }
      default: {
        if (!rl->coloring && rl->chars <= rl->max_chars) {
          readline_buffer_put(rl, c);
          changed = true;
        }
      }
    }
    if (rl->lines >= rl->max_lines) {
      changed = readline_buffer_shift(rl);
    }
  }
  if (changed) {
    return rl->buffer;
  } else {
    return NULL;
  }
}
