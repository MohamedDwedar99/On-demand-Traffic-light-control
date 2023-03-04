/*
 * Traffic_Light.c
 *
 * Created: 2/14/2023 6:28:38 AM
 * Author : SONY
 */ 


#include "../Service/BIT MATH/BIT_MATH.h"
#include "../Service/STD/STD.h"
#include "../Service/Bottom/Bottom_Interface.h"
#include "../Service/Pedstairs/Pedstairs_Interface.h"
#include "../Service/Traffic/Traffic_Interface.h"
#include "app.h"

#define Ped_trans 3

u8  time_sec;
u32 x = 0;
u8 volatile B_Case = 0;

u8 app(void)
{
	switch (B_Case)
	{
		case Car_Cross:
			PED_StopMode();
			TRAF_CrossMode();
			break;
		case Car_trans:
			if (time_sec%2 != 1)
			{
				PED_TransientMode(1);
				TRAF_TransientMode(1);
			}
			else
			{
				PED_TransientMode(0);
				TRAF_TransientMode(0);
			}
			break;
			case Car_Stop:
				PED_CrossMode();
				TRAF_StopMode();
				break;
			case Ped_trans:
				if (time_sec%2 != 1)
				{
					PED_TransientMode(1);
					TRAF_TransientMode(1);
				}
				else
				{
					PED_TransientMode(0);
					TRAF_TransientMode(0);
				}
			break;
			default: return APP_Error;
		}
		if (time_sec >= 5)
		{
			time_sec = 0;
			B_Case++;
			if (B_Case == 4)
			{
				B_Case = 0;
			}
		}
		return APP_OK;
}

u8 Time_Sec(void)
{
	x++;
	if (x ==3906)
	{
		time_sec++;
		x = 0;
		return APP_OK;
	}
	return TimeSecError;
}

u8 Bottom_Tap(void)
{
	switch (B_Case)
	{
		case Car_Cross:B_Case = 1;break;
		case Car_trans:break; //do nothing
		case Car_Stop:break;	//do nothing
		default: return Bottom_TapError;
	}
	return Bottom_OK;
}