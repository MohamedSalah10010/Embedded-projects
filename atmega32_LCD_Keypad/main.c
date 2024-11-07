/*
 * main.c
 *
 * Created: 4/22/2023 4:29:10 PM
 *  Author: TEAM 6
 */
 
 
#include "APP/Calc.h"
uint8_t str[]= "MOHAMED";
uint8_t str2[]= "SALAH";
uint8_t wel[] = "WELCOME!!";
static uint8_t btn,btn2;


void fir(){
	
	 for (uint8_t i =1 ; i<15 ; i++)
	 {  
		 btn2= DIO_read_PIN(PORTC,2);
		
		if (btn2==HIGH)break;
		 LCD_vidInit_4_bit();
		 Gotoxy_4_bit(1,i);
		 LCD_vidWriteString_4_bit(str);
		 _delay_ms(100);
		 
	 }
	
	
}

void sec(){
	
	for (uint8_t i = 0 ; i<15; i++){
		
		btn =DIO_read_PIN(PORTC,1);
		
		if (btn==HIGH)break;
		
		LCD_vidInit_4_bit();
		Gotoxy_4_bit(1, i);
		LCD_vidWriteString_4_bit(str2);
		_delay_ms(100);
	}
	
}
	
int main(void)
{
	
	
	LCD_vidInit_4_bit();
	LCD_vidWriteString_4_bit(wel);
	
  
	
	
	DIO_setPIN_DIR(PORTC,1,INPUT);
	DIO_setPIN_DIR(PORTC,2,INPUT);
	
	while (1)
	{
		
		 btn =DIO_read_PIN(PORTC,1);
		 btn2= DIO_read_PIN(PORTC,2);
		  
		  if (btn== HIGH){		
			  while(btn2!= HIGH) {
				  fir();
				  }
			  btn= LOW;
			  
		  }
		  
		 if(btn2 == HIGH){
			 
				
			 while(btn!= HIGH){ 	sec();}
			btn2= LOW;
				
			}
			  
		  }
	}
	
	
	

		 
