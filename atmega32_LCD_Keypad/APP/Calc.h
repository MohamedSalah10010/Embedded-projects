/*
 * Calc.h
 *
 * Created: 4/24/2023 6:41:51 AM
 *  Author: TEAM 6
 *
  */ 


#ifndef CALC_H_
#define CALC_H_


#include "../ECUAL/KEYPAD/keypad.h"
#include "../ECUAL/LCD/LCD.h"
#define  MAX_LENGTH_FOR_NUM 5


 void app(void);

float calc(sint64_t num1 , sint64_t num2, uint8_t op);

sint64_t  getnum(uint8_t* op);

#endif /* CALC_H_ */