/*
 * I2C.c
 *
 *  Created on: Apr 30, 2021
 *      Author: MeGa
 */

#include<I2C.h>
#include<avr/io.h>
#include<util/delay.h>

void TWI_Init(void)
{

//	TWCR = 0;
//	TWBR= TWBR_val;

TWSR=0x00;      // prescaler >>> FOSC/1
TWBR=0x47;             //50khz     //  CPU feq/(16+(2*twbr *2^twbr)
TWCR=0x04;        // for twi enable
}

void TWI_Start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); 	// clearing the interrupt flag by set it by 1 (must be done by software)     Send START condition bit and enable TWI
	while (!(TWCR & (1<<TWINT)) );   		/* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
	}

void TWI_Stop(void)
{
	TWCR =  (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);	  // must enable the twi interface and clear the interrupt flag  Transmit STOP condition bit
}

void TWI_Sendbyte(unsigned char  D_byte)
{
	TWDR = D_byte;   /* Put data On TWI data Register */
	TWCR = (1<<TWINT) |(1<<TWEN);	   //Load SLA_W into TWDR Register. Clear TWINT bit
	                                   //in TWCR to start transmission of data

	while (!(TWCR & (1<<TWINT)));   		/* Wait for TWINT flag set in TWCR Register (data is send successfully) */

	}


/*
char TWI_Read_data (unsigned char ACK){


		//  to start receiving Byte
		if(ACK)
		{
			TWCR = (1<< TWINT) | (1<< TWEN) | (ACK<< TWEA) ;
		}
		else
		{
			TWCR = (1<< TWINT) | (1<< TWEN) ;
		}
	//	 Polling until the byte is received completely
		while((TWCR & (1 << TWINT)) == 0);

		return TWDR;



}
*/

char  TWI_ReceiveData_ACK(void)
{

	/*
		 * Clear the TWINT flag before reading the data TWINT=1
		 * Enable sending ACK after reading or receiving data TWEA=1
		 * Enable TWI Module TWEN=1
		*/

	TWCR = (1<<TWEA)|(1<<TWINT)|(1<<TWEN);

	while (!(TWCR & (1<<TWINT)));		/* Wait for TWINT flag set in TWCR Register (data received successfully) */

	return TWDR;

}

char TWI_ReceiveData_NACK(void)
{

	TWCR = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR & (1<<TWINT)));   	 /* Wait for TWINT flag set in TWCR Register (data received successfully) */

	return TWDR;


}

