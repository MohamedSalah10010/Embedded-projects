/*
 * DIO_program.c
 *
 * Created: 13/9/2022 8:50:05 PM
 *  Author: Mohamed Salah
 */

#include "DIO_INTERFACE.h"

#define A	PORTA
#define B	PORTB
#define C	PORTC
#define	D	PORTD

#define a	PORTA
#define b	PORTB
#define c	PORTC
#define d	PORTD


 void DIO_voidInit(void)
 {
		DDRA_REG=Init_direction_default;
		DDRB_REG=Init_direction_default;
		DDRC_REG=Init_direction_default;
		DDRD_REG=Init_direction_default;

		PINA_REG=Init_PinValue_default;
		PINB_REG=Init_PinValue_default;
		PINC_REG=Init_PinValue_default;
		PIND_REG=Init_PinValue_default;
 }

 /************	PORT FUNCTIONS	**********/
	 u8 DIO_set_PORT_DIR(u8 portnum, u8 dir){

	 u8 Local_u8ErrorState = STD_TYPES_OK;

	 if(((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD)) && ((dir==INPUT)||(dir==OUTPUT)))
 {
	 switch (portnum)
	  {
			case PORTA: DDRA_REG=dir;break;
			case PORTB: DDRB_REG=dir;break;
			case PORTC: DDRC_REG=dir;break;
			case PORTD: DDRD_REG=dir;break;
			default:Local_u8ErrorState = STD_TYPES_NOK;break;

		}

 }
	 else
	  Local_u8ErrorState = STD_TYPES_NOK;
	 return Local_u8ErrorState;
	 }


	 u8 DIO_read_PORT(u8 portnum)
	 {
		 u8 Local_u8ErrorState = STD_TYPES_OK;
        volatile u8 value=0;
		 if((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))
		 {

			switch(portnum)
			{
			case PORTA: value=PINA_REG;break;
			case PORTB: value=PINB_REG;break;
			case PORTC: value=PINC_REG;break;
			case PORTD: value=PIND_REG;break;
			default: Local_u8ErrorState = STD_TYPES_NOK;break;
			}

		 }
		 else
		  Local_u8ErrorState = STD_TYPES_NOK;
		 return value,Local_u8ErrorState;

	 }


	 u8 DIO_write_PORT(u8 portnum,u8 value)
	 {
	u8 Local_u8ErrorState = STD_TYPES_OK;

	if(((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))&&((value==HIGH)||(value==LOW)))
	{

		switch(portnum)
		{
			case PORTA: PORTA_REG=value;break;
			case PORTB: PORTB_REG=value;break;
			case PORTC: PORTC_REG=value;break;
			case PORTD: PORTD_REG=value;break;
			default: Local_u8ErrorState = STD_TYPES_NOK;break;
		}

	}
	else{
	 Local_u8ErrorState = STD_TYPES_NOK;}

	return Local_u8ErrorState;

	 }

	 u8 DIO_toggle_PORT(u8 portnum)
	 {
		 u8 Local_u8ErrorState = STD_TYPES_OK;

		 if((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))
		 {
			 switch(portnum)
			 {
				 case PORTA: PORTA_REG=~PORTA_REG;break;
				 case PORTB: PORTB_REG=~PORTB_REG;break;
				 case PORTC: PORTC_REG=~PORTC_REG;break;
				 case PORTD: PORTD_REG=~PORTD_REG;break;
				 default: Local_u8ErrorState = STD_TYPES_NOK;break;
			 }

		 }
		 else
		  Local_u8ErrorState = STD_TYPES_NOK;
		 return Local_u8ErrorState;
	 }


	 /************ PIN FUNCTIONS ************/
	u8 DIO_setPIN_DIR(u8 portnum, u8 pinnum, u8 dir)
	{
		u8 Local_u8ErrorState = STD_TYPES_OK;

		if (((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))&& (pinnum<=PIN7)&&((dir==INPUT)||(dir==OUTPUT)))
		{
			switch(portnum)
			{
			case PORTA:
			if (dir==OUTPUT){ SET_BIT(DDRA_REG,pinnum);}
			else {CLR_BIT(DDRA_REG,pinnum);}
			break;

			case PORTB:
			if (dir==OUTPUT){ SET_BIT(DDRB_REG,pinnum);}
			else {CLR_BIT(DDRB_REG,pinnum);}
			break;

			case PORTC:
			if (dir==OUTPUT){ SET_BIT(DDRC_REG,pinnum);}
			else {CLR_BIT(DDRC_REG,pinnum);}
			break;

			case PORTD:
			if (dir==OUTPUT){ SET_BIT(DDRD_REG,pinnum);}
			else {CLR_BIT(DDRD_REG,pinnum);}
			break;

			default: Local_u8ErrorState = STD_TYPES_NOK;break;
			}

		}
		else
		 Local_u8ErrorState = STD_TYPES_NOK;
		return Local_u8ErrorState;
			}

	u8 DIO_read_PIN(u8 portnum,u8 pinnum)
	{
		u8 Local_u8ErrorState = STD_TYPES_OK;
        volatile u8 value=0;
		if (((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))&& (pinnum<=PIN7))
		{


			switch(portnum)
			{
				case PORTA:	value= READ_BIT(PINA_REG,pinnum);
				break;

				case PORTB:	value= READ_BIT(PINB_REG,pinnum);
				break;

				case PORTC:	value= READ_BIT(PINC_REG,pinnum);
				break;

				case PORTD:	value= READ_BIT(PIND_REG,pinnum);
				break;

				default: Local_u8ErrorState = STD_TYPES_NOK;break;
			}

		}
		else
		 Local_u8ErrorState = STD_TYPES_NOK;
		return value,Local_u8ErrorState;
	}


	u8 DIO_write_PIN(u8 portnum,u8 pinnum,u8 value)
	{
		u8 Local_u8ErrorState = STD_TYPES_OK;

		if (((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))&& (pinnum<=PIN7)&&((value==HIGH)||(value==LOW)))
		{
			switch(portnum)
			{
				case PORTA:
				if (value==HIGH){ SET_BIT(PORTA_REG,pinnum);}
				else {CLR_BIT(PORTA_REG,pinnum);}
				break;

				case PORTB:
				if (value==HIGH){ SET_BIT(PORTB_REG,pinnum);}
				else {CLR_BIT(PORTB_REG,pinnum);}
				break;

				case PORTC:
				if (value==HIGH){ SET_BIT(PORTC_REG,pinnum);}
				else {CLR_BIT(PORTC_REG,pinnum);}
				break;

				case PORTD:
				if (value==HIGH){ SET_BIT(PORTD_REG,pinnum);}
				else {CLR_BIT(PORTD_REG,pinnum);}
				break;

				default: Local_u8ErrorState = STD_TYPES_NOK;break;
			}

		}
		else
		 Local_u8ErrorState = STD_TYPES_NOK;
		return Local_u8ErrorState;
	}

	u8 DIO_toggle_PIN(u8 portnum,u8 pinnum)
	{
		u8 Local_u8ErrorState = STD_TYPES_OK;

		if (((portnum==PORTA)||(portnum==PORTB)||(portnum==PORTC)||(portnum==PORTD))&& (pinnum<=PIN7))
		{

			switch(portnum)
			{
				case PORTA:	 TOGGLE_BIT(PORTA_REG,pinnum);
				break;

				case PORTB:	 TOGGLE_BIT(PORTB_REG,pinnum);
				break;

				case PORTC:	 TOGGLE_BIT(PORTC_REG,pinnum);
				break;

				case PORTD:	 TOGGLE_BIT(PORTD_REG,pinnum);
				break;

				default: Local_u8ErrorState = STD_TYPES_NOK;break;
			}

		}
		else
		 Local_u8ErrorState = STD_TYPES_NOK;
		return Local_u8ErrorState;
	}


	
