#include "menus.h"
#include "utils.h"
#include <stdint.h>
#include <avr/io.h>

static void pin_action(void)
{
    // typedef enum
    // {
    //     PH3,
    //     PH4,
    //     PH5
    // } Pins; // 4 timer

  
    
}

static void freq_action(void)
{
}

static void duty_action(void)
{
}

static const Command pwm_menu_items[] = {
    {"Pin:", pin_action},
    {"Freq:", freq_action},
    {"Duty:", duty_action},
};

Menu pwm_menu = {
    .items = pwm_menu_items,
    .size = ARRAY_LENGTH(pwm_menu_items),
    .pointer = 0,
    .start_pos = 2};