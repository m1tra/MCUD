#include <stdint.h>

void i2c_scanner(void)
{
    uint8_t ack = 0;
    uint8_t i2c_devices_counter = 0;
    uint8_t addresses[128];
    oled_set_text_cursor(0, 2);
    oled_write_string("SCANNING...", 11);
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
    oled_write_string("FOUNDED_DEVICES:", 20);

    char buffer[3];

    utoa(i2c_devices_counter, buffer, 10);
    oled_set_text_cursor(0, 3);
    oled_write_string(buffer, strlen(buffer));

    for (uint8_t i = 0; i < i2c_devices_counter; i++)
    {
        oled_set_text_cursor(0, 5 + i);

        char buffer[5] = "0x";

        utoa(addresses[i], buffer + 2, 16);

        oled_write_string(buffer, strlen(buffer));
    }
}