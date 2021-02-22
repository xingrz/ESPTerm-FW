#include <stdlib.h>

#include "ui.h"
#include "ui_list.h"

static lv_style_t *style_list;
static lv_style_t *style_item;

lv_obj_t *ui_list(lv_obj_t *parent) {
  lv_obj_t *list = lv_list_create(parent, NULL);
  lv_obj_set_pos(list, 0, 0);
  lv_obj_set_size(list, UI_WIDTH, UI_HEIGHT);
  lv_obj_add_style(list, LV_OBJ_PART_MAIN, style_list);
  return list;
}

lv_obj_t *ui_list_item(lv_obj_t *list, lv_group_t *group, const char *text,
                       lv_event_cb_t event_cb) {
  lv_obj_t *item = lv_list_add_btn(list, NULL, text);
  lv_obj_add_style(item, LV_BTN_PART_MAIN, style_item);
  if (event_cb != NULL) lv_obj_set_event_cb(item, event_cb);
  if (group != NULL) lv_group_add_obj(group, item);
  return item;
}

void ui_list_init(void) {
  style_list = (lv_style_t *)malloc(sizeof(lv_style_t));
  lv_style_init(style_list);
  lv_style_set_border_color(style_list, LV_STATE_DEFAULT, LV_COLOR_BLACK);
  lv_style_set_border_width(style_list, LV_STATE_DEFAULT, 1);
  lv_style_set_border_side(style_list, LV_STATE_DEFAULT, LV_BORDER_SIDE_FULL);
  lv_style_set_radius(style_list, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_ver(style_list, LV_STATE_DEFAULT, 2);
  lv_style_set_pad_hor(style_list, LV_STATE_DEFAULT, 0);
  lv_style_set_margin_all(style_list, LV_STATE_DEFAULT, 0);

  style_item = (lv_style_t *)malloc(sizeof(lv_style_t));
  lv_style_init(style_item);
  lv_style_set_radius(style_item, LV_STATE_DEFAULT, 0);
  lv_style_set_border_width(style_item, LV_STATE_DEFAULT, 0);
  lv_style_set_pad_ver(style_item, LV_STATE_DEFAULT, 1);
  lv_style_set_pad_hor(style_item, LV_STATE_DEFAULT, 6);
  lv_style_set_margin_all(style_item, LV_STATE_DEFAULT, 0);
  lv_style_set_bg_color(style_item, LV_STATE_DEFAULT, LV_COLOR_TRANSP);
  lv_style_set_text_color(style_item, LV_STATE_DEFAULT, LV_COLOR_BLACK);
  lv_style_set_bg_color(style_item, LV_STATE_FOCUSED, LV_COLOR_BLACK);
  lv_style_set_text_color(style_item, LV_STATE_FOCUSED, LV_COLOR_TRANSP);
  lv_style_set_outline_width(style_item, LV_STATE_FOCUSED, 0);
}
