#include "PCF8575.h"
#include "stm32f4xx_hal.h"

uint8_t read_addr;
uint8_t write_addr;
uint16_t timeout;
uint8_t data[2];
void PCF8575_Init(uint8_t addr_t, uint16_t timeout_t){
    read_addr = addr_t|0x01;
    write_addr = addr_t;
    timeout = timeout_t;//add a default time
}
void PCF8575_write(I2C_HandleTypeDef *hi2c, uint8_t write[2]){
    HAL_I2C_Master_Transmit(hi2c,write_addr,write,2,timeout);
}
int PCF8575_read(I2C_HandleTypeDef *hi2c){
    HAL_I2C_Master_Receive(hi2c,read_addr,data,2,timeout);   
    uint16_t rec_data; 
    rec_data = (data[0]<<8|data[1]);
    return rec_data;
}
void PCF8575_Setpin(){
    uint16_t bt;
}