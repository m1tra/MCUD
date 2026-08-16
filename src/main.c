#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "i2c.h"
#include "oled.h"
#include "adc.h"
#include "utils.h"

#include "../src/menu/menu.h"
#include "../src/tools/index.h"
#include "../src/ui/ui.h"
#include "../src/menus/menus.h"

int main(void)
{
    uint16_t y_value = MIDDLE_VALUE;
    uint16_t x_value = MIDDLE_VALUE;

    i2c_init();
    oled_init();
    adc_init();

    menu_init(&main_menu);

    sei();

    adc_start(X_CHANNEL);

    while (1)
    {
        if (adc_is_y_ready())
        {
            y_value = adc_get_y_value();
            ui_handle_y(y_value);
        }

        if (adc_is_x_ready())
        {
            x_value = adc_get_x_value();

            ui_handle_x(x_value);
        }
    }
}