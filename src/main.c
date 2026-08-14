#include <avr/io.h>
#include <util/delay.h>

#include <avr/interrupt.h>

#include "i2c.h"
#include "oled.h"


int main()
{

    i2c_init();
    
    while (1)
    {
    }
}
