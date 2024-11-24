CROSS_COMPILE = arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
OBJCOPY = $(CROSS_COMPILE)objcopy
CPUFLAGS = -mcpu=cortex-m3 -mthumb
CFLAGS = -Wall -Wextra -g3 -O0 -MD $(CPUFLAGS) -DSTM32F1 -Ilibopencm3/include
LDFLAGS = $(CPUFLAGS) -nostartfiles -Llibopencm3/lib -Wl,-T,bluepill.ld
LDLIBS = -lopencm3_stm32f1 -lc -lnosys


PROJ_NAME = main


CSRC = $(PROJ_NAME).c
OBJ = $(CSRC:.c=.o)

$(PROJ_NAME).elf: $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ) $(LDLIBS)
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin

.PHONY: libopencm3
libopencm3:
	if [ ! -f libopencm3/Makefile ]; then \
		git submodule init; \
		git submodule update; \
	fi
	$(MAKE) -C libopencm3 lib/stm32/f1

.PHONY: clean
clean:
	-rm -rf *.o *.bin *.elf *.map *.d
	#-$(MAKE) -C libopencm3 clean


.PHONY: program
program:
	st-flash write $(PROJ_NAME).bin 0x8000000

#THIS DOES NOT WORK!! DEBUG - ADDED TO .elf SECTION ABOVE 
%.bin: %.elf
	echo "HELLO WHY U NO SEE ME??!!??"	
	#$(OBJCOPY) -O binary $< $@
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin


