/*
 * DIO_INTERFACE.h
 *
 * Created: 13/9/2022 8:36:51 PM
 *  Author: Mohamed Salah
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_



/*	FUNCTIONS	*/

void DIO_voidInit         (void);
//******************************************* PORT **********************************

	u8 DIO_set_PORT_DIR(u8 portnum, u8 dir);

	u8 DIO_read_PORT(u8 portnum);

	u8 DIO_write_PORT(u8 portnum,u8 value);

	u8 DIO_toggle_PORT(u8 portnum);

//******************************************** PIN **********************************

	u8 DIO_setPIN_DIR(u8 portnum, u8 pinnum, u8 dir);

	u8 DIO_read_PIN(u8 portnum,u8 pinnum);

	u8 DIO_write_PIN(u8 portnum,u8 pinnum,u8 value);

	u8 DIO_toggle_PIN(u8 portnum,u8 pinnum);




#endif /* DIO_INTERFACE_H_ */
