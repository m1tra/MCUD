#include <stdint.h>
#include "oled.h"
#include "i2c.h"
#include <stdlib.h>

void i2c_scanner(void)
{
    uint8_t ack = 0;
    uint8_t i2c_devices_counter = 0;
    uint8_t addresses[128];
    for (uint8_t i = 0x0; i < 0x7C; i++)
    {
        i2c_start();
        ack = i2c_ping(i);
        i2c_stop();
        if (ack == 1)
        {
            addresses[i2c_devices_counter] = i;
            i2c_devices_counter++;
        }
        ack = 0;
    }
    oled_set_text_cursor(0, 2);

    char buffer[12] = "Devices: ";

    utoa(i2c_devices_counter, buffer + 9, 10);
    oled_write_string(buffer, strlen(buffer));

    oled_set_text_cursor(0, 4);
    oled_write_string("Found:", strlen("Found:"));

    for (uint8_t i = 0; i < i2c_devices_counter; i++)
    {
        oled_set_text_cursor(0, 5 + i);

        char new_buffer[5] = "0x";

        utoa(addresses[i], new_buffer + 2, 16);

        oled_write_string(new_buffer, strlen(new_buffer));
    }
}