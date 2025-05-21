#ifndef ADC_H
#define ADC_H

#include <stdint.h>

void adc_init();
uint16_t adc_read(uint8_t channel);
float adc_read_voltage(uint8_t channel);

#endif
