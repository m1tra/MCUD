#ifndef UI_H
#define UI_H

#include <stdint.h>
#include "../src/menu/menu.h"

typedef enum
{
    SCREEN_MAIN_MENU,
    SCREEN_I2C_SCANNER,
    SCREEN_PWM_GENERATOR,
    SCREEN_ADC_MONITOR,
    SCREEN_GPIO_TESTER,
    SCREEN_UART_TERMINAL,
    SCREEN_SERVO_TESTER,
    SCREEN_SENSOR_INFO
} Screen;


void ui_set_screen(Screen screen);
Screen ui_get_screen(void);
void ui_handle_y(uint16_t y);

#endif