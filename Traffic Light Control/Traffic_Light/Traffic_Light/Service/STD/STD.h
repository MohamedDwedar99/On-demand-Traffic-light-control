/*
 * STD.h
 *
 * Created: 2/14/2023 6:32:12 AM
 *  Author: SONY
 */ 


#ifndef STD_H_
#define STD_H_

typedef	unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef  double f64;

#define NULL 0x00

typedef enum Error
{
	ok,
	Bug
}Error;



#endif /* STD_H_ */