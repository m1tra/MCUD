#include "ui.h"
#include "../src/menu/menu.h"
#include "../src/menus/menus.h"
#include <stdint.h>

static Screen current_screen = SCREEN_MAIN_MENU;

static void enableScroll(uint16_t y, Menu *menu)
{
    menu_pointer_scroll_down(
        y,
        menu);

    menu_pointer_scroll_up(
        y,
        menu);
}

static void enableSelect(uint16_t x, Menu *menu)
{
    menu_choose_by_pointer(
        x,
        menu);

}
static void enableClose(uint16_t x, Menu *menu)
{
    menu_close(
        x,
        menu);

}

void ui_set_screen(Screen screen)
{
    current_screen = screen;
}

Screen ui_get_screen(void)
{
    return current_screen;
}

void ui_handle_y(uint16_t y)
{
    switch (current_screen)
    {
    case SCREEN_MAIN_MENU:
        enableScroll(y, &main_menu);
        break;
    case SCREEN_I2C_SCANNER:
        break;
    case SCREEN_PWM_GENERATOR:
        enableScroll(y, &pwm_menu);
        break;
    case SCREEN_SERVO_TESTER:
        enableScroll(y, &servo_tester_menu);
        break;
    }
}

void ui_handle_x(uint16_t x, Menu *menu)
{
    switch (current_screen)
    {
    case SCREEN_MAIN_MENU:
        enableSelect(x, &main_menu);
        break;
    case SCREEN_I2C_SCANNER:
        enableClose(x, &main_menu);
        break;
    case SCREEN_PWM_GENERATOR:
        enableSelect(x, &pwm_menu);
        enableClose(x, &main_menu);
        break;
    case SCREEN_SERVO_TESTER:
        enableSelect(x, &servo_tester_menu);
        enableClose(x, &main_menu);
        break;
    }
}