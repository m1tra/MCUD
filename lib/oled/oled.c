#include "oled.h"
#include "i2c.h"
#include "utils.h"
#include "font5x8.h"

void oled_init(void)
{
    uint8_t instructions[] = {
        OLED_CMD_DISPLAY_OFF,

        OLED_CMD_CHARGE_PUMP,
        OLED_CHARGE_PUMP_ON,

        OLED_CMD_MEMORY_MODE,
        OLED_MEMORY_HORIZONTAL,

        OLED_CMD_DISPLAY_ON};
    oled_send_command(instructions, ARRAY_LENGTH(instructions));
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

static void oled_set_cursor(uint8_t column, uint8_t page)
{
    uint8_t instructions[] = {
        OLED_CMD_COLUMN_ADDRESS, column, 127,
        OLED_CMD_PAGE_ADDRESS, page, 7};

    oled_send_command(instructions, ARRAY_LENGTH(instructions));
}

void oled_set_text_cursor(uint8_t col, uint8_t row)
{
    oled_set_cursor(col * TEXT_SIZE, row);
}

void oled_write_string(const char *str, uint8_t length)
{
    for (int i = 0; i < length; i++)
    {
        oled_write_char(*(str + i));
    }
}

void oled_write_char(char sym)
{
    oled_send_data(font[sym - 0x20], 6);
}

void oled_clear()
{
    oled_set_cursor(0,0);
    i2c_start();

    i2c_write(OLED_ADDRESS << 1);
    i2c_write(0x40);

    for (int i = 0; i < OLED_SIZE; i++)
    {
        i2c_write(0x0);
    }

    i2c_stop();
}