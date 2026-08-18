#include "menus.h"
#include "utils.h"
#include "gpio.h"
#include "../src/tools/index.h"
#include <stdint.h>
#include <avr/io.h>



static const Command pwm_menu_items[] = {
    {"Pin:", pin_action, draw_pin},
    {"Freq:", freq_action, draw_freq},
    {"Duty:", duty_action, draw_duty},
    {"Confirm", confirm_action, NULL},
};

Menu pwm_menu = {
    .items = pwm_menu_items,
    .size = ARRAY_LENGTH(pwm_menu_items),
    .pointer = 0,
    .start_pos = 2};