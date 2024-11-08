/*
 * Timer.h
 *
 * Created: 9/14/2022 10:51:54 PM
 *  Author: Mohamed Salah
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Timer_REG.h"
#include "../../Lib/BIT_MATH.h"
#include "../../Lib/STD_TYPES.h"


void timer_init(); // initiate normal mode

void delay(uint32_t duration_millisec); // set delay in milliseconds 



#endif /* TIMER_H_ */