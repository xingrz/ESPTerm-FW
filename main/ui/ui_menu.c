#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_log.h"
#include "esp_system.h"

#include "ui.h"
#include "ui_list.h"

#define TAG "ui_menu"

static lv_obj_t *first;

static void ui_menu_uart_on_event(lv_obj_t *obj, lv_event_t event);
static void ui_menu_about_on_event(lv_obj_t *obj, lv_event_t event);
static void ui_menu_back_on_event(lv_obj_t *obj, lv_event_t event);

static lv_obj_t *ui_menu_create(lv_obj_t *parent, lv_group_t *group) {
  lv_obj_t *menu = ui_list(parent);
  first = ui_list_item(menu, group, "  UART", ui_menu_uart_on_event);
  ui_list_item(menu, group, "  About", ui_menu_about_on_event);
  ui_list_item(menu, group, "< Back", ui_menu_back_on_event);
  return menu;
}

static void ui_menu_show() {
  lv_group_focus_obj(first);
}

static void ui_menu_uart_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_UART);
  }
}

static void ui_menu_about_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_ABOUT);
  }
}

static void ui_menu_back_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_MAIN);
  }
}

void ui_menu_init(ui_fragment_t *frag) {
  frag->create = ui_menu_create;
  frag->show = ui_menu_show;
}
