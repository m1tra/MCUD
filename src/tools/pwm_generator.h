#include "gpio.h"
#include <avr/io.h>
#ifndef PWM_GENERATOR_H
#define PWM_GENERATOR_H



extern GPIO_pin PH3_pin;
extern GPIO_pin PH4_pin;
extern GPIO_pin PH5_pin;



void pin_action(void);
void duty_action(void);
void freq_action(void);
void confirm_action(void);

void draw_pin(void);
void draw_freq(void);
void draw_duty(void);

void pwm_generator(void);
void pwm_generator_run(void);

#endif