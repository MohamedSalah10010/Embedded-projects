/*
 * KEYPAD_INTERFACE.h
 *
 * Created: 4/23/2023 12:16:23 AM
 *  Author: Mohamed Salah
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "../../MCAL/DIO/DIO_INTERFACE.h"

#define port PORTD

uint8_t KEYPAD_getChar(uint8_t * Key);


#endif /* KEYPAD_INTERFACE_H_ */