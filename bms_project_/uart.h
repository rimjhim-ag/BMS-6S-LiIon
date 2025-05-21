#ifndef UART_H
#define UART_H

#include <stdint.h>

void uart_init();
void uart_send(char* str);
void uart_send_number(uint8_t num);

#endif
