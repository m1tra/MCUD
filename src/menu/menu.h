#ifndef MENU_H
#define MENU_H

#include <stdint.h>

#define MENU_SIZE 7

typedef void (*CommandHandler)(void);

typedef struct
{
    const char *name;
    CommandHandler execute;
} Command;

extern const Command menu[];

void menu_init(uint8_t pointer);

uint8_t menu_pointer_scroll_down(
    uint16_t y_value,
    uint8_t pointer);

uint8_t menu_pointer_scroll_up(
    uint16_t y_value,
    uint8_t pointer);

void menu_choose_by_pointer(
    uint16_t x_value,
    uint8_t pointer);

void menu_close(uint16_t x_value, uint8_t pointer);

#endif