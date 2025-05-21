# Battery Management System (BMS) for 6 Li-ion Cells in Series

## Overview

This project implements a scalable Battery Management System (BMS) in Embedded C for microcontrollers like ATmega328 or STM32. It monitors 6 Li-ion cells connected in series and handles:

- Cell voltage measurement
- Over-voltage/under-voltage protection
- Passive balancing logic
- UART-based logging (optional)

## File Structure

- `main.c`: Entry point, runs the main control loop.
- `bms.c/h`: BMS logic for checking and balancing cells.
- `adc.c/h`: Modular ADC read interface.
- `config.h`: Configuration constants.
- `uart.c/h`: UART logging interface (optional).
