#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/uart.h"
#include "esp_log.h"
#include "esp_system.h"

#include "term.h"
#include "ui.h"
#include "ui_list.h"

#define TAG "ui_uart"

static lv_obj_t *item_baud;

static void ui_uart_baud_on_event(lv_obj_t *obj, lv_event_t event);
static void ui_uart_back_on_event(lv_obj_t *obj, lv_event_t event);

static lv_obj_t *ui_uart_create(lv_obj_t *parent, lv_group_t *group) {
  lv_obj_t *menu = ui_list(parent);

  item_baud = ui_list_item(menu, group, "  Baud rate: ", ui_uart_baud_on_event);

  ui_list_item(menu, group, "< Back", ui_uart_back_on_event);
  return menu;
}

static void ui_uart_show() {
  lv_group_focus_obj(item_baud);

  lv_obj_t *label_baud = lv_list_get_btn_label(item_baud);
  lv_label_set_text_fmt(label_baud, "  Baud rate: %d", term_get_baudrate());
}

static void ui_uart_baud_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_UART_BAUD);
  }
}

static void ui_uart_back_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    ui_fragment_show(FRAG_MENU);
  }
}

void ui_uart_init(ui_fragment_t *frag) {
  frag->create = ui_uart_create;
  frag->show = ui_uart_show;
}
