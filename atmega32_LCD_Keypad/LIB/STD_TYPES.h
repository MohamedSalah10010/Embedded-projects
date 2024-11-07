/*
 * STD_TYPES.h
 *
 *  Created: 12/09/2022 11:25:42 AM
 *  Author: Mohamed Salah
 */ 

/*Standards data types lib*/



#ifndef STD_TYPES_H_
#define STD_TYPES_H_



typedef unsigned char uint8_t;
typedef signed char sint8_t;

typedef unsigned short uint16;
typedef signed short sint16_t;

typedef unsigned int uint32;
typedef signed int sint32_t;

typedef unsigned long long uint64;
typedef signed long long sint64_t;

	
	/*ERROR FLAG*/

#define STD_TYPES_OK 1
#define STD_TYPES_NOK 0

#define NULL ((void*) 0)

#endif /* STD_TYPES_H_ */