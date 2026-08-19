#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include <avr/io.h>
#include <gpio.h>

typedef struct
{
    GPIO_pin *pin;
    uint32_t freq;
    uint8_t duty;
} Settings;

void pwm_init(Settings pwm_settings);

#endif
