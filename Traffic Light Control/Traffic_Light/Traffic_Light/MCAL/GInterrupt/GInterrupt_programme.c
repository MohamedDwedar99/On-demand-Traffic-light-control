/*
 * GInterrupt_programme.c
 *
 * Created: 2/14/2023 6:39:39 AM
 *  Author: SONY
 */ 

#include "../../Service/BIT MATH/BIT_MATH.h"
#include "../../Service/STD/STD.h"
#include "GInterrupt_Interface.h"

u8 GInterrupt_Enable(void)
{
	SET_BIT(SREG,Global);
	return ok;
}
