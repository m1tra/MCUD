#include "adc.h"
#include "avr/io.h"
#include <avr/interrupt.h>

static volatile uint8_t adc_x_ready;
static volatile uint8_t adc_y_ready;

static volatile uint16_t adc_x_value;
static volatile uint16_t adc_y_value;

static volatile uint8_t adc_current_channel = 0;

void adc_init(void)
{
    ADMUX = (1 << REFS0); // Vэт = 5в

    ADCSRA =
        (1 << ADEN) |
        (1 << ADIE) |
        (1 << ADPS2) |
        (1 << ADPS1) |
        (1 << ADPS0); //~125kHz
}

void adc_start(uint8_t channel)
{
    adc_current_channel = channel;

    ADMUX = (ADMUX & 0xE0) | (channel & 0x1F);

    ADCSRA |= (1 << ADSC);
}

uint16_t adc_get_x_value(void)
{
    adc_x_ready = 0;
    return adc_x_value;
}

uint16_t adc_get_y_value(void)
{
    adc_y_ready = 0;
    return adc_y_value;
}

uint8_t adc_is_x_ready(void)
{
    return adc_x_ready;
};

uint8_t adc_is_y_ready(void)
{
    return adc_y_ready;
};

uint8_t adc_get_channel(void)
{
    return adc_current_channel;
};

ISR(ADC_vect)
{
    if (adc_current_channel == X_CHANNEL)
    {
        adc_x_value = ADC;
        adc_x_ready = 1;

        adc_start(Y_CHANNEL);
    }
    else
    {
        adc_y_value = ADC;
        adc_y_ready = 1;

        adc_start(X_CHANNEL);
    }
}