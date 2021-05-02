/*
 * eeprom_i2c_own.c
 *
 *  Created on: Apr 30, 2021
 *      Author: MeGa
 */

#include <eeprom_i2c_own.h>
#include <avr/io.h>
#include<util/delay.h>
extern void EEPROM24C16_Init (){
	TWI_Init();
}
void  _EEPROM24C16_i2c_Write_Byte(unsigned char  memory_location, unsigned char  slave_address, unsigned char  data){


	    TWI_Start();                         /* Send Start Bit 						 */
	    TWI_Sendbyte(slave_address);     /* Send Slave address with Write bit */
	    TWI_Sendbyte(memory_location);   /* Send Memory Location Address 			 */
	    TWI_Sendbyte(data);              /* Send Data					 */
	    TWI_Stop();
		_delay_ms(15);
}
char  EEPROM24C16_i2c_Read_Byte (unsigned char memory_location, unsigned char slave_address){
	unsigned char  data;


	    TWI_Start();                      /* Send Start Bit 						 */
	    TWI_Sendbyte(slave_address);       /* Send Slave address with  Write bit  */
	    TWI_Sendbyte(memory_location);       /* Send Memory Location Address 			 */

	    TWI_Start();                     /*  Restart Bit 						 */
	    TWI_Sendbyte(slave_address | 1);     /* Send Slave address with read bit  */
		data = TWI_ReceiveData_NACK();
		  TWI_Stop();

		return data;


}
