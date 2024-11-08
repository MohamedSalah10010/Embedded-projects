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
	void DIO_voidInit();
	DIO_set_PORT_DIR(B,INPUT);
	DIO_set_PORT_DIR(D,OUTPUT);
	while(1){
			DIO_write_PIN(D,0,HIGH);
			DIO_write_PIN(D,1,LOW);
			DIO_write_PIN(D,2,HIGH);
			DIO_write_PIN(D,3,LOW);
			DIO_write_PIN(D,4,HIGH);

	}

}
