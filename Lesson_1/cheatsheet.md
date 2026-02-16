Cheatsheet

DDRx is a memory mapped register, which talks directly to the MCU's GPIO hardware
PORTx is a memory mapped register, wich talks directly to the MCU's GPIO hardware
PINx is a memory mapped register, which talks directly to the MCU's GPIO hardware


DDRB |= (1 << DDB5)


This shows that we're setting the DDB5th bit of the DDRB memory address to 1. In this case, DDB5 is a macro for the number 5.

DDB5, PB5, and PORTB5 are all macros that resolve to the number 5 - however its best to use them in context

////////////////////////////////
PWM macros

TCCR1A - "Timer/Counter Control Register 1 A"
	Memory register with 8 bits: COM1A1, COM1A0, COM1B1, COM1B0, -, -, WGM11, WGM10

TCCR1B - "Timer/Counter Control Register 1 B"
OCR1A  - "Output Compare Register 1 A"



