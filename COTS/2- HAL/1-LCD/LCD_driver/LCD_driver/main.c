/*
 * main.c
 *
 * Created: 11/20/2021 2:07:58 PM
 *  Author: Mohamed Salah
 */

#include "DIO_INTERFACE.h"
#include "LCD_interface.h"

#define F_CPU 8000000UL
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"


int main(void){
	 
	 LCD_init();
	DIO_set_PORT_DIR(A,OUTPUT);
	DIO_set_PORT_DIR(D,OUTPUT);
	while(1){
			
	 LCD_send_char('H');
	 LCD_send_char('A');
	 _delay_ms(100);
	 
	}

}
