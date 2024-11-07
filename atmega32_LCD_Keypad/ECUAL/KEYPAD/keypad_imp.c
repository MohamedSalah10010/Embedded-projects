/*
 * keypad_imp.c
 *
 * Created: 4/24/2023 3:37:17 AM
 *  Author: TEAM 6
 */ 

#include "keypad.h"

uint8_t KeyPad_getPressedKey(void)
 {
	uint8_t col, row;
	while (1) {

		/* loops for columns */
		for (col = 0; col < N_col; col++) {
			/*
			 * only one of the column pins will be output and
			 * the rest will be input pins include the row pins
			 */
			KEYPAD_PORT_DIR = (0b00010000 << col);// pin4 :pin7 
		
			/*
			 * clear the output pin column in this trace and enable the internal
			 * pull up resistors for the rows pins
			 */
			KEYPAD_PORT_OUT = (~(0b00010000 << col));//  ~(0b0001 0000) = 0b1110 1111 pin4 value = LOW 
		
			/* loops for rows */
			for (row = 0; row < N_row; row++) {
				/* If the button is pressed */
			
				if (IS_BIT_CLR(KEYPAD_PORT_IN, row)) {

					while(IS_BIT_CLR(KEYPAD_PORT_IN, row)); // to avoid the continuous pressing on the button and the bouncing error
					
					return KeyPad_4x4_adjustKeyNumber((row * N_col) + col + 1);
				}
				
			}
		}
	}
}


 uint8_t KeyPad_4x4_adjustKeyNumber(uint8_t button_number) {

	switch (button_number) {
		case 1:
		return '7';
		break;
		case 2:
		return '8';
		break;
		case 3:
		return '9';
		break;
		case 4:
		return '/'; /* ASCII Code of % */
		break;
		case 5:
		return '4';
		break;
		case 6:
		return '5';
		break;
		case 7:
		return '6';
		break;
		case 8:
		return '*'; /* ASCII Code of '*' */
		break;
		case 9:
		return '1';
		break;
		case 10:
		return '2';
		break;
		case 11:
		return '3';
		break;
		case 12:
		return '-'; /* ASCII Code of '-' */
		break;
		case 13:
		return 'C'; /* ASCII of Enter */
		break;
		case 14:
		return '0';
		break;
		case 15:
		return '='; /* ASCII Code of '=' */
		break;
		case 16:
		return '+'; /* ASCII Code of '+' */
		break;
		default:
		return button_number;
	}
}