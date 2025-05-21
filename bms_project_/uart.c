#include "uart.h"
#include <avr/io.h>

void uart_init() {
    UBRR0H = 0;
    UBRR0L = 103;
    UCSR0B = (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_send(char* str) {
    while (*str) {
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = *str++;
    }
}

void uart_send_number(uint8_t num) {
    char buffer[4];
    itoa(num, buffer, 10);
    uart_send(buffer);
    uart_send("\n");
}
