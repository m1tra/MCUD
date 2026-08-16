#include "i2c.h"
#include <avr/io.h>

static void spinLoop()
{
    while (!(TWCR & (1 << TWINT)))
        ;
}

void i2c_init(void)
{
    TWSR = 0;
    TWBR = 72; // ~100 kHz

    TWCR = (1 << TWEN);
}

void i2c_start(void)
{
    TWCR =
        (1 << TWINT) |
        (1 << TWSTA) |
        (1 << TWEN);

    spinLoop();
}

uint8_t i2c_ping(uint8_t address)
{
    TWDR = address << 1;

    TWCR =
        (1 << TWINT) |
        (1 << TWEN) |
        (1 << TWEA);

    spinLoop();

    uint8_t status = TWSR & 0xF8;
    
    if (status == 0x18) {
        return 1;
    }
    else {
        return 0;
    }
}


void i2c_write(uint8_t data)
{
    TWDR = data;

    TWCR =
        (1 << TWINT) |
        (1 << TWEN);

    spinLoop();
}
void i2c_stop(void)
{
    TWCR =
        (1 << TWSTO) |
        (1 << TWEN) |
        (1 << TWINT);
}
