/*
 * KEYPAD.c
 *
 * Created: 4/23/2023 12:16:04 AM
 *  Author: Mohamed Salah
 */ 
/***************************************************************************************/
/*
R1 --> 0			C1 --> 4
R2 --> 1			C2 --> 5
R3 --> 2			C3 --> 6
R4 --> 3			C4 --> 7
*/
#include "KEYPAD_INTERFACE.h"
uint8_t colloc, rowloc;
uint8_t keypad[4][4] = 
{
	{'7', '8', '9', '/'},
	{'4', '5', '6', '*'},
	{'1', '2', '3', '-'},
	{'C', '0', '=', '+'}
};


uint8_t KEYPAD_getChar(uint8_t *Key)
{
	uint8_t Local_u8ErrorState = STD_TYPES_OK;
	uint8_t rowcounter, colcounter,pinval,flag;
	
	*Key=0xFF;
	if (Key != NULL ){
		
		
		for(rowcounter = 0 ; rowcounter<=3 ; rowcounter++)
		{
			
			DIO_write_PIN(port, rowcounter, LOW);
			
			for(colcounter = 4 ; colcounter<=7 ; colcounter++)
			{
				pinval = DIO_read_PIN(port,colcounter);
				if( pinval == LOW)
				{
					
					_delay_ms(20);
					pinval = DIO_read_PIN(port,colcounter);
					
					while(pinval == LOW)
					{
						pinval = DIO_read_PIN(port,colcounter);
						
					}
					*Key = keypad[rowcounter][colcounter];
					flag=1;
					break;
				}
			}
			
			DIO_write_PIN(port, rowcounter, HIGH);
			
			if (flag ==1){
				break;
			}
			
		}
		
		
	}
	else {
		Local_u8ErrorState =STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
	
	}