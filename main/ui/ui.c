#include <stdlib.h>

#include "common.h"
#include "input.h"
#include "ui.h"

typedef struct {
  lv_obj_t *obj;
  lv_group_t *group;
} ui_fragment_state_t;

ui_fragment_t fragments[FRAG_MAX] = {0};
ui_fragment_state_t states[FRAG_MAX] = {0};

ui_fragment_id_t current = FRAG_NONE;

static inline void ui_fragment_register(ui_fragment_id_t id,
                                        void (*init)(ui_fragment_t *)) {
  init(&fragments[id]);
}

void ui_fragment_init(void) {
  ui_list_init();

  ui_fragment_register(FRAG_MAIN, ui_main_init);
  ui_fragment_register(FRAG_MENU, ui_menu_init);
  ui_fragment_register(FRAG_ABOUT, ui_about_init);

  lv_obj_t *root = lv_cont_create(lv_scr_act(), NULL);
  lv_obj_set_hidden(root, true);
  lv_obj_set_pos(root, 0, 0);
  lv_obj_set_size(root, UI_WIDTH, UI_HEIGHT);
  lv_obj_set_style_local_radius(root, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 0);
  lv_obj_set_style_local_border_width(root, LV_CONT_PART_MAIN, LV_STATE_DEFAULT,
                                      0);
  lv_obj_set_style_local_margin_all(root, LV_CONT_PART_MAIN, LV_STATE_DEFAULT,
                                    0);
  lv_obj_set_style_local_pad_all(root, LV_CONT_PART_MAIN, LV_STATE_DEFAULT, 0);

  for (int i = 0; i < FRAG_MAX; i++) {
    states[i].group = lv_group_create();
    if (fragments[i].create != NULL) {
      states[i].obj = fragments[i].create(root, states[i].group);
      if (states[i].obj != NULL) {
        lv_obj_set_hidden(states[i].obj, true);
      }
    }
  }

  lv_obj_set_hidden(root, false);
}

void ui_fragment_show(ui_fragment_id_t id) {
  if (states[current].obj != NULL) {
    lv_obj_set_hidden(states[current].obj, true);
  }
  if (fragments[id].show != NULL) {
    fragments[id].show();
  }
  if (states[id].obj != NULL) {
    lv_obj_set_hidden(states[id].obj, false);
  }
  current = id;
}

void input_on_next(void) {
  if (states[current].group != NULL) {
    lv_group_focus_next(states[current].group);
  }
}

void input_on_enter(void) {
  if (states[current].group != NULL) {
    lv_obj_t *obj = lv_group_get_focused(states[current].group);
    if (obj == NULL) return;
    lv_event_send(obj, LV_EVENT_PRESSED, NULL);
  }
}
