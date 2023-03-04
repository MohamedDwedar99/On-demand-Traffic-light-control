/*
 * Timer_Interface.h
 *
 * Created: 2/14/2023 6:40:56 AM
 *  Author: SONY
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


#define TCCR0 *((volatile u8*)0x53)
#define TCNT0 *((volatile u8*)0x52)
#define OCR0 *((volatile u8*)0x5C)
#define TIMSK *((volatile u8*)0x59)
#define TIFR *((volatile u8*)0x58)

enum Time_Error
{
	Time_OK,
	Time_InitError,
	Time_SetTimeError	
};

u8 Time_Init(void);
void __vector_11(void) __attribute__((signal,used));
u8 SetTime(void (*ptr)(void));

#endif /* TIMER_INTERFACE_H_ */