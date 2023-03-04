/*
 * Interrupt_Programme.c
 *
 * Created: 2/14/2023 6:41:28 AM
 *  Author: SONY
 */ 

#include "../../Service/BIT MATH/BIT_MATH.h"
#include "../../Service/STD/STD.h"
#include "../GInterrupt/GInterrupt_Interface.h"
#include "../DIO/DIO_Interface.h"
#include "EXTI_Interface.h"

void (*EXTI0_CallBack)(void) = NULL;
void (*EXTI1_CallBack)(void) = NULL;
void (*EXTI2_CallBack)(void) = NULL;



u8 EXTI_INIT(u8 INTN_COPY,u8 MODE_COPY)
{
	GInterrupt_Enable();
	switch (INTN_COPY)
	{
		case INT0:
		DIO_SetPinDirection(PORTD,PIN2,PIN_INPUT);
		switch (MODE_COPY)
		{
			case RISING:
			DIO_SetPinValue(PORTD,PIN2,PIN_HIGH);
			EXTI_SENSE(INTN_COPY,RISING);
			EXTI_Enable(INTN_COPY);
			return EXTI_OK;
			break;
			case FALLING:
			DIO_SetPinValue(PORTD,PIN2,PIN_HIGH);
			EXTI_SENSE(INTN_COPY,FALLING);
			EXTI_Enable(INTN_COPY);
			return EXTI_OK;
			break;
			case CHANGE:
			DIO_SetPinValue(PORTD,PIN2,PIN_LOW);
			EXTI_SENSE(INTN_COPY,CHANGE);
			EXTI_Enable(INTN_COPY);
			return EXTI_OK;
			break;
			case LOW:
			DIO_SetPinValue(PORTD,PIN2,PIN_HIGH);
			EXTI_SENSE(INTN_COPY,FALLING);
			EXTI_Enable(INTN_COPY);
			return EXTI_OK;
			break;
		}
		return EXTI_INIT_Error;
		break;
		case INT1:
		DIO_SetPinDirection(PORTD,PIN3,PIN_INPUT);
		switch (MODE_COPY)
		{
			case RISING:
			DIO_SetPinValue(PORTD,PIN3,PIN_HIGH);
			EXTI_SENSE(INTN_COPY,RISING);
			EXTI_Enable(INTN_COPY);
			return EXTI_OK;
			break;
			case FALLING:
			DIO_SetPinValue(PORTD,PIN3,PIN_HIGH);
			EXTI_SENSE(INTN_COPY,FALLING);
			EXTI_Enable(INTN_COPY);
			return EXTI_OK;
			break;
			case CHANGE:
			DIO_SetPinValue(PORTD,PIN3,PIN_LOW);
			EXTI_SENSE(INTN_COPY,CHANGE);
			EXTI_Enable(INTN_COPY);
			return EXTI_OK;
			break;
			case LOW:
			DIO_SetPinValue(PORTD,PIN3,PIN_HIGH);
			EXTI_SENSE(INTN_COPY,FALLING);
			EXTI_Enable(INTN_COPY);
			return EXTI_OK;
			break;
		}
		return EXTI_INIT_Error;
		break;
		case INT2:
		DIO_SetPinDirection(PORTB,PIN2,PIN_INPUT);
		switch (MODE_COPY)
		{
			case RISING:
			DIO_SetPinValue(PORTD,PIN3,PIN_HIGH);
			EXTI_SENSE(INTN_COPY,RISING);
			EXTI_Enable(INTN_COPY);
			return EXTI_OK;
			break;
			case FALLING:
			DIO_SetPinValue(PORTD,PIN3,PIN_HIGH);
			EXTI_SENSE(INTN_COPY,FALLING);
			EXTI_Enable(INTN_COPY);
			return EXTI_OK;
			break;
		}
		return EXTI_INIT_Error;
		break;
	}
	return EXTI_INIT_Error;
}
u8 EXTI_Enable(u8 INT_COPY)
{
	switch (INT_COPY)
	{
		case INT0:
		SET_BIT(GICR_Register,INT0);
		return EXTI_OK;
		break;
		case INT1:
		SET_BIT(GICR_Register,INT1);
		return EXTI_OK;
		break;
		case INT2:
		SET_BIT(GICR_Register,INT2);
		return EXTI_OK;
		break;
	}
	return EXTI_EnableError;
}
u8 EXTI_SENSE(u8 INT_COPY,u8 MODE_COPY)
{
	switch (INT_COPY)
	{
		case INT0:
		switch (MODE_COPY)
		{
			case LOW:
			CLR_BIT(MCUCR_Register,ISC00);
			CLR_BIT(MCUCR_Register,ISC01);
			return EXTI_OK;
			break;
			case CHANGE:
			SET_BIT(MCUCR_Register,ISC00);
			CLR_BIT(MCUCR_Register,ISC01);
			return EXTI_OK;
			break;
			case FALLING:
			CLR_BIT(MCUCR_Register,ISC00);
			SET_BIT(MCUCR_Register,ISC01);
			return EXTI_OK;
			break;
			case RISING:
			SET_BIT(MCUCR_Register,ISC00);
			SET_BIT(MCUCR_Register,ISC01);
			return EXTI_OK;
			break;
		}
		return EXTI_SENSEError;
		break;
		case INT1:
		switch (MODE_COPY)
		{
			case LOW:
			CLR_BIT(MCUCR_Register,ISC10);
			CLR_BIT(MCUCR_Register,ISC11);
			return EXTI_OK;
			break;
			case CHANGE:
			SET_BIT(MCUCR_Register,ISC10);
			CLR_BIT(MCUCR_Register,ISC11);
			return EXTI_OK;
			break;
			case FALLING:
			CLR_BIT(MCUCR_Register,ISC10);
			SET_BIT(MCUCR_Register,ISC11);
			return EXTI_OK;
			break;
			case RISING:
			SET_BIT(MCUCR_Register,ISC10);
			SET_BIT(MCUCR_Register,ISC11);
			return EXTI_OK;
			break;
		}
		return EXTI_SENSEError;
		break;
		case INT2:
		switch (MODE_COPY)
		{
			case RISING:
			SET_BIT(MCUCR_Register,ISC2);
			return EXTI_OK;
			break;
			case FALLING:
			CLR_BIT(MCUCR_Register,ISC2);
			return EXTI_OK;
			break;
		}
		return EXTI_SENSEError;
		break;
	}
	return EXTI_SENSEError;
}
u8 EXTI0_SetCallBack(void (*ptr)(void))
{
	EXTI0_CallBack = ptr;
	if (EXTI0_CallBack == NULL)
	{
		return EXTI0_SetCallBackError;
	}
	return EXTI_OK;
}

void __vector_1(void)
{
	EXTI0_CallBack();
}
void __vector_2 (void)
{
	EXTI1_CallBack;
}
void __vector_3 (void)
{
	EXTI2_CallBack;
}