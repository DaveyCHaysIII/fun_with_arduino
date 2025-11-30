#Chip = atmega328p
#cpu clock = 16MhZ, or 16 000 000
#port to arduino: /dev/ttyACM0
#serial baud rate to perform write = 115200
#avr-gcc flags: -Os, -DF_CPU, -mmcu, -c, -o
#avr-objcopy flags: -O, -R
#avrdude flags: -F, -V, -c, -p, -P, -b, -U
default:
	#first, we compile to an object file
	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o on-board-blink.o on-board-blink.c
	#second, we compile to a .bin
	avr-gcc -o on-board-blink.bin on-board-blink.o
	#third, we convert the .bin to a .hex, and remove .eeprom section
	avr-objcopy -O ihex -R .eeprom on-board-blink.bin on-board-blink.hex
	#last, we push that file to arduino. Easy!
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:on-board-blink.hex
