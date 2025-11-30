MCU = atmega328p
F_CPU = 16000000UL
PORT = /dev/ttyACM0
BAUD = 115200
PROGRAM = breadboard-blink

all: $(PROGRAM).hex

# 1. Compile .c → .o
%.o: %.c
	avr-gcc -Os -DF_CPU=$(F_CPU) -mmcu=$(MCU) -c -o $@ $<

# 2. Link .o → .elf
$(PROGRAM).elf: $(PROGRAM).o
	avr-gcc -mmcu=$(MCU) -o $@ $<

# 3. Convert .elf → .hex
$(PROGRAM).hex: $(PROGRAM).elf
	avr-objcopy -O ihex -R .eeprom $< $@

# Upload to Arduino
upload: $(PROGRAM).hex
	avrdude -c arduino -p $(MCU) -P $(PORT) -b $(BAUD) \
		-U flash:w:$(PROGRAM).hex:i

# Cleanup
clean:
	rm -f *.o *.elf *.hex

# MAKE - SUDO MAKE UPLOAD - MAKE CLEAN

