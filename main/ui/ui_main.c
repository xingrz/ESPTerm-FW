#include "ui.h"

static lv_obj_t *term;

static void ui_main_term_on_event(lv_obj_t *obj, lv_event_t event);

static lv_obj_t *ui_main_create(lv_obj_t *parent, lv_group_t *group) {
  term = lv_label_create(parent, NULL);
  lv_obj_set_pos(term, 0, 0);
  lv_obj_set_event_cb(term, ui_main_term_on_event);
  lv_label_set_long_mode(term, LV_LABEL_LONG_CROP);

  lv_group_add_obj(group, term);

  ui_main_set_text("hello world");

  return term;
}

static void ui_main_show() {
  lv_group_focus_obj(term);
}

void ui_main_set_text(const char *text) {
  if (term != NULL) {
    lv_label_set_text(term, text);
    lv_obj_set_size(term, UI_WIDTH, UI_HEIGHT);
  }
}

static void ui_main_term_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_MENU);
  }
}

void ui_main_init(ui_fragment_t *frag) {
  frag->create = ui_main_create;
  frag->show = ui_main_show;
}
