#ifndef ADC_H
#define ADC_H
#define X_CHANNEL 0x00
#define Y_CHANNEL 0x02
#define MIDDLE_VALUE 512
#define PADDING 30

#include <stdint.h>

void adc_init(void);

void adc_start(uint8_t channel);

uint16_t adc_get_x_value(void);

uint16_t adc_get_y_value(void);

uint8_t adc_is_x_ready(void);

uint8_t adc_is_y_ready(void);

uint8_t adc_get_channel(void);

#endif