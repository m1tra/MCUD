#include <avr/io.h>
#include <util/delay.h>

#include <avr/interrupt.h>

#include "i2c.h"
#include "oled.h"
#include "utils.h"


int main()
{

    i2c_init();
    oled_init();
    oled_clear();
    oled_set_text_cursor(0,0);
    oled_write_string("HELLO WORLD", 11);
    oled_set_text_cursor(0,1);
    oled_write_string("HELLO WORLD", 11);
    oled_set_text_cursor(0,2);
    oled_write_string("HELLO WORLD", 11);
    oled_set_text_cursor(0,3);
    oled_write_string("HELLO WORLD", 11);
    oled_set_text_cursor(0,4);
    oled_write_string("HELLO WORLD", 11);
    oled_set_text_cursor(0,5);
    oled_write_string("HELLO WORLD", 11);
    oled_set_text_cursor(0,6);
    oled_write_string("HELLO WORLD", 11);
    oled_set_text_cursor(0,7);
    oled_write_string("HELLO WORLD", 11);

    while (1)
    {
        
    }
}
