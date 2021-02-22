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
  FRAG_MAX,
} ui_fragment_id_t;

typedef struct {
  lv_obj_t *(*create)(lv_obj_t *parent, lv_group_t *group);
  void (*show)(void);
} ui_fragment_t;

void ui_fragment_init(void);
void ui_fragment_show(ui_fragment_id_t id);

void ui_list_init(void);

void ui_main_init(ui_fragment_t *frag);
void ui_main_set_text(const char *text);

void ui_menu_init(ui_fragment_t *frag);

void ui_about_init(ui_fragment_t *frag);

#endif // _ESPTERM_UI_
