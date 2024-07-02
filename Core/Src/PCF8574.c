#include "PCF8574.h"
#include "stm32f4xx_hal.h"

uint8_t PCF8574_addr;
uint8_t PCF8574_addw;
uint16_t PCF8574_timeout;
uint8_t PCF8574_data[1];


PCF8574_Slave slave[8];
void PCF8574_Init(I2C_HandleTypeDef *hi2c,uint16_t timeout_t){
    PCF8574_timeout = timeout_t;//add a default time
    slave[0].read_addr= 0x41;
    slave[0].write_addr = 0x40;
    slave[1].read_addr= 0x43;
    slave[1].write_addr = 0x42;
    slave[2].read_addr= 0x45;
    slave[2].write_addr = 0x44;
    slave[3].read_addr= 0x47;
    slave[3].write_addr = 0x46;
    slave[4].read_addr= 0x49;
    slave[4].write_addr = 0x48;
    slave[5].read_addr= 0x4B;
    slave[5].write_addr = 0x4A;
    slave[6].read_addr= 0x4D;
    slave[6].write_addr = 0x4C;
    slave[7].read_addr= 0x4F;
    slave[7].write_addr = 0x4E;
    for (int i=0;i<8;i++){
        HAL_I2C_Master_Transmit(hi2c,slave[i].write_addr,0x00,1,PCF8574_timeout); 
    }
    }
void PCF8574_write(I2C_HandleTypeDef *hi2c, uint8_t write[1],uint8_t i){
    HAL_I2C_Master_Transmit(hi2c,slave[i].write_addr,write,1,PCF8574_timeout);
}
int PCF8574_read(I2C_HandleTypeDef *hi2c, uint8_t i){
    HAL_I2C_Master_Receive(hi2c,slave[i].read_addr,PCF8574_data,1,PCF8574_timeout);   
    return PCF8574_data[0];
}
void PCF8574_Reset(I2C_HandleTypeDef *hi2c,uint8_t i){
    HAL_I2C_Master_Transmit(hi2c,slave[i].write_addr,0x00,1,PCF8574_timeout);
}
