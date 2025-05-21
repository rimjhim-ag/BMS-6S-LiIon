#include "bms.h"
#include "adc.h"
#include "uart.h"
#include <util/delay.h>

int main(void) {
    adc_init();
    uart_init();
    bms_init();

    while (1) {
        bms_update();
        _delay_ms(1000);
    }
}
