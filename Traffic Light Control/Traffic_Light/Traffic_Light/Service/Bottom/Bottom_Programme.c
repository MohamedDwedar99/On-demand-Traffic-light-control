/*
 * Bottom_Programme.c
 *
 * Created: 2/15/2023 1:52:11 AM
 *  Author: SONY
 */ 

#include "../BIT MATH/BIT_MATH.h"
#include "../STD/STD.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Bottom_Interface.h"



u8 Bottom_Init(void)
{
	DIO_SetPinDirection(PORTD,PIN2,PIN_INPUT);
	DIO_SetPinValue(PORTD,PIN2,PIN_HIGH);
	return Bottom_OK;
}


