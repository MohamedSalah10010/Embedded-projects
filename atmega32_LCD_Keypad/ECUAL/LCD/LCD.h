/*
 * LCD.h
 *
 *  Created on: 4/24/2023 
 *      Author: TEAM 6
 */

#ifndef ECUAL_LCD_LCD_H_
#define ECUAL_LCD_LCD_H_

// Driver Inclusions

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "LCD_interface.h"




/***************************************************************************************/
/* Description! Apply initialization sequence for LCD module                           */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidInit_8_bit(void);

void LCD_vidInit_4_bit(void);

/***************************************************************************************/
/* Description! Interface to send the configuration commands to the LCD Driver         */
/* Input      ! Command number                                                         */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidSendCommand(uint8_t u8CmdCpy);

void LCD_vidSendCommand_4_bit(uint8_t u8CmdCpy);


/***************************************************************************************/
/* Description! Interface to write character on LCD screen                             */
/* Input      ! Data to send                                                           */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteCharctr(uint8_t  u8DataCpy);

void LCD_vidWriteCharctr_4_bit(uint8_t  u8DataCpy);

/***************************************************************************************/
/* Description! Interface to write string on LCD screen                                */
/* Input      ! Pointer to the string                                                  */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
void LCD_vidWriteString (uint8_t * pu8StringCpy);
void LCD_vidWriteString_4_bit (uint8_t * pu8StringCpy);


/***************************************************************************************/
/* Description! go to specific location on LCD screen                                  */
/* Input      ! row number (Y) & coloumn number (X)                                    */
/* Output     ! Nothing                                                                */
/***************************************************************************************/

void Gotoxy (uint8_t  Y,uint8_t  X);
void Gotoxy_4_bit (uint8_t  Y,uint8_t  X);

void LCD_vidWriteExtraChar (uint8_t  Y,uint8_t  X);




#endif /* ECUAL_LCD_LCD_H_ */
