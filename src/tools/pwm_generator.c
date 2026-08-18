#include <avr/io.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>

#include "../src/menu/menu.h"
#include "../src/menus/menus.h"

#include "utils.h"
#include "GPIO.h"
#include "oled.h"

GPIO_pin PH3_pin = {
    &DDRH,
    &PORTH,
    &PINH,
    PH3,
    "PH3"
};

GPIO_pin PH4_pin = {
    &DDRH,
    &PORTH,
    &PINH,
    PH4,
    "PH4"
};

GPIO_pin PH5_pin = {
    &DDRH,
    &PORTH,
    &PINH,
    PH5,
    "PH5"
};

GPIO_pin *pwm_pins[] = {
    &PH3_pin,
    &PH4_pin,
    &PH5_pin
};

uint32_t pwm_frequencies[] = {
    50,
    100,
    500,
    1000,
    5000,
    10000,
    20000,
    50000
};

const uint8_t duty_step = 10;

uint8_t pwm_pin_pointer = 0;
uint8_t pwm_freq_pointer = 0;
uint8_t pwm_duty = 10;

typedef struct
{
    GPIO_pin *pin;
    uint32_t freq;
    uint8_t duty;
} Settings;

Settings pwm_setting;

static void pwm_settings_init(void)
{
    pwm_setting.pin = pwm_pins[pwm_pin_pointer];
    pwm_setting.freq = pwm_frequencies[pwm_freq_pointer];
    pwm_setting.duty = pwm_duty;
}

void draw_pin(void)
{
    const char *name = pwm_setting.pin->name;

    oled_set_text_cursor(7, 2);
    oled_write_string(name, strlen(name));
}

void draw_freq(void)
{
    char buffer[12];

    ultoa(pwm_setting.freq, buffer, 10);

    oled_set_text_cursor(7, 3);
    oled_write_string(buffer, strlen(buffer));
    oled_write_string(" Hz", 3);
}

void draw_duty(void)
{
    char buffer[4];

    utoa(pwm_setting.duty, buffer, 10);

    oled_set_text_cursor(7, 4);
    oled_write_string(buffer, strlen(buffer));
    oled_write_string("%", 1);
}

void pin_action(void)
{
    pwm_pin_pointer++;

    if (pwm_pin_pointer >= ARRAY_LENGTH(pwm_pins))
    {
        pwm_pin_pointer = 0;
    }

    pwm_setting.pin = pwm_pins[pwm_pin_pointer];

    draw_pin();
}

void freq_action(void)
{
    pwm_freq_pointer++;

    if (pwm_freq_pointer >= ARRAY_LENGTH(pwm_frequencies))
    {
        pwm_freq_pointer = 0;
    }

    pwm_setting.freq = pwm_frequencies[pwm_freq_pointer];

    draw_freq();

    
}

void duty_action(void)
{
    if (pwm_duty >= 100)
    {
        pwm_duty = duty_step;
    }
    else
    {
        pwm_duty += duty_step;
    }

    pwm_setting.duty = pwm_duty;

    draw_duty();

}

void confirm_action(void)
{

}

void pwm_generator(void)
{
    pwm_settings_init();
    menu_init(&pwm_menu);
}