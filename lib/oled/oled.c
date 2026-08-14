#include "oled.h"
#include "i2c.h"

// for ssd1315
//  0x00 → Horizontal Addressing Mode
//  0x01 → Vertical Addressing Mode
//  0x02 → Page Addressing Mode
void oled_init(void)
{

    uint8_t instructions[] = {
        0xAE, // Display OFF

        0x8D, 0x14, // Charge Pump ON

        0x20, 0x00, // Set Memory Addressing Mode Horizontal Addressing Mode

        0xAF // Display ON
    };
    oled_send_command(instructions, 6);
}

void oled_send_command(const uint8_t *data, uint16_t length)
{
    i2c_start();

    i2c_write(OLED_ADDRESS << 1);
    i2c_write(0x0);

    for (int i = 0; i < length; i++)
    {
        i2c_write(*(data + i));
    }

    i2c_stop();
}

void oled_send_data(const uint8_t *data, uint16_t length)
{
    i2c_start();

    i2c_write(OLED_ADDRESS << 1);
    i2c_write(0x40);

    for (int i = 0; i < length; i++)
    {
        i2c_write(*(data + i));
    }

    i2c_stop();
}