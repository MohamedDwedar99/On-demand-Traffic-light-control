/*
 * Pedstairs_Programme.c
 *
 * Created: 2/15/2023 1:58:04 AM
 *  Author: SONY
 */ 

#include "../BIT MATH/BIT_MATH.h"
#include "../STD/STD.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/Timer/Timer_Interface.h"
#include "Pedstairs_Interface.h"


u8 PED_Init(void)
{
	DIO_SetPinDirection(Pedstairs,Red,PIN_OUTPUT);
	DIO_SetPinDirection(Pedstairs,Yellow,PIN_OUTPUT);
	DIO_SetPinDirection(Pedstairs,Green,PIN_OUTPUT);
	return PED_OK;
}
u8 PED_CrossMode(void)
{
	DIO_SetPinValue(Pedstairs,Yellow,PIN_LOW);
	DIO_SetPinValue(Pedstairs,Red,PIN_LOW);
	DIO_SetPinValue(Pedstairs,Green,PIN_HIGH);
	return PED_OK;
}
u8 PED_TransientMode(u8 H)
{
	DIO_SetPinValue(Pedstairs,Green,PIN_LOW);
	DIO_SetPinValue(Pedstairs,Red,PIN_LOW);
	DIO_SetPinValue(Pedstairs,Yellow,H);
	return PED_OK;
}
u8 PED_StopMode(void)
{
	DIO_SetPinValue(Pedstairs,Yellow,PIN_LOW);
	DIO_SetPinValue(Pedstairs,Green,PIN_LOW);
	DIO_SetPinValue(Pedstairs,Red,PIN_HIGH);
	return PED_OK;
}