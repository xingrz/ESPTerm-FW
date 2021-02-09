COMPONENT_SRCDIRS += lvgl/src/lv_core
COMPONENT_SRCDIRS += lvgl/src/lv_hal
COMPONENT_SRCDIRS += lvgl/src/lv_widgets
COMPONENT_SRCDIRS += lvgl/src/lv_font
COMPONENT_SRCDIRS += lvgl/src/lv_misc
COMPONENT_SRCDIRS += lvgl/src/lv_themes
COMPONENT_SRCDIRS += lvgl/src/lv_draw
COMPONENT_SRCDIRS += lvgl/src/lv_gpu

CFLAGS += -DLV_CONF_INCLUDE_SIMPLE

COMPONENT_ADD_INCLUDEDIRS += lvgl
