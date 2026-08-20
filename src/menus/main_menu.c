#include "menus.h"
#include "../menu/menu.h"
#include "../tools/index.h"
#include "utils.h"

static const Command main_menu_items[] = {
    {"I2C Scanner",   i2c_scanner_run, NULL},
    {"ADC Monitor",   i2c_scanner_run, NULL},
    {"PWM Generator", pwm_generator_run, NULL},
    {"GPIO Tester",   i2c_scanner_run, NULL},
    {"UART Terminal", i2c_scanner_run, NULL},
    {"Servo Tester",  servo_tester_run, NULL},
    {"Sensor Info",   i2c_scanner_run, NULL},
};

Menu main_menu = {
    .items = main_menu_items,
    .size = ARRAY_LENGTH(main_menu_items),
    .pointer = 0,
    .start_pos = 0
};