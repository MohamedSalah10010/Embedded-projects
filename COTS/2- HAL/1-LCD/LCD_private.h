/*
 * LCD_private.h
 *
 * Created: 2/23/2022 8:22:37 PM
 *  Author: MOHAMED SALAH
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_



#define  Clear		    0x01
#define  Home			0x02
#define  Englishwrap	0x06
#define  Arabicwrap		0x04
#define DisplayON		0x0C
#define CursorON		0x0E
#define BlinkON			0x0F
#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position



#endif /* LCD_PRIVATE_H_ */