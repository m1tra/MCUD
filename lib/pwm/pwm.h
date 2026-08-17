#ifndef PWM_H
#define PWM_H

#include <stdint.h>
#include <avr/io.h>
#include <gpio.h>

typedef struct {
    GPIO_pin pin;
    
} PWM_settings;

void pwm_init(PWM_settings pwm);

#endif
