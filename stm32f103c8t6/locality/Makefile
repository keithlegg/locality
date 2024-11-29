


PROJECT = locality
BUILD_DIR = bin

#LDSCRIPT = bluepill.ld
LDFLAGS += bluepill.ld

SHARED_DIR = ../common
CFILES = main.c
CFILES += common.c north_port.c south_port.c test_ports.c
#AFILES += api-asm.S

# TODO - you will need to edit these two lines!
DEVICE=stm32f1
OOCD_FILE = board/thisisbroken.cfg


# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk


.PHONY: program
program:
	st-flash write $(PROJECT).bin 0x8000000 