/*
 * main.c
 *
 * Created: 11/20/2021 2:07:58 PM
 *  Author: Mohamed Salah
 */

#include "DIO_INTERFACE.h"

#define F_CPU 8000000UL
#include <util/delay.h>
#include "STD_TYPES.h"


int main(void){
	 //DIO_voidInit();
	DIO_set_PORT_DIR(B,OUTPUT);
	DIO_set_PORT_DIR(A,OUTPUT);
	DIO_set_PORT_DIR(c,OUTPUT);
	while(1){
			
			//DIO_write_PORT(C,HIGH);
			//_delay_ms(500);
			DIO_write_PORT(C,0b00001111);
			_delay_ms(1000);			
			
			DIO_write_PIN(C,0,HIGH);
			DIO_write_PIN(C,7,HIGH);DIO_write_PIN(C,6,HIGH);
			DIO_write_PORT(A,0x00110011);
			
			_delay_ms(500);
			DIO_write_PORT(A,HIGH);
			
			
			/*
			DIO_write_PIN(A,0,HIGH);
			_delay_ms(500);
			DIO_write_PIN(A,0,LOW);
			_delay_ms(1000);
			DIO_write_PIN(A,1,HIGH);
			
			_delay_ms(500);
			DIO_write_PIN(A,1,LOW);
			_delay_ms(1000);
			
			DIO_write_PIN(A,2,HIGH);
			_delay_ms(500);
			DIO_write_PIN(A,2,LOW);
			_delay_ms(1000);
			DIO_write_PIN(A,3,HIGH);
			_delay_ms(500);
			DIO_write_PIN(A,3,LOW);
			_delay_ms(1000);
			DIO_write_PIN(A,4,HIGH);
			_delay_ms(500);
			DIO_write_PIN(A,4,LOW);
			_delay_ms(1000);
			DIO_write_PIN(A,5,HIGH);
			_delay_ms(500);
			DIO_write_PIN(A,5,LOW);
			_delay_ms(1000);
	*/
			
			
	}

}
