#include "oled.h"
#include "menu.h"
#include "adc.h"
#include <stdint.h>
#include <string.h>
#include <util/delay.h>

const char *menu[] = {
    "I2C Scanner",
    "ADC Monitor",
    "PWM Generator",
    "GPIO Tester",
    "UART Terminal",
    "Servo Tester",
    "Sensor Info"};

void menu_init(void)
{
    oled_set_pointer_cursor(0);
    oled_write_string(">", 1);
    for (uint8_t i = 0; i < MENU_SIZE; i++)
    {
        oled_set_text_cursor(1, i);

        const char *position_of_menu = menu[i];

        oled_write_string(
            position_of_menu,
            strlen(position_of_menu));
    }
}

uint8_t menu_pointer_scroll_down(uint16_t y_value, uint8_t pointer)
{
    while (y_value > MIDDLE_VALUE + PADDING)
    {
        oled_set_pointer_cursor(pointer);
        oled_write_string(" ", 1);

        pointer++;

        if (pointer >= MENU_SIZE)
        {
            pointer = 0;
        }

        oled_set_pointer_cursor(pointer);
        oled_write_string(">", 1);

        _delay_ms(250);

        if (adc_is_y_ready())
        {
            y_value = adc_get_y_value();
        }
    }
    return pointer;
}

uint8_t menu_pointer_scroll_up(uint16_t y_value, uint8_t pointer)
{
    while (y_value < MENU_SIZE - PADDING)
    {
        oled_set_pointer_cursor(pointer);
        oled_write_string(" ", 1);

        if (pointer == 0)
        {
            pointer = MENU_SIZE - 1;
        }
        else
        {
            pointer--;
        }

        oled_set_pointer_cursor(pointer);
        oled_write_string(">", 1);

        _delay_ms(250);

        if (adc_is_y_ready())
        {
            y_value = adc_get_y_value();
        }
    }
    return pointer;
}