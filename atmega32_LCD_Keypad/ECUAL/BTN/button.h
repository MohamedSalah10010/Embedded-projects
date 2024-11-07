/*
 * button.h
 *
 * Created: 22-Nov-22 6:51:08 AM
 *  Author: Mahmoud
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


// Driver Inclusions

#include "../../MCAL/DIO/DIO_INTERFACE.h"



// Driver Macros

#define BTN_1_PORT			PORTB_REG
#define BTN_2_PORT			PORTB_REG
#define BTN_3_PORT			PORTB_REG
#define BTN_4_PORT			PORTB_REG

#define BTN_1_PIN			PIN4
#define BTN_2_PIN			PIN2
#define BTN_3_PIN			PIN3
#define BTN_4_PIN			PIN4

#define BTN_1				1
#define BTN_2				2
#define BTN_3				3
#define BTN_4				4


#define BTN_PRESSED				HIGH
#define BTN_NOT_PRESSED			LOW


// Driver Functions Prototypes

void BTN_init  (uint8_t btnNum);
uint8_t   BTN_read  (uint8_t btnNum);


#endif /* BUTTON_H_ */
