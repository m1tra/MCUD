#include <avr/io.h>
#include <util/delay.h>

#include <avr/interrupt.h>

#include "i2c.h"
#include "oled.h"
#include "adc.h"
#include "utils.h"
#include "../src/menu/menu.h"

int main()
{

    uint8_t pointer = 0;

    i2c_init();
    oled_init();
    menu_init(pointer);
    adc_init();
    sei();
    adc_start(X_CHANNEL);
    uint16_t y_value = MIDDLE_VALUE;
    uint16_t x_value = MIDDLE_VALUE;

    while (1)
    {
        if (adc_is_y_ready())
        {
            y_value = adc_get_y_value();

            pointer = menu_pointer_scroll_down(y_value, pointer);
            pointer = menu_pointer_scroll_up(y_value, pointer);
        }
        if (adc_is_x_ready()){
            x_value = adc_get_x_value();
            
            menu_choose_by_pointer(x_value, pointer);
            menu_close(x_value, pointer);
            
        }
    }
}
