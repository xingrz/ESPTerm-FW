COMPONENT_ADD_INCLUDEDIRS += .
COMPONENT_ADD_INCLUDEDIRS += include

COMPONENT_SRCDIRS += display
COMPONENT_SRCDIRS += font
COMPONENT_SRCDIRS += readline
COMPONENT_SRCDIRS += tasks
COMPONENT_SRCDIRS += ui

CFLAGS += -DGIT_TAG="\"$(shell git describe --tags --abbrev=0)\""
CFLAGS += -DGIT_COMMIT="\"$(shell git rev-parse --short HEAD)\""
CFLAGS += -DGIT_INCREMENT="\"$(shell git rev-list --count HEAD)\""
