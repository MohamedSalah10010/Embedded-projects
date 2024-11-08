/*
 * LCD_function.c
 *
 * Created: 2/23/2022 8:23:32 PM
 *  Author: MOHAMED SALAH
 * 
 */ 



/*LIB*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#define F_CPU 8000000UL
#include <util/delay.h>
/*MCAL*/
#include "DIO_INTERFACE.h"

/*HAL*/
#include "LCD_config.h"
#include "LCD_interface.h"
#include "LCD_private.h"


void LCD_init(void)
{
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Return Home  */
	LCD_send_cmd(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	LCD_send_cmd(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_send_cmd(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_send_cmd(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_send_cmd(lcd_EntryMode);
	_delay_ms(2);

}

void LCD_send_cmd(u8 copy_cmd){
	
/*SET RS to 0*/
 DIO_setPIN_DIR(PORTA,PIN0,LOW);
/*SET RW to 0*/	
 DIO_setPIN_DIR(PORTA,PIN1,LOW);
/*Write command*/
 DIO_write_PORT(PORTC, copy_cmd);
/*SET E to 1*/
 DIO_setPIN_DIR(PORTA,PIN2,HIGH);
_delay_us(1);
/*SET E to 0*/	
 DIO_setPIN_DIR(PORTA,PIN2,LOW);		
}

void LCD_send_char(u8 copy_char){
	
	/*SET RS to 1*/
	 DIO_setPIN_DIR(PORTA,PIN0,HIGH);
	/*SET RW to 0*/
	 DIO_setPIN_DIR(PORTA,PIN1,LOW);
	/*Write data*/
	 DIO_write_PORT(PORTC, copy_char);
	/*SET E to 1*/
	 DIO_setPIN_DIR(PORTA,PIN2,HIGH);
	_delay_us(1);
	/*SET E to 0*/
	 DIO_setPIN_DIR(PORTA,PIN2,LOW);
		
}


void LCD_send_string(u8 arr[])
{
/*SET RS to 1*/
DIO_setPIN_DIR(PORTA,PIN0,HIGH);
/*SET RW to 0*/
DIO_setPIN_DIR(PORTA,PIN1,LOW);
/*Write data*/
DIO_write_PORT(PORTC, arr[30]);
/*SET E to 1*/
DIO_setPIN_DIR(PORTA,PIN2,HIGH);
_delay_us(1);
/*SET E to 0*/
DIO_setPIN_DIR(PORTA,PIN2,LOW);
}

