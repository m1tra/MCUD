#ifndef OLED_H
#define OLED_H

#include <stdint.h>

void oled_on(void);
void oled_off(void);
void oled_send_command(uint8_t command);
void oled_send_data(uint8_t data);

#endif
