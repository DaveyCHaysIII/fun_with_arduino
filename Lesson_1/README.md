# Lesson 1: Learning Microcontrollers

This lesson covers the basics of AVR bare-metal programming. To being, you will need to install the following dependencies:

avr-libc
avrdude
binutils-avr
gcc-avr

The primary strategy goes as follows:

We want to turn a C file into a binary form that the Atmega chip can read. It expects an Intel Hex file, which is flashed using the AVRDUDE utility. To do this compilation, there are a variety of steps that need to be taken:

1. First, we tell the compiler to output an object file configured for our device and clock speed

	avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o file.o file.c

	-Os:		optimize for size (optional)
	-DF_CPU: 	Defines macro F_CPU at compile time of CPU freq (16MHz)
	-mmcu:		targets a specific microcontroller using presets for correct registers, instructions, memory layouts, interrupt vectors, etc.
	-c:		compile only - do not link
	-o:		output file name file.o

2. Second, we compile that object file to a binary

	avr-gcc -o file.bin file.o

	-o: 		output file name file.o

3. Third, we convert the .bin to a .hex and remove the EEPROM section (best practice to change EEPROM and FLASH as two different operations)

	avr-objcopy -O ihex -R .eeprom file.bin file.hex

	-O: 		output format <>, in our case intel hex (ihex)
	-R:		Remove section, in our case the .eeprom section

4. Finally, we feed that .hex file to our flasher AVRDUDE who writes it to the chip.

	sudo avrdude -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:file.hex:i

	-c:		sets programmer type
	-p:		specifies part number
	-P:		sets the port or serial device, in our case its /dev/ttyACM0
	-b:		sets the baud rate
	-U:		Memory Operations - tells it to flash : write : file : format

