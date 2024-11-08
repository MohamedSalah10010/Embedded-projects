/*
 * embedded_lab.c
 *
 * Created: 11/13/2022 2:24:17 PM
 * Author : abosa
 */ 


#include "MCAL/DIO_INTERFACE.h"

int main(void)
{
	DIO_setPIN_DIR(PORTA,5,OUTPUT);
	
    /* Replace with your application code */
    while (1) 
    {
		DIO_write_PIN(PORTA,5,HIGH);
    }
}

