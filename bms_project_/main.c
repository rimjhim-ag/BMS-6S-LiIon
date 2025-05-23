#include "bms.h"
#include "adc.h"
#include "uart.h"
#include <util/delay.h>
#include "current.h"
#include "temperature.h"

int main(void) {
    adc_init();
    uart_init();
    bms_init();
    current_init();
    temperature_init();

    while (1) {
        bms_update();
        check_current_protection();
        check_temperature_protection();
        _delay_ms(1000);
    }
}


