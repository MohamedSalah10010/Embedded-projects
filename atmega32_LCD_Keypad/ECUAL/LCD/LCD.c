
/*
 * LCD.h
 *
 *  Created on: 4/24/2023 
 *      Author: TEAM 6
 */

#include "LCD.h"

/*   Macros */

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet4bit 0x28		  // 4-bit data, 2-line display, 5 x 7 font
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position

static uint8_t mode_flag; // HIGH if 8 bit mode, LOW if 4 bit mode
const uint8_t  extraChar[]=
{
	0b00000,0b00000,	0b00111,	0b11101,	0b00111,	0b00000,	0b00000,	0b00000, // char 1
	0b00000,	0b00000,	0b01110,0b00010,0b11111,0b00000,0b00000,0b00000 ,//char1
	0b00000,0b00000,	0b00111,	0b11101,	0b00111,	0b00000,	0b00000,	0b00000, //char2
	0b00000,	0b00000,	0b00010,	0b00010,	0b01111,	0b00000,	0b00000,	0b00000, //char3
	
};

/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit_8_bit(void)
{
	/*Set directions for DIO connected to LCD*/
	DIO_setPIN_DIR(PORT_CTRL,RS,OUTPUT);
	DIO_setPIN_DIR(PORT_CTRL,R_W,OUTPUT);
	DIO_setPIN_DIR(PORT_CTRL,EN,OUTPUT);
	
	DIO_set_PORT_DIR(PORT_DATA,OUTPUT);
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	/* Return Home  */
	LCD_vidSendCommand(lcd_Home);
	_delay_ms(15);

	/* Function Set  */
	LCD_vidSendCommand(lcd_FunctionSet8bit);
	_delay_ms(1);

	/* Display ON OFF Control */
	LCD_vidSendCommand(lcd_DisplayOn);
	_delay_ms(1);

	/* Clear Display */
	LCD_vidSendCommand(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_vidSendCommand(lcd_EntryMode);
	_delay_ms(2);
	mode_flag=HIGH;

}

/***************************************************************************************/
/* Description! Apply 4 bit initialization sequence for LCD module                     */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit_4_bit(void)
{
	/*Set directions for DIO connected to LCD*/
	DIO_setPIN_DIR(PORT_CTRL,RS,OUTPUT);
	DIO_setPIN_DIR(PORT_CTRL,R_W,OUTPUT);
	DIO_setPIN_DIR(PORT_CTRL,EN,OUTPUT);
	
	DIO_setPIN_DIR(PORT_DATA,D7,OUTPUT);
	DIO_setPIN_DIR(PORT_DATA,D6,OUTPUT);
	DIO_setPIN_DIR(PORT_DATA,D5,OUTPUT);
	DIO_setPIN_DIR(PORT_DATA,D4,OUTPUT);
	
	/* Delay 30ms to ensure the initialization of the LCD driver */
	_delay_ms(30);

	LCD_vidSendCommand_4_bit(lcd_Home);
	_delay_ms(15);
	
	LCD_vidSendCommand_4_bit(lcd_FunctionSet4bit);
	_delay_ms(2);

	/* Display ON OFF Control */
	LCD_vidSendCommand_4_bit(lcd_DisplayOn);
	_delay_ms(2);

	/* Clear Display */
	LCD_vidSendCommand_4_bit(lcd_Clear);
	_delay_ms(15);

	/* Entry Mode Set  */
	LCD_vidSendCommand_4_bit(lcd_EntryMode);
	_delay_ms(2);

	mode_flag = LOW; // 4-bit mode
}


/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(uint8_t u8CmdCpy)
{

	/* Set RS to LOW */
	DIO_write_PIN(PORT_CTRL, RS, LOW);

	/* Set R/W to LOW */
	DIO_write_PIN(PORT_CTRL, R_W, LOW);

	/* Set E to HIGH  */
	DIO_write_PIN(PORT_CTRL, EN, HIGH);

	/* Load Command on Data bus */
	//DIO_write_PORT(PORT_DATA, u8CmdCpy);
	if(mode_flag == LOW){
		DIO_write_PIN(PORT_DATA,D7 ,READ_BIT(u8CmdCpy,7)); 
		DIO_write_PIN(PORT_DATA,D6 ,READ_BIT(u8CmdCpy,6)); 
		DIO_write_PIN(PORT_DATA,D5 ,READ_BIT(u8CmdCpy,5));
		DIO_write_PIN(PORT_DATA,D4 ,READ_BIT(u8CmdCpy,4)); 
	}
	
	else{
		DIO_write_PIN(PORT_DATA,D7 ,READ_BIT(u8CmdCpy,7));
		DIO_write_PIN(PORT_DATA,D6 ,READ_BIT(u8CmdCpy,6));
		DIO_write_PIN(PORT_DATA,D5 ,READ_BIT(u8CmdCpy,5));
		DIO_write_PIN(PORT_DATA,D4 ,READ_BIT(u8CmdCpy,4));
		DIO_write_PIN(PORT_DATA,D3 ,READ_BIT(u8CmdCpy,3));
		DIO_write_PIN(PORT_DATA,D2 ,READ_BIT(u8CmdCpy,2));
		DIO_write_PIN(PORT_DATA,D1 ,READ_BIT(u8CmdCpy,1));
		DIO_write_PIN(PORT_DATA,D0 ,READ_BIT(u8CmdCpy,0));
	}
	
	/* Set E to LOW */
	DIO_write_PIN(PORT_CTRL, EN, LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_write_PIN(PORT_CTRL, EN, HIGH);

	/* Delay for 10ms to let the LCD execute command */
	_delay_ms(10);

}

void LCD_vidSendCommand_4_bit(uint8_t u8CmdCpy)
{
		
	uint8_t cmd = (u8CmdCpy & 0xf0);
	LCD_vidSendCommand(cmd);
	_delay_ms(2);
	cmd = ((u8CmdCpy<<4) & 0xf0);

	
	
	LCD_vidSendCommand(cmd);
	_delay_ms(2);
	
}

/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(uint8_t u8DataCpy)
{
	/* Set RS to HIG */
	DIO_write_PIN(PORT_CTRL, RS, HIGH);

	/* Set R/W to LOW */ 
	DIO_write_PIN(PORT_CTRL, R_W, LOW); // R --> 1 , W --> 0

	/* Set E to HIGH */
	DIO_write_PIN(PORT_CTRL, EN, HIGH);

	/* Load Command on Data bus */
	if (mode_flag == LOW){
		DIO_write_PIN(PORT_DATA,D7 ,READ_BIT(u8DataCpy,7));
		DIO_write_PIN(PORT_DATA,D6 ,READ_BIT(u8DataCpy,6));
		DIO_write_PIN(PORT_DATA,D5 ,READ_BIT(u8DataCpy,5));
		DIO_write_PIN(PORT_DATA,D4 ,READ_BIT(u8DataCpy,4));
	}
	else{
		DIO_write_PIN(PORT_DATA,D7 ,READ_BIT(u8DataCpy,7));
		DIO_write_PIN(PORT_DATA,D6 ,READ_BIT(u8DataCpy,6));
		DIO_write_PIN(PORT_DATA,D5 ,READ_BIT(u8DataCpy,5));
		DIO_write_PIN(PORT_DATA,D4 ,READ_BIT(u8DataCpy,4));
		DIO_write_PIN(PORT_DATA,D3 ,READ_BIT(u8DataCpy,3));
		DIO_write_PIN(PORT_DATA,D2 ,READ_BIT(u8DataCpy,2));
		DIO_write_PIN(PORT_DATA,D1 ,READ_BIT(u8DataCpy,1));
		DIO_write_PIN(PORT_DATA,D0 ,READ_BIT(u8DataCpy,0));
	
	}	
	
	/* Set E to LOW */
	DIO_write_PIN(PORT_CTRL, EN, LOW);

	/* Wait for E to settle */
	_delay_ms(5);

	/* Set E to HIGH */
	DIO_write_PIN(PORT_CTRL, EN, HIGH);

	/* Delay to let the LCD Display the character */
	_delay_ms(10);

}

void LCD_vidWriteCharctr_4_bit(uint8_t u8DataCpy)
{
 	uint8_t data = (u8DataCpy & 0xf0);
	LCD_vidWriteCharctr(data);
	_delay_ms(2);
	data = ((u8DataCpy<<4) & 0xf0);
	LCD_vidWriteCharctr(data);
	_delay_ms(2);


}
/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (uint8_t* pu8StringCpy)
{

//	/* Local loop index */
	uint8_t u8Index = 0;
// 	aa[5]={1,2,3,4,'\0'}		ahmed[0], ahmed[1]
// 	char ahmed[6]="ahmed"; --> {'a','h'......'d','\0'}	
		
	while (pu8StringCpy[u8Index] != '\0')
	
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr(pu8StringCpy[u8Index]);

		/* Increment local loop index */
		u8Index++;

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}

}
void LCD_vidWriteString_4_bit (uint8_t* pu8StringCpy)
{

	//	/* Local loop index */
	
	uint8_t u8Index = 0;

		while (pu8StringCpy[u8Index] != '\0')
	
	{

		/* Write Character on LCD */
		LCD_vidWriteCharctr_4_bit(pu8StringCpy[u8Index]);

		/* Increment local loop index */
				u8Index++;

		/* Delay to let the LCD show the character */
		_delay_ms(2);
	}

}
/***************************************************************************************/
/* Description! Interface to start the writing process at certain digit in the LCD     */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void Gotoxy (uint8_t Y,uint8_t X)
{
	if (X>=0 && X<=15)
	{
	    switch(Y)
	    {
		    case 1:
					LCD_vidSendCommand(X+127);
					break;
		    case 2:
		    		LCD_vidSendCommand(X+191);
					break;
		    default:
					break;
	    }
	}
}
void Gotoxy_4_bit (uint8_t Y,uint8_t X)
{
	
	if (X>=0 && X<=15)
	{
		switch(Y)
		{
			case 1:
					LCD_vidSendCommand_4_bit(0x80+X);
					break;
			case 2:
					LCD_vidSendCommand_4_bit(0xC0+X);
					break;
			default:
					break;
		}
	}
}

/***************************************************************************************/
/* Description! Interface to write extra characters saved in the CGRAM                 */
/* Input      ! Y = Row position , X = Column position                                 */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteExtraChar (uint8_t Y,uint8_t X)
{
    uint8_t iteration1,iteration2;

    /*DDRAM-->CGRAM*/
    LCD_vidSendCommand_4_bit(64);// 0b01000000
	for(iteration1=0 ; iteration1<64 ; iteration1++)
	{
		LCD_vidWriteCharctr_4_bit(extraChar[iteration1]);
	}
	/*CGRAM-->DDRAM*/
	LCD_vidSendCommand_4_bit(128);
	Gotoxy_4_bit(Y,X);
	/*First eight character which saved at CGRAM*/
	for (iteration2=0; iteration2<=7 ; iteration2++)
	{
		/* Write bytes of DDRAM */
		LCD_vidWriteCharctr_4_bit(iteration2); // choose your char

		_delay_ms(5);
	}
}
