#ifndef MENU_H
#define MENU_H
#define MENU_SIZE 7

extern const char *menu[];

void menu_init(void);
uint8_t menu_pointer_scroll_down(uint16_t y_value, uint8_t pointer);
uint8_t menu_pointer_scroll_up(uint16_t y_value, uint8_t pointer);
#endif