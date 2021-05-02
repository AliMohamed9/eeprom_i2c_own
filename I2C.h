/*
 * I2C.h
 *
 *  Created on: Apr 30, 2021
 *      Author: MeGa
 */

#ifndef I2C_H_
#define I2C_H_


extern void TWI_Init(void);
extern void TWI_Start(void);
extern void TWI_Sendbyte(unsigned char  D_byte);
extern char  TWI_ReceiveData_ACK(void);
extern char  TWI_ReceiveData_NACK(void);
extern void TWI_Stop(void);

#endif /* I2C_H_ */
