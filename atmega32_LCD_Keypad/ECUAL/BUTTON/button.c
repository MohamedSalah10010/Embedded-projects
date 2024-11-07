/*
 * button.c
 *
 * Created: 22-Nov-22 6:50:54 AM
 *  Author: Mahmoud
 */ 


#include "button.h"


 void BTN_init  (uint8_t btnNum)
{
	switch(btnNum)
	{
		case 1:
			DIO_setPIN_DIR (BTN_1_PORT, BTN_1_PIN, INPUT);
			DIO_write_PIN(BTN_1_PORT, BTN_1_PIN, LOW);
			break;
		case 2:
			DIO_setPIN_DIR (BTN_2_PORT, BTN_2_PIN, INPUT);
			DIO_write_PIN(BTN_2_PORT, BTN_2_PIN, LOW);
			break;
		case 3:
			DIO_setPIN_DIR (BTN_3_PORT, BTN_3_PIN, INPUT);
			DIO_write_PIN(BTN_3_PORT, BTN_3_PIN, LOW);
			break;
		case 4:
			DIO_setPIN_DIR (BTN_4_PORT, BTN_4_PIN, INPUT);
			DIO_write_PIN(BTN_4_PORT, BTN_4_PIN, LOW);
			break;
		default:
			// ERR
			break;
	}
}

uint8_t   BTN_read  (uint8_t btnNum)
{
	uint8_t btnValue = 0;
	switch(btnNum)
	{
		case 1:
			btnValue = DIO_read_PIN(BTN_1_PORT, BTN_1_PIN);
			break;
		case 2:
			btnValue = DIO_read_PIN(BTN_2_PORT, BTN_2_PIN);
			break;
		case 3:
			btnValue = DIO_read_PIN(BTN_3_PORT, BTN_3_PIN);
			break;
		case 4:
			btnValue = DIO_read_PIN(BTN_4_PORT, BTN_4_PIN);
			break;
		default:
			// ERR
			break;
	}
	return btnValue;
}

