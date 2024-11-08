/*
 * Mohamed_Salah_Embedded.c
 *
 * Created: 11/28/2022 9:58:17 AM
 * Author : Mohamed Salah
 */ 

#include "MCAL/DIO/DIO_INTERFACE.h"
#include "MCAL/Timer/Timer.h"

int main(void)
{
    /* Replace with your application code */
    

	DIO_setPIN_DIR(PORTA,0,OUTPUT);// RED LED	
	DIO_setPIN_DIR(PORTA,1,OUTPUT);// YELLOW LED
	DIO_setPIN_DIR(PORTA,2,OUTPUT);// GREEN LED
	DIO_setPIN_DIR(PORTC,0,OUTPUT);// IN1
	DIO_setPIN_DIR(PORTC,1,OUTPUT);//IN2
	DIO_setPIN_DIR(PORTB,1,INPUT);
	DIO_setPIN_DIR(PORTB,2,INPUT);
	uint8_t btn_1,btn_2;

	while (1) 
    {
		
	
	btn_1=DIO_read_PIN(PORTB,1);
	btn_2=DIO_read_PIN(PORTB,2);
	
	if (btn_2==HIGH){DIO_write_PIN(PORTA,0,HIGH); // turn red on
DIO_write_PIN(PORTC,0,HIGH); // turn motor on anti-clockwise
DIO_write_PIN(PORTC,1,LOW);
}
else if (btn_1==HIGH){
	DIO_write_PIN(PORTC,0,LOW); // turn motor off 
	DIO_write_PIN(PORTC,1,LOW);
	DIO_write_PIN(PORTA,0,LOW); // turn red off
	
	DIO_write_PIN(PORTA,1,HIGH); // turn yellow on
	}
	
	/*
DIO_write_PIN(PORTA,0,HIGH); // turn red on
DIO_write_PIN(PORTC,0,HIGH); // turn motor on anti-clockwise
DIO_write_PIN(PORTC,1,LOW);
	delay(15000);
	DIO_write_PIN(PORTC,0,LOW); // turn motor off 
	DIO_write_PIN(PORTC,1,LOW);
	DIO_write_PIN(PORTA,0,LOW); // turn red off
	
	DIO_write_PIN(PORTA,1,HIGH); // turn yellow on
	delay(10000);
	
	DIO_write_PIN(PORTA,1,LOW);// turn yellow off
	DIO_write_PIN(PORTA,2,HIGH); // turn green on
	
	DIO_write_PIN(PORTC,0,LOW); //turn motor on clockwise
	DIO_write_PIN(PORTC,1,HIGH);

	delay(15000);
	
	DIO_write_PIN(PORTC,0,LOW); // turn motor off
	DIO_write_PIN(PORTC,1,LOW);
	
	DIO_write_PIN(PORTA,2,LOW); // turn green off
	DIO_write_PIN(PORTA,1,HIGH); // turn yellow on
	delay(10000);
	DIO_write_PIN(PORTA,1,LOW); // turn yellow off
	*/
	
	}
}

