#ifndef OLED_H
#define OLED_H
#define OLED_ADDRESS 0x3C
#define OLED_CMD_DISPLAY_OFF       0xAE
#define OLED_CMD_DISPLAY_ON        0xAF

#define OLED_CMD_CHARGE_PUMP       0x8D
#define OLED_CHARGE_PUMP_ON        0x14

#define OLED_CMD_MEMORY_MODE       0x20
#define OLED_MEMORY_HORIZONTAL     0x00
#define OLED_MEMORY_VERTICAL       0x01
#define OLED_MEMORY_PAGE           0x02

#define OLED_CMD_COLUMN_ADDRESS    0x21
#define OLED_CMD_PAGE_ADDRESS      0x22

#define TEXT_SIZE 6

#define OLED_X 128
#define OLED_Y 8
#define OLED_SIZE OLED_X * OLED_Y

#include <stdint.h>


void oled_init(void);
void oled_send_command(const uint8_t *command, uint16_t length);
void oled_send_data(const uint8_t *data, uint16_t length);
void oled_set_text_cursor(uint8_t col, uint8_t row);
void oled_write_char(char sym);
void oled_write_string(const char *str, uint8_t length);
void oled_clear(void);
void oled_set_pointer_cursor(uint8_t page);

#endif
