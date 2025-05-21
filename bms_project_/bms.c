#include "bms.h"
#include "adc.h"
#include "uart.h"
#include "config.h"

float cell_voltages[NUM_CELLS];

void bms_init() {
    for (int i = 0; i < NUM_CELLS; i++) {
        cell_voltages[i] = 0;
    }
}

void bms_update() {
    float total = 0;
    for (int i = 0; i < NUM_CELLS; i++) {
        cell_voltages[i] = adc_read_voltage(i);
        total += cell_voltages[i];

        if (cell_voltages[i] < MIN_CELL_VOLTAGE) {
            uart_send("Under-voltage detected on cell ");
            uart_send_number(i);
        } else if (cell_voltages[i] > MAX_CELL_VOLTAGE) {
            uart_send("Over-voltage detected on cell ");
            uart_send_number(i);
        }
    }

    float average = total / NUM_CELLS;

    for (int i = 0; i < NUM_CELLS; i++) {
        if (cell_voltages[i] > average + BALANCE_THRESHOLD) {
            // Replace with actual GPIO balancing logic
            uart_send("Balancing cell ");
            uart_send_number(i);
        }
    }
}
