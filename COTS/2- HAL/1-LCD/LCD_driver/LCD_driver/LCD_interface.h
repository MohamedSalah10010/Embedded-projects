/*
 * LCD_interface.h
 *
 * Created: 2/23/2022 8:23:15 PM
 *  Author: MOHAMED SALAH
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


void LCD_init(void);

void LCD_send_cmd(u8 copy_cmd);

void LCD_send_char(u8 copy_char);

void LCD_send_string(u8 *ptr);



#endif /* LCD_INTERFACE_H_ */