#include "oled.h"
#include "menu.h"
#include "adc.h"
#include "i2c.h"
#include "utils.h"
#include "../tools/i2c_scanner.h"
#include "../tools/pwm_generator.h"
#include "../ui/ui.h"

#include <stdint.h>
#include <string.h>
#include <util/delay.h>
#include <stdlib.h>

static uint8_t is_command_execute = 0;

static void tool_open(const char *name)
{

    is_command_execute = 1;

    oled_clear();
    oled_write_string(name, strlen(name));
}

void i2c_scanner_run(void)
{
    ui_set_screen(SCREEN_I2C_SCANNER);
    tool_open("I2C Scanner");
    i2c_scanner();
}

void adc_monitor_run(void)
{
    ui_set_screen(SCREEN_ADC_MONITOR);
    tool_open("ADC Monitor");
}

void pwm_generator_run(void)
{
    ui_set_screen(SCREEN_PWM_GENERATOR);
    tool_open("PWM Generator");
    pwm_generator();
}

void gpio_tester_run(void)
{
    ui_set_screen(SCREEN_GPIO_TESTER);
    tool_open("GPIO Tester");
}

void uart_terminal_run(void)
{
    ui_set_screen(SCREEN_UART_TERMINAL);
    tool_open("UART Terminal");
}

void servo_tester_run(void)
{
    ui_set_screen(SCREEN_SERVO_TESTER);
    tool_open("Servo Tester");
}

void sensor_info_run(void)
{
    ui_set_screen(SCREEN_SENSOR_INFO);
    tool_open("Sensor Info");
}

void menu_init(Menu *menu)
{
    oled_set_pointer_cursor(menu->pointer + menu->start_pos);
    oled_write_string(">", 1);

    for (uint8_t i = 0; i < menu->size; i++)
    {
        oled_set_text_cursor(1, i + menu->start_pos);

        const char *position_of_menu = menu->items[i].name;

        oled_write_string(
            position_of_menu,
            strlen(position_of_menu));
    }
}

void menu_pointer_scroll_down(uint16_t y_value, Menu *menu)
{
    // if (is_command_execute)
    // {
    //     return;
    // }

    while (y_value > MIDDLE_VALUE + PADDING)
    {
        oled_set_pointer_cursor(menu->pointer + menu->start_pos);
        oled_write_string(" ", 1);

        menu->pointer++;

        if (menu->pointer >= menu->size)
        {
            menu->pointer = 0;
        }

        oled_set_pointer_cursor(menu->pointer + menu->start_pos);
        oled_write_string(">", 1);

        _delay_ms(250);

        if (adc_is_y_ready())
        {
            y_value = adc_get_y_value();
        }
    }
}

void menu_pointer_scroll_up(uint16_t y_value, Menu *menu)
{
    // if (is_command_execute)
    // {
    //     return;
    // }

    while (y_value < MIDDLE_VALUE - PADDING)
    {
        oled_set_pointer_cursor(menu->pointer + menu->start_pos);
        oled_write_string(" ", 1);

        if (menu->pointer == 0)
        {
            menu->pointer = menu->size - 1;
        }
        else
        {
            menu->pointer--;
        }

        oled_set_pointer_cursor(menu->pointer + menu->start_pos);
        oled_write_string(">", 1);

        _delay_ms(250);

        if (adc_is_y_ready())
        {
            y_value = adc_get_y_value();
        }
    }
}

void menu_choose_by_pointer(uint16_t x_value, Menu *menu)
{
    if (x_value > MIDDLE_VALUE + PADDING &&
        is_command_execute == 0)
    {
        menu->items[menu->pointer].execute();
    }
}

void menu_close(uint16_t x_value, Menu *menu)
{
    if (x_value < MIDDLE_VALUE - PADDING &&
        is_command_execute == 1)
    {
        is_command_execute = 0;
        ui_set_screen(SCREEN_MAIN_MENU);

        oled_clear();
        menu_init(menu);
    }
}