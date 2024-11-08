/*
 * STD_TYPES.h
 *
 * Created: 11/20/2021 12:25:42 AM
 *  Author: Mohamed Salah
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef signed char s8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned long  u32;
typedef signed long   s32;

typedef unsigned long long   u64;
typedef signed long  long    s64;

typedef float f32;
typedef double f64;
	
	/*ERROR FLAG*/

#define STD_TYPES_OK 1
#define STD_TYPES_NOK 0

#define NULL ((void*) 0)

#endif /* STD_TYPES_H_ */