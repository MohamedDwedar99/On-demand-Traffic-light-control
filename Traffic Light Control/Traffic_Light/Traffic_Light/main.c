/*
 * main.c
 *
 * Created: 2/17/2023 3:54:53 AM
 *  Author: SONY
 */ 
#include "Service/BIT MATH/BIT_MATH.h"
#include "Service/STD/STD.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GInterrupt/GInterrupt_Interface.h"
#include "MCAL/Interrupt/EXTI_Interface.h"
#include "MCAL/Timer/Timer_Interface.h"
#include "Service/Bottom/Bottom_Interface.h"
#include "Service/Pedstairs/Pedstairs_Interface.h"
#include "Service/Traffic/Traffic_Interface.h"
#include "APP/app.h"

void main (void)
{
		PED_Init();
		TRAF_Init();
		Bottom_Init();
		Time_Init();
		EXTI_INIT(INT0,FALLING);
		GInterrupt_Enable();
		SetTime(Time_Sec);
		EXTI0_SetCallBack(Bottom_Tap);
		while(1)
		{
			app();
		}
}