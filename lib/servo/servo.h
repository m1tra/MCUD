#ifndef SERVO_H
#define SERCO_H

#include <stdint.h>
#include <avr/io.h>
#include <gpio.h>

typedef struct
{
    GPIO_pin *pin;
    uint8_t angle;
    uint16_t pulse;
    uint32_t freq;
} Servo_settings;

void servo_init(Servo_settings servo_settings);

#endif
