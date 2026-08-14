#ifndef OLED_H
#define OLED_H
#define OLED_ADDRESS 0x3C

#include <stdint.h>

void oled_init(void);
void oled_send_command(const uint8_t *command, uint16_t length);
void oled_send_data(const uint8_t *data, uint16_t length);

#endif
