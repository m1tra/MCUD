#ifndef MENU_H
#define MENU_H

#include <stdint.h>

typedef void (*CommandHandler)(void);

typedef struct
{
    const char *name;
    CommandHandler execute;
} Command;

typedef struct
{
    const Command *items;
    uint8_t size;
    uint8_t pointer;
    uint8_t start_pos;
} Menu;

void menu_init(Menu *menu);

void menu_pointer_scroll_down(
    uint16_t y_value,
    Menu *menu);

void menu_pointer_scroll_up(
    uint16_t y_value,
    Menu *menu);

void menu_choose_by_pointer(
    uint16_t x_value,
    Menu *menu);

void menu_close(
    uint16_t x_value,
    Menu *menu);

#endif