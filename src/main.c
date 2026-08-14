#include <avr/io.h>
#include <util/delay.h>

#include <avr/interrupt.h>

#include "i2c.h"
#include "oled.h"

int main()
{

    i2c_init();
    oled_init();

    uint8_t test[1024];

    for (uint16_t i = 0; i < 1024; i++)
    {
        test[i] = 0xFF;
    }

    oled_send_data(test, 1024);

    while (1)
    {
        
    }
}
