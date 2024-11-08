/*
 * EMBEDDED_TASK.c
 *
 * Created: 12/7/2022 11:36:50 PM
 * Author : abosa
 */ 

#include "MCAL/DIO.h"
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
    DIO_init(PORT_A,0,OUT); // LED RED
    DIO_init(PORT_A,1,OUT); // YELLOW LED
    DIO_init(PORT_A,2,OUT); // GREEN LED
    DIO_init(PORT_C,0,OUT);// MOTOR IN1
    DIO_init(PORT_C,1,OUT);// MOTOR IN2
    
	while (1) 
    {
		DIO_write(PORT_A,0,HIGH);//RED STATE
		DIO_write(PORT_C,0,HIGH);
		DIO_write(PORT_C,1,LOW);
		_delay_ms(5000);
		DIO_write(PORT_A,0,LOW);//RED OFF
		DIO_write(PORT_A,1,HIGH); // YELLOW STATE
		DIO_write(PORT_C,0,LOW);
		DIO_write(PORT_C,1,LOW);
		_delay_ms(5000);
		DIO_write(PORT_A,1,LOW); // YELLOW STATE
		DIO_write(PORT_A,2,HIGH);//GREEN STATE
		DIO_write(PORT_C,1,HIGH);
		DIO_write(PORT_C,0,LOW);
		_delay_ms(5000);
		DIO_write(PORT_A,2,LOW);//GREEN STATE
		
		
		
    }
}

