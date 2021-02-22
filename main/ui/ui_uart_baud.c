#include <stdlib.h>

#include "esp_log.h"
#include "esp_system.h"

#include "common.h"
#include "term.h"
#include "ui.h"
#include "ui_list.h"

#define TAG "ui_uart_baud"

const char *selections[] = {"9600", "19200", "74880", "115200"};

lv_obj_t *items[COUNT(selections)];

static void ui_uart_baud_rates_on_event(lv_obj_t *obj, lv_event_t event);

static lv_obj_t *ui_uart_baud_create(lv_obj_t *parent, lv_group_t *group) {
  lv_obj_t *rates = ui_list(parent);
  for (uint32_t i = 0; i < COUNT(selections); i++) {
    items[i] =
        ui_list_item(rates, group, selections[i], ui_uart_baud_rates_on_event);
  }
  return rates;
}

static void ui_uart_baud_show() {
  uint32_t rate = term_get_baudrate();
  for (uint32_t i = 0; i < COUNT(items); i++) {
    if (atoi(selections[i]) == rate) {
      lv_group_focus_obj(items[i]);
      break;
    }
  }
}

static void ui_uart_baud_rates_on_event(lv_obj_t *obj, lv_event_t event) {
  if (event == LV_EVENT_PRESSED) {
    for (uint32_t i = 0; i < COUNT(items); i++) {
      if (items[i] == obj) {
        term_set_baudrate(atoi(selections[i]));
        ui_fragment_show(FRAG_MAIN);
        break;
      }
    }
  }
}

void ui_uart_baud_init(ui_fragment_t *frag) {
  frag->create = ui_uart_baud_create;
  frag->show = ui_uart_baud_show;
}
