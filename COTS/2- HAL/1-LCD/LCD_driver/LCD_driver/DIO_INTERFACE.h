/*
 * DIO_INTERFACE.h
 *
 * Created: 11/20/2021 12:36:51 AM
 *  Author: Mohamed Salah
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*AVR PORTS*/

#define PORTA	0
#define PORTB	1
#define PORTC	2
#define PORTD	3

#define A	PORTA 
#define B	PORTB 
#define C	PORTC 
#define	D	PORTD 

#define a	PORTA	
#define b	PORTB	
#define c	PORTC	
#define d	PORTD	

/* AVR PIN number*/

#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7


/* AVR_INPUT_OUTPUT  */

#define INPUT 0
#define OUTPUT 1
#define HIGH 1
#define LOW 0
#define Connect  1
#define NotConnected 0

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
