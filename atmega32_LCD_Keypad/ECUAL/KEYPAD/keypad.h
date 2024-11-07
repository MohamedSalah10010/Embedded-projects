/*
 * keypad.h
 *
 * Created: 4/24/2023 3:37:28 AM
 *  Author: TEAM 6
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../../MCAL/DIO/DIO_INTERFACE.h"



/*KEYPAD NUMBER OF ROWS AND COLUMNS CONFIGURATIONS*/
#define N_col 4
#define N_row 4

/* KEYPAD PORT CONFIGURATION */
#define  PORT			PORTD
#define KEYPAD_PORT_OUT PORTD_REG
#define KEYPAD_PORT_IN  PIND_REG
#define KEYPAD_PORT_DIR DDRD_REG

/* getting the pressed keypad key */
uint8_t KeyPad_getPressedKey(void);
uint8_t KeyPad_4x4_adjustKeyNumber(uint8_t button_number);
#endif /* KEYPAD_H_ */



