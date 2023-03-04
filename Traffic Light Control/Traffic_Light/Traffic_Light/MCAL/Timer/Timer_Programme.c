/*
 * Timer_Programme.c
 *
 * Created: 2/14/2023 6:40:30 AM
 *  Author: SONY
 */ 

#include "../../Service/BIT MATH/BIT_MATH.h"
#include "../../Service/STD/STD.h"
#include "../DIO/DIO_Interface.h"
#include "Timer_Interface.h"

void (*Time_int)(void) = NULL;


u8 Time_Init(void)
{
	//Normal Mode No Prescaller
	SET_BIT(TCCR0,0);
	//Start From 0
	//Enable OverFlow
	SET_BIT(TIMSK,0);
	return Time_OK;
}

void __vector_11(void)
{
	Time_int();
}

u8 SetTime(void (*ptr)(void))
{
	Time_int = ptr;
	if (Time_int == NULL)
	{
		return Time_SetTimeError;
	}
	return Time_OK;
}