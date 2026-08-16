#ifndef I2C_H
#define I2C_H

#include <stdint.h>

void i2c_init(void);
void i2c_start(void);
void i2c_write(uint8_t data);
uint8_t i2c_ping(uint8_t address);
void i2c_stop(void);

#endif
