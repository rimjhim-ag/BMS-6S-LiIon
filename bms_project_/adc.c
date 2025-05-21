#include "adc.h"
#include "config.h"
#include <avr/io.h>

void adc_init() {
    ADMUX = (1 << REFS0);
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1);
}

uint16_t adc_read(uint8_t channel) {
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

float adc_read_voltage(uint8_t channel) {
    uint16_t adc_value = adc_read(channel);
    return ((float)adc_value / ADC_MAX) * REF_VOLTAGE * VOLTAGE_DIVIDER_RATIO;
}
