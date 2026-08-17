#include <stdint.h>
#include "gpio.h"

void gpio_output(GPIO_pin *pin){
    *(pin->ddr) |= (1 << pin->bit);
}