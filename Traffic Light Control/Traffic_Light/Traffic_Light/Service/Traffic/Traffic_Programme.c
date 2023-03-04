/*
 * Traffic_Programme.c
 *
 * Created: 2/15/2023 1:58:47 AM
 *  Author: SONY
 */ 


#include "../BIT MATH/BIT_MATH.h"
#include "../STD/STD.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "Traffic_Interface.h"


u8 TRAF_Init(void)
{
	DIO_SetPinDirection(Traffic,Red,PIN_OUTPUT);
	DIO_SetPinDirection(Traffic,Yellow,PIN_OUTPUT);
	DIO_SetPinDirection(Traffic,Green,PIN_OUTPUT);
	return TRAF_OK;
}
u8 TRAF_CrossMode(void)
{
	DIO_SetPinValue(Traffic,Yellow,PIN_LOW);
	DIO_SetPinValue(Traffic,Red,PIN_LOW);
	DIO_SetPinValue(Traffic,Green,PIN_HIGH);
	return TRAF_OK;
}
u8 TRAF_TransientMode(u8 H)
{
	DIO_SetPinValue(Traffic,Green,PIN_LOW);
	DIO_SetPinValue(Traffic,Red,PIN_LOW);
	DIO_SetPinValue(Traffic,Yellow,H);
	return TRAF_OK;
}
u8 TRAF_StopMode(void)
{
	DIO_SetPinValue(Traffic,Yellow,PIN_LOW);
	DIO_SetPinValue(Traffic,Green,PIN_LOW);
	DIO_SetPinValue(Traffic,Red,PIN_HIGH);
	return TRAF_OK;
}