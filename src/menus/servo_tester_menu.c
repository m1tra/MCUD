#include "menus.h"
#include "utils.h"
#include "gpio.h"
#include "../src/tools/index.h"
#include <stdint.h>
#include <avr/io.h>

static const Command servo_tester_items[] = {
    {"Pin:", servo_pin_action, servo_draw_pin},
    {"Angle:", servo_angle_action, servo_draw_angle},
    {"Pulse:", servo_pulse_action, servo_draw_pulse},
    {"Freq", servo_freq_action, servo_draw_freq},
    {"Confirm", servo_confirm_action, NULL}
};

Menu servo_tester_menu = {
    .items = servo_tester_items,
    .size = ARRAY_LENGTH(servo_tester_items),
    .pointer = 0,
    .start_pos = 2
};