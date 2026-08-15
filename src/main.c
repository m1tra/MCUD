#include <avr/io.h>
#include <util/delay.h>

#include <avr/interrupt.h>

#include "i2c.h"
#include "oled.h"
#include "utils.h"
#include "../src/menu/menu.h"


int main()
{

    i2c_init();
    oled_init();
    menu_init();
  

    while (1)
    {
        
    }
}
