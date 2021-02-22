#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_system.h"

#include "ui.h"
#include "ui_list.h"

#define TAG "ui_about"

static void ui_about_back_on_event(lv_obj_t *obj, lv_event_t event);

static lv_obj_t *ui_about_create(lv_obj_t *parent, lv_group_t *group) {
  lv_obj_t *about = ui_list(parent);
  ui_list_item(about, NULL, "ESPTerm", NULL);
  ui_list_item(about, NULL, "  FW ver: " GIT_TAG " (" GIT_INCREMENT ")", NULL);
  ui_list_item(about, NULL, "  commit: " GIT_COMMIT, NULL);
  ui_list_item(about, group, "< Back", ui_about_back_on_event);
  return about;
}

static void ui_about_back_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_MENU);
  }
}

void ui_about_init(ui_fragment_t *frag) {
  frag->create = ui_about_create;
}
