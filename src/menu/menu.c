#include "oled.h"
#include "menu.h"
#include "adc.h"
#include "i2c.h"
#include "utils.h"
#include "../tools/i2c_scanner.h"
#include <stdint.h>
#include <string.h>
#include <util/delay.h>
#include <stdlib.h>

static uint8_t is_command_execute = 0;

static void scanner_header(const char *name)
{
    is_command_execute = 1;
    oled_clear();
    oled_write_string(name, strlen(name));
}

static void i2c_scanner_run(void)
{
    scanner_header("I2C Scanner");
    i2c_scanner();
}

static void adc_monitor_run(void)
{
    is_command_execute = 1;
    oled_clear();
    oled_write_string("ADC Monitor", 11);
}

static void pwm_generator_run(void)
{
    is_command_execute = 1;
    oled_clear();
    oled_write_string("PWM Generator", 13);
}

static void gpio_tester_run(void)
{
    is_command_execute = 1;
    oled_clear();
    oled_write_string("GPIO Tester", 11);
}

static void uart_terminal_run(void)
{
    is_command_execute = 1;
    oled_clear();
    oled_write_string("UART Terminal", 13);
}

static void servo_tester_run(void)
{
    is_command_execute = 1;
    oled_clear();
    oled_write_string("Servo Tester", 12);
}

static void sensor_info_run(void)
{
    is_command_execute = 1;
    oled_clear();
    oled_write_string("Sensor Info", 11);
}

const Command menu[] = {
    {"I2C Scanner", i2c_scanner_run},
    {"ADC Monitor", adc_monitor_run},
    {"PWM Generator", pwm_generator_run},
    {"GPIO Tester", gpio_tester_run},
    {"UART Terminal", uart_terminal_run},
    {"Servo Tester", servo_tester_run},
    {"Sensor Info", sensor_info_run},
};

void menu_init(uint8_t pointer)
{
    oled_set_pointer_cursor(pointer);
    oled_write_string(">", 1);
    for (uint8_t i = 0; i < MENU_SIZE; i++)
    {
        oled_set_text_cursor(1, i);

        const char *position_of_menu = menu[i].name;

        oled_write_string(
            position_of_menu,
            strlen(position_of_menu));
    }
}

uint8_t menu_pointer_scroll_down(uint16_t y_value, uint8_t pointer)
{
    if (is_command_execute)
    {
        return pointer;
    }
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
    if (is_command_execute)
    {
        return pointer;
    }
    while (y_value < MIDDLE_VALUE - PADDING)
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

void menu_choose_by_pointer(uint16_t x_value, uint8_t pointer)
{
    if (x_value > MIDDLE_VALUE + PADDING & is_command_execute == 0)
    {
        menu[pointer].execute();
    }
}

void menu_close(uint16_t x_value, uint8_t pointer)
{
    if (x_value < MIDDLE_VALUE - PADDING & is_command_execute == 1)
    {
        is_command_execute = 0;
        oled_clear();
        menu_init(pointer);
    }
}