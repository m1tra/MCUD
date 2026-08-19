#include <avr/io.h>
#include <stdint.h>

#include "gpio.h"
#include "pwm.h"
#include "utils.h"
#include "../../src/tools/pwm_generator.h"

static void set_prescaler(uint16_t prescaler)
{
    TCCR4B &= ~(
        (1 << CS42) |
        (1 << CS41) |
        (1 << CS40));

    switch (prescaler)
    {
    case 1:
        TCCR4B |= (1 << CS40);
        break;

    case 8:
        TCCR4B |= (1 << CS41);
        break;

    case 64:
        TCCR4B |=
            (1 << CS41) |
            (1 << CS40);
        break;

    case 256:
        TCCR4B |= (1 << CS42);
        break;

    case 1024:
        TCCR4B |=
            (1 << CS42) |
            (1 << CS40);
        break;
    }
}

static void set_pin_reg(GPIO_pin *pin)
{
    if (pin == &PH3_pin) // OC4A
    {
        TCCR4A |= (1 << COM4A1);
    }
    else if (pin == &PH4_pin) // OC4B
    {
        TCCR4A |= (1 << COM4B1);
    }
    else if (pin == &PH5_pin) // OC4C
    {
        TCCR4A |= (1 << COM4C1);
    }
}

static void set_duty(GPIO_pin *pin, uint16_t value)
{
    if (pin == &PH3_pin)
    {
        OCR4A = value;
    }
    else if (pin == &PH4_pin)
    {
        OCR4B = value;
    }
    else if (pin == &PH5_pin)
    {
        OCR4C = value;
    }
}

void pwm_init(Settings pwm_settings)
{
    /*
        Timer4
        Fast PWM
        Mode 14

        WGM43 = 1
        WGM42 = 1
        WGM41 = 1
        WGM40 = 0

        TOP = ICR4
    */
    if (pwm_settings.freq == 0)
    {
        return;
    }

    if (pwm_settings.duty > 100)
    {
        pwm_settings.duty = 100;
    }
    TCCR4A = (1 << WGM41);

    TCCR4B =
        (1 << WGM43) |
        (1 << WGM42);
    gpio_output(pwm_settings.pin);

    const uint16_t prescaler_values[] = {
        1,
        8,
        64,
        256,
        1024};

    uint16_t current_prescaler = 0;
    uint32_t top = 0;

    for (uint8_t i = 0;
         i < ARRAY_LENGTH(prescaler_values);
         i++)
    {
        uint32_t prescaler = prescaler_values[i];

        uint32_t timer_ticks =
            F_CPU /
            (prescaler * pwm_settings.freq);

        if (timer_ticks >= 1 &&
            timer_ticks <= 65536UL)
        {
            top = timer_ticks - 1;

            current_prescaler =
                prescaler_values[i];

            break;
        }
    }

    if (current_prescaler == 0)
    {
        return;
    }

    ICR4 = (uint16_t)top;

    set_pin_reg(pwm_settings.pin);

    uint16_t compare;

    if (pwm_settings.duty == 0)
    {
        compare = 0;
    }
    else if (pwm_settings.duty >= 100)
    {
        compare = (uint16_t)top;
    }
    else
    {
        compare =
            ((uint32_t)(top + 1) *
             pwm_settings.duty) /
            100;
    }

    set_duty(
        pwm_settings.pin,
        compare);

    set_prescaler(current_prescaler);
}