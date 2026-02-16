#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL              /* 16 MHz CPU clock */
#define BAUD_RATE 9600
#define UBRR_VALUE ((F_CPU / (16UL * BAUD_RATE)) - 1)

void uart_init(void)
{
    /* Set baud rate */
    UBRR0H = (uint8_t)(UBRR_VALUE >> 8);
    UBRR0L = (uint8_t)UBRR_VALUE;  // (typo fix: UBRR0L — see note below)

    /* Enable TX */
    UCSR0B = (1 << TXEN0);

    /* Frame format: 8N1 */
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_send_char(char c)
{
    /* Wait for transmit buffer to be empty */
    while (!(UCSR0A & (1 << UDRE0)))
        ;

    /* Put data into buffer, sends the byte */
    UDR0 = c;
}

void uart_send_string(const char *s)
{
    while (*s)
    {
        uart_send_char(*s++);
    }
}

int main(void)
{
    const char *msg = "Hi\n";

    /* Initialize UART */
    uart_init();

    /* Set PB5 as output (onboard LED) */
    DDRB |= (1 << DDB5);

    while (1)
    {
        /* Send message */
        uart_send_string(msg);

        /* Toggle LED */
        PORTB ^= (1 << PORTB5);

        /* Small delay so you don’t spam UART too fast */
        _delay_ms(500);
    }

    return 0;
}

