#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "driver/gpio.h"
#include "driver/spi.h"
#include "esp_log.h"

#include "pinout.h"
#include "sh1122.h"

#define TAG "sh1122"

#define HSPI_MAX_LEN 64

static void hspi_init(void) {
  ESP_LOGV(TAG, "hspi_init enter");

  spi_config_t spi = {
      .interface.val = SPI_DEFAULT_INTERFACE,
      .intr_enable.val = 0,
      .mode = SPI_MASTER_MODE,
      .clk_div = SPI_40MHz_DIV,
      .event_cb = NULL,
  };

  spi_init(HSPI_HOST, &spi);

  ESP_LOGV(TAG, "hspi_init exit");
}

static void hspi_write(void *buf, uint32_t len) {
  spi_trans_t trans = {
      .mosi = buf,
      .bits = {.mosi = len * 8},
  };

  spi_trans(HSPI_HOST, &trans);
}

static void gpio_init() {
  ESP_LOGV(TAG, "gpio_init enter");

  gpio_config_t output = {
      .intr_type = GPIO_INTR_DISABLE,
      .pin_bit_mask = (1UL << PIN_OLED_DC) | (1UL << PIN_OLED_RES),
      .mode = GPIO_MODE_OUTPUT,
      .pull_up_en = GPIO_PULLUP_ENABLE,
      .pull_down_en = GPIO_PULLDOWN_DISABLE,
  };

  gpio_config(&output);

  ESP_LOGV(TAG, "gpio_init exit");
}

static void write_reg(uint8_t val) {
  gpio_set_level(PIN_OLED_DC, 0);
  hspi_write(&val, sizeof(uint8_t));
}

static void write_data(void *buf, uint32_t len) {
  gpio_set_level(PIN_OLED_DC, 1);
  hspi_write(buf, len);
}

void sh1122_init(void) {
  ESP_LOGI(TAG, "Init SH1122...");

  gpio_init();
  hspi_init();
  vTaskDelay(300 / portTICK_PERIOD_MS);

  gpio_set_level(PIN_OLED_RES, 0);
  vTaskDelay(10 / portTICK_PERIOD_MS);
  gpio_set_level(PIN_OLED_RES, 1);

  write_reg(0xAE); // Set display off
  write_reg(0xB0); // Row address Mode Setting
  write_reg(0x00);
  write_reg(0x10); // Set Higher Column Address of display RAM
  write_reg(0x00); // Set Lower Column Address of display RAM
  write_reg(0xD5); // Set Display Clock Divide Ratio/Oscillator Frequency
  write_reg(0x50); // 50 125hz
  write_reg(0xD9); // Set Discharge/Precharge Period
  write_reg(0x22);
  write_reg(0x40); // Set Display Start Line
  write_reg(0x81); // The Contrast Control Mode Set
  write_reg(0xFF);
  write_reg(0xA0); // Set Segment Re-map
  write_reg(0xC0); // Set Common Output Scan Direction
  write_reg(0xD3); // Set Display Offset
  write_reg(0x00);
  write_reg(0xA4); // Set Entire Display OFF/ON
  write_reg(0xA6); // Set Normal/Reverse Display
  write_reg(0xA8); // Set Multiplex Ration
  write_reg(0x3F);
  write_reg(0xAD); // DC-DC Setting
  write_reg(0x80); // DC-DC is disable
  write_reg(0xDB); // Set VCOM Deselect Level
  write_reg(0x30);
  write_reg(0xDC); // Set VSEGM Level
  write_reg(0x30);
  write_reg(0x33); // Set Discharge VSL Level 1.8V
  sh1122_fill(0x00);
  write_reg(0xAF); // Set Display On
}

static void sh1122_prepare(uint8_t x, uint8_t y) {
  write_reg(0xB0);
  write_reg(y);
  write_reg(((x & 0xf0) >> 4) | 0x10);
  write_reg((x & 0x0f));
}

void sh1122_fill(uint8_t color) {
  uint8_t pt[HSPI_MAX_LEN];
  memset(pt, ((color & 0xF) << 4) | (color & 0xF), sizeof(pt));
  sh1122_prepare(0, 0);
  for (int i = 0; i < SCREEN_PIXELS >> 1; i += sizeof(pt)) {
    write_data(pt, sizeof(pt));
  }
}

void sh1122_draw(uint8_t y1, uint8_t y2, uint8_t *src) {
  sh1122_prepare(0, y1);
  for (int i = 0; i < (SCREEN_WIDTH >> 1) * (y2 + 1 - y1); i += HSPI_MAX_LEN) {
    write_data(src + i, HSPI_MAX_LEN);
  }
}
