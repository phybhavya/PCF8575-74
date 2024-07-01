#ifndef __PCF8575_H__
#define __PCF8575_H__
#include "stm32f4xx_hal.h"
void PCF8575_Init(uint8_t addr_t, uint16_t timeout_t);
void PCF8575_write(I2C_HandleTypeDef *hi2c, uint8_t write[2]);
int PCF8575_read(I2C_HandleTypeDef *hi2c);
void PCF8575_Setpin();
#endif
