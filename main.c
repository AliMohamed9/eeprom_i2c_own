/*
 * main.c
 *
 *  Created on: May 1, 2021
 *      Author: MeGa
 */
#include <avr/io.h>
#include<util/delay.h>
#include <eeprom_i2c_own.h>

int main(){
 unsigned char data_out=0;

DDRD|=(1<<PD7)|(1<<PD6);
PORTD = 0x00;
	EEPROM24C16_Init ();

	_EEPROM24C16_i2c_Write_Byte( 0x00, 0xA2,0x0f);
	_delay_ms(10);

	data_out =EEPROM24C16_i2c_Read_Byte(0x00 , 0xA2);

	while(1){

		PORTD=data_out;
		_delay_ms(5000);
	}

}
