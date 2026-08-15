#include "oled.h"
#include "menu.h"
#include <stdint.h>
#include <string.h>

const char *menu[] = {
    "I2C Scanner",
    "ADC Monitor",
    "PWM Generator",
    "GPIO Tester",
    "UART Terminal",
    "Servo Tester",
    "Sensor Info"
};

#define MENU_SIZE 7

void menu_init(void)
{
    for (uint8_t i = 0; i < MENU_SIZE; i++)
    {
        oled_set_text_cursor(0, i);

        const char *position_of_menu = menu[i];

        oled_write_string(
            position_of_menu,
            strlen(position_of_menu)
        );
    }
}