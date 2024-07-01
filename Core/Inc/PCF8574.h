#ifndef __PCF8574_H__
#define __PCF8574_H__
#include "stm32f4xx_hal.h"
typedef struct
{
    uint8_t write_addr;
    uint8_t read_addr;
}PCF8574_Slave;

void PCF8574_Init(uint16_t timeout_t);
void PCF8574_write(I2C_HandleTypeDef *hi2c, uint8_t write[1],uint8_t i);
int PCF8574_read(I2C_HandleTypeDef *hi2c, uint8_t i);
void PCF8574_Setpin();
#endif
