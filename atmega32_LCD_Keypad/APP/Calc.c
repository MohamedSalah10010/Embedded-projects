/*
 * Calc.c
 *
 * Created: 4/24/2023 5:59:56 AM
 *  Author: TEAM 6
 */

#include "Calc.h"

sint64_t  getnum(uint8_t* op){
	
	uint8_t * num = (uint8_t *) malloc(MAX_LENGTH_FOR_NUM * sizeof(uint8_t)); // create arr that contain the integers

	uint8_t i= 0;	// index 
	sint64_t num1=0;  
	
	uint8_t key = KeyPad_getPressedKey(); /*
	
	7 8 9 - 
	4 5 6 + 
	1 2 3 /
	C 0   *
	
	*/
	
	while(key != '='){
		
		if(i < MAX_LENGTH_FOR_NUM){
		
			if(
			key == '*' ||
			key == '+' ||
			key == '-' ||
			key == '/' ||
			key =='C' )
			{
			if (key=='C'){
							LCD_vidInit_4_bit(); // clear LCD
							
							// clear all the value of num[]
							
							for (uint8_t j=0; j<MAX_LENGTH_FOR_NUM;j++){num[j]=0;} 
							free(num);
							
							*op= key; // aka C
							return num1; 
						}		
				
				LCD_vidWriteCharctr_4_bit(key);// * - / +
				
				
				
				// clear all the value of num[]
				for (uint8_t j=0; j<MAX_LENGTH_FOR_NUM;j++){num[j]=0;} 	
				free(num);
				
				
				*op= key; // * - / +
				return num1;
				
				}
				
			LCD_vidWriteCharctr_4_bit(key);
			num[i]=key;
				
				
			num1 = atoi((char *)num); // convert string "array of characters" to int
				
			i++;
				
			key= KeyPad_getPressedKey();
			
		}
		
		
	else if (i == MAX_LENGTH_FOR_NUM){
			num[MAX_LENGTH_FOR_NUM]='\0'; // num[5]= {1,2,4,5,'\0'}; 1245 string  
			
			num1 = atoi((char *)num); // 1245 str to 1245 int
			
			while(key != '*' && key != '+' &&key != '-' &&key != '/' &&	key != 'C'){
				Gotoxy_4_bit(1,MAX_LENGTH_FOR_NUM);// line 1 ,5
				key=KeyPad_getPressedKey();
				}
		
			if( key == '*' ||
			key == '+' ||
			key == '-' ||
			key == '/' ||
			key == 'C')
			{
				if (key == 'C' ){ 
				LCD_vidInit_4_bit();
				
				// clear all the value of num[]
				for (uint8_t j=0; j<MAX_LENGTH_FOR_NUM;j++){num[j]=0;}
				free(num);
				
				
				
				*op= key;
				return num1;
				
				}
					
				LCD_vidWriteCharctr_4_bit(key);
			
				
				// clear all the value of num[]
				for (uint8_t j=0; j<MAX_LENGTH_FOR_NUM;j++)num[j]=0;
				free(num);
				
				
				*op= key;
				return num1;	
		}
		
		
		}

	}
	
	*op =key; // =
	 return num1;
}
 
 float  calc (sint64_t  num1, sint64_t num2, uint8_t op)
 {
	 
	 
	 switch (op)
	 {
		 case '+':   return num1 + num2;
		 case '-':   return num1 - num2;
		 case '*':   return num1 * num2;
		 case '/':   if (num2 == 0) return 0;
					 else return ((float)num1 / num2);
		 default:    return 0;
	 }
	 
 }
 
 void app(void){
	 sint64_t number1,number2;
	 float res;
	 float result[MAX_LENGTH_FOR_NUM];
	 sint64_t num1[MAX_LENGTH_FOR_NUM],num2[MAX_LENGTH_FOR_NUM];
	 
	 uint8_t key1,key2;
	 
	 
	 
	 while(1)
	 {
		 
		 
		 LCD_vidInit_4_bit();
		 LCD_vidWriteExtraChar (1,1);
		 _delay_ms(1000);
		 LCD_vidInit_4_bit();
		
		 number1= getnum(&key1);
		 
		 if (key1 =='C'){ app();}
		 else if( key1 == '='){ 
			 sprintf((char *)num1,"%lld",number1); // convert int to string 
			 Gotoxy_4_bit(2,0);
			 LCD_vidWriteString_4_bit((uint8_t *)num1);
			 _delay_ms(500);
			 app();
			 }
		 
		 number2= getnum(&key2); 
		 
		 sprintf((char *)num1,"%lld",number1);
		 sprintf((char *)num2,"%lld",number2);
		 
		 res = calc(number1,number2,key1);
		 
		 if (key1!='/')
		 {
			  sprintf((char *)result,"%lld",(sint64_t)res);// (float to int ) to string
		 }
		 else 
		 {
			 
			 sprintf((char *)result,"%0.2lf",res); // float with 2 decimals to  string
		 }
		
		 
		 
		 Gotoxy_4_bit(2,0);
		 
		 LCD_vidWriteString_4_bit((uint8_t *)result);
		 
		 if(KeyPad_getPressedKey()){app();}
			 
		 }
		
		 
	 }
