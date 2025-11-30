# Lesson 1: Learning Microcontrollers

This lesson covers the basics of AVR bare-metal programming. To being, you will need to install the following dependencies:

avr-libc
avrdude
binutils-avr
gcc-avr

The primary strategy goes as follows:

We want to turn a C file into a binary form that the Atmega chip can read. It expects an Intel Hex file, which is flashed using the AVRDUDE utility. To do this compilation, there are a variety of steps that need to be taken:


comm port for Arduino Uno Rev 3: /dev/ttyACMO
command to open arduino gui: run appimage
