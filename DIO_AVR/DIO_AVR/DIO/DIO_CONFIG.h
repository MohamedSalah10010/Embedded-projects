/*
 * DIO_CONFIG.h
 *
 * Created: 13/09/2022 11:00:54 PM
 *  Author: Mohamed Salah
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

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
#define u8_Direction_input		0x00
#define u8_PinValue_LOW			0x00



#define Init_direction_default  u8_Direction_input

#define Init_PinValue_default  u8_PinValue_LOW


#endif /* DIO_CONFIG_H_ */