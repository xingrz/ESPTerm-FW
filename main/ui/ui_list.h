#ifndef __ESPTERM_UI_LIST__
#define __ESPTERM_UI_LIST__

#include "lvgl.h"

lv_obj_t *ui_list(lv_obj_t *parent);
lv_obj_t *ui_list_item(lv_obj_t *list, lv_group_t *group, const char *text,
                       lv_event_cb_t event_cb);

#endif // __ESPTERM_UI_LIST__
