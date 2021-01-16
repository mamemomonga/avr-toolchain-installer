# 動作デバイス ( リスト: avr-as -mlist-devices )
DEVICE := attiny412

# 動作クロック
CLOCK := 20000000

# jtag2updi シリアルポート
PORT := /dev/cu.usbserial-0001

# プログラマ
PROGRAMMER := -c jtag2updi -P $(PORT)

# ------------------------------------

HDRS    := $(shell find . -type f -name '*.h')
SRCC    := $(shell find . -type f -name '*.c')
SRCA    := $(shell find . -type f -name '*.S')
OBJS    := $(SRCC:%.c=%.o) $(SRCA:%.S=%.o)
DEPS    := $(OBJS:%.o=%.d)
AVRDUDE := avrdude $(PROGRAMMER) -p $(DEVICE) 
COMPILE := avr-gcc \
	-mmcu=$(DEVICE) -Wall -Os -std=gnu99 -I . -DF_CPU=$(CLOCK) -I $(AVR_DFP)/include -B $(AVR_DFP)/gcc/dev/$(DEVICE) \
	-Wl,-section-start=.data=0x00802000

all:	main.hex

-include $(DEPS)

%.o: %.c
	$(COMPILE) -c -MMD -MP $<

.c.o:
	$(COMPILE) -c $< -o $@

.S.o:
	$(COMPILE) -x assembler-with-cpp -c $< -o $@

.c.s:
	$(COMPILE) -S $< -o $@

flash:	all
	$(AVRDUDE) -U flash:w:main.hex:i

install: flash

load: all
	bootloadHID main.hex

clean:
	rm -f main.hex main.elf $(OBJS) $(OBJS:.o=.d)

main.elf: $(OBJS) $(HDRS)
	$(COMPILE) -o main.elf $(OBJS)

main.hex: main.elf
	rm -f main.hex
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	avr-size --format=avr --mcu=$(DEVICE) main.elf

disasm:	main.elf
	avr-objdump -d main.elf
cpp:
	$(COMPILE) -E main.c

