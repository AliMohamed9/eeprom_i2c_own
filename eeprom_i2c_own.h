/*
 * eeprom_i2c_own.h
 *
 *  Created on: Apr 30, 2021
 *      Author: MeGa
 */

#ifndef EEPROM_I2C_OWN_H_
#define EEPROM_I2C_OWN_H_
#include <avr/io.h>
#include<util/delay.h>
#include <I2C.h>

extern void EEPROM24C16_Init ();
extern void  EEPROM24C16_i2c_Write_Byte (unsigned char  memory_location, unsigned char  slave_address, unsigned char  data);
extern char  EEPROM24C16_i2c_Read_Byte (unsigned char memory_location, unsigned char slave_address);

#endif /* EEPROM_I2C_OWN_H_ */
