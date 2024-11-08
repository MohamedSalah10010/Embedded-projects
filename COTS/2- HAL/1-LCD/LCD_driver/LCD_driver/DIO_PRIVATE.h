/*
 * DIO_PRIVATE.h
 *
 * Created: 11/19/2021 10:55:48 PM
 *  Author: Mohamed Salah
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*	REGESTERS	*/
/* Port A */
#define PORTA_REG  *((volatile u8*)0X3B)
#define DDRA_REG   *((volatile u8*)0X3A)
#define PINA_REG   *((volatile u8*)0X39)

/* Port B */
#define PORTB_REG  *((volatile u8*)0X38)
#define DDRB_REG   *((volatile u8*)0X37)
#define PINB_REG   *((volatile u8*)0X36)

/* Port C */
#define PORTC_REG  *((volatile u8*)0X35)
#define DDRC_REG   *((volatile u8*)0X34)
#define PINC_REG  *((volatile u8*)0X33)

/* Port D */
#define PORTD_REG  *((volatile u8*)0X32)
#define DDRD_REG   *((volatile u8*)0X31)
#define PIND_REG   *((volatile u8*)0X30)


#endif /* DIO_PRIVATE_H_ */