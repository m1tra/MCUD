#include "menus.h"
#include "../tools/index.h"
#include "utils.h"

static const Command main_menu_items[] = {
    {"I2C Scanner",   i2c_scanner_run},
    {"ADC Monitor",   i2c_scanner_run},
    {"PWM Generator", pwm_generator_run},
    {"GPIO Tester",   i2c_scanner_run},
    {"UART Terminal", i2c_scanner_run},
    {"Servo Tester",  i2c_scanner_run},
    {"Sensor Info",   i2c_scanner_run},
};

Menu main_menu = {
    .items = main_menu_items,
    .size = ARRAY_LENGTH(main_menu_items),
    .pointer = 0,
    .start_pos = 0
};