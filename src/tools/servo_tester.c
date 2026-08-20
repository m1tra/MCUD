#include "servo_tester.h"
#include "oled.h"
#include "../menu/menu.h"
#include "pwm.h"
#include "GPIO.h"
#include "utils.h"
#include <avr/io.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>
#include <menus/menus.h>
#include "servo.h"

GPIO_pin PE3_pin = {
    &DDRE,
    &PORTE,
    &PINE,
    PE3,
    "PE3"
};

GPIO_pin PE4_pin = {
    &DDRE,
    &PORTE,
    &PINE,
    PE4,
    "PE4"
};

GPIO_pin PE5_pin = {
    &DDRE,
    &PORTE,
    &PINE,
    PE5,
    "PE5"
};

GPIO_pin *servo_pins[] = {
    &PE3_pin,
    &PE4_pin,
    &PE5_pin
};

uint16_t servo_angles[] = {
    0,
    45,
    90,
    135,
    180
};

uint16_t servo_pulses[] = {
    500,
    1000,
    1500,
    2000,
    2500
};

uint16_t servo_frequencies[] = {
    50,
    100,
    200
};

uint8_t servo_pin_pointer = 0;
uint8_t servo_angle_pointer = 2;
uint8_t servo_pulse_pointer = 2;
uint8_t servo_freq_pointer = 0;

Servo_settings servo_settings;

static void servo_settings_init(void)
{
    servo_settings.pin = servo_pins[servo_pin_pointer];
    servo_settings.angle = servo_angles[servo_angle_pointer];
    servo_settings.pulse = servo_pulses[servo_pulse_pointer];
    servo_settings.freq = servo_frequencies[servo_freq_pointer];
}

void servo_draw_pin(void)
{
    const char *name = servo_settings.pin->name;
    oled_set_text_cursor(7, 2);
    oled_write_string(name, strlen(name));
}

void servo_draw_angle(void)
{
    char buffer[6];
    itoa(servo_angles[servo_angle_pointer], buffer, 10);
    oled_set_text_cursor(7, 3);
    oled_write_string(buffer, strlen(buffer));
    oled_write_string(" deg", 4);
}

void servo_draw_pulse(void)
{
    char buffer[6];
    itoa(servo_pulses[servo_pulse_pointer], buffer, 10);
    oled_set_text_cursor(7, 4);
    oled_write_string(buffer, strlen(buffer));
    oled_write_string(" us", 3);
}

void servo_draw_freq(void)
{
    char buffer[8];
    ultoa(servo_frequencies[servo_freq_pointer], buffer, 10);
    oled_set_text_cursor(7, 5);
    oled_write_string(buffer, strlen(buffer));
    oled_write_string(" Hz", 3);
}

void servo_pin_action(void)
{
    servo_pin_pointer++;
    if (servo_pin_pointer >= ARRAY_LENGTH(servo_pins)) {
        servo_pin_pointer = 0;
    }
    servo_settings.pin = servo_pins[servo_pin_pointer];
    servo_draw_pin();
}

void servo_angle_action(void)
{
    servo_angle_pointer++;
    if (servo_angle_pointer >= ARRAY_LENGTH(servo_angles)) {
        servo_angle_pointer = 0;
    }
    servo_draw_angle();
}

void servo_pulse_action(void)
{
    servo_pulse_pointer++;
    if (servo_pulse_pointer >= ARRAY_LENGTH(servo_pulses)) {
        servo_pulse_pointer = 0;
    }
    servo_draw_pulse();
}

void servo_freq_action(void)
{
    servo_freq_pointer++;
    if (servo_freq_pointer >= ARRAY_LENGTH(servo_frequencies)) {
        servo_freq_pointer = 0;
    }
    servo_draw_freq();
}

void servo_confirm_action(void)
{
    // Запуск сервы
}

void servo_tester(void)
{
    servo_settings_init();
    menu_init(&servo_tester_menu);
}