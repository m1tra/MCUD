#include <avr/io.h>
#include "../src/menu/menu.h"
#include "../src/menus/menus.h"
#include "utils.h"

uint8_t pins[] = {
    PH3,
    PH4,
    PH5
}; //4timer


void pwm_generator(void)
{
    menu_init(&pwm_menu);
}