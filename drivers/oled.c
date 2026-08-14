#include "oled.h"
#include "i2c.h"

void oled_on(void)
{
    i2c_start();
    oled_send_command(0xAF);
    i2c_stop();
}
void oled_off(void)
{
    i2c_start();
    oled_send_command(0xAE);
    i2c_stop();
}
void oled_send_сommand(const uint8_t *data, uint16_t length)
{
    i2c_start();

    i2c_write(OLED_ADDRESS << 1);
    i2c_write(0x0);

    for (int i = 0; i < length; i++){
        i2c_write(*(data+i));
    }
    
    i2c_stop();
}

void oled_send_data(const uint8_t *data, uint16_t length)
{
    i2c_start();

    i2c_write(OLED_ADDRESS << 1);
    i2c_write(0x40);

    for (int i = 0; i < length; i++){
        i2c_write(*(data+i));
    }
    
    i2c_stop();
}