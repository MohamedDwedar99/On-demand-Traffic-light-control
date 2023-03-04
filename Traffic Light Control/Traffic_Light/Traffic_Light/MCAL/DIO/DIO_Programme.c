/*
 * DIO_Programme.c
 *
 * Created: 2/14/2023 6:38:59 AM
 *  Author: SONY
 */ 

#include "../../Service/BIT MATH/BIT_MATH.h"
#include "../../Service/STD/STD.h"
#include "DIO_Interface.h"

u8 DIO_SetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinValCopy)
{
	if ((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		if ( u8PinValCopy == PIN_HIGH )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA: SET_BIT(PORTA_Register,u8PinIdCopy); break;
				case PORTB: SET_BIT(PORTB_Register,u8PinIdCopy); break;
				case PORTC: SET_BIT(PORTC_Register,u8PinIdCopy); break;
				case PORTD: SET_BIT(PORTD_Register,u8PinIdCopy); break;
				default : return DIO_SetPinValError; break;
			}
		}

		else if ( u8PinValCopy == PIN_LOW )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA: CLR_BIT(PORTA_Register,u8PinIdCopy); break;
				case PORTB: CLR_BIT(PORTB_Register,u8PinIdCopy); break;
				case PORTC: CLR_BIT(PORTC_Register,u8PinIdCopy); break;
				case PORTD: CLR_BIT(PORTD_Register,u8PinIdCopy); break;
				default : return DIO_SetPinValError; break;
			}
		return DIO_OK;
		}
		else
		{
			return DIO_SetPinValError;
		}
	}

}
u8 DIO_GetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy)
{
	u8 u8Valuecopy;

	if ((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		/* Check on the Required PORT Number */
		switch (u8PortIdCopy)
		{
			case PORTA: u8Valuecopy = GET_BIT(PINA_Register,u8PinIdCopy); break;
			case PORTB: u8Valuecopy = GET_BIT(PINB_Register,u8PinIdCopy); break;
			case PORTC: u8Valuecopy = GET_BIT(PINC_Register,u8PinIdCopy); break;
			case PORTD: u8Valuecopy = GET_BIT(PIND_Register,u8PinIdCopy); break;
			default : break;
		}
	}
	return u8Valuecopy;

}
u8 DIO_SetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinDirCopy)
{
	if ((u8PortIdCopy <= PORTD) && (u8PinIdCopy <= PIN7))
	{
		if ( u8PinDirCopy == PIN_OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA: SET_BIT(DDRA_Register,u8PinIdCopy); break;
				case PORTB: SET_BIT(DDRB_Register,u8PinIdCopy); break;
				case PORTC: SET_BIT(DDRC_Register,u8PinIdCopy); break;
				case PORTD: SET_BIT(DDRD_Register,u8PinIdCopy); break;
				default : return DIO_SetPinDirection; break;
			}
		}

		else if ( u8PinDirCopy == PIN_INPUT )
		{
			/* Check on the Required PORT Number */
			switch (u8PortIdCopy)
			{
				case PORTA: CLR_BIT(DDRA_Register,u8PinIdCopy); break;
				case PORTB: CLR_BIT(DDRB_Register,u8PinIdCopy); break;
				case PORTC: CLR_BIT(DDRC_Register,u8PinIdCopy); break;
				case PORTD: CLR_BIT(DDRD_Register,u8PinIdCopy); break;
				default : return DIO_SetPinDirection; break;
			}
		}

		else
		{
			return DIO_SetPinDirError;
		}
	}
	return DIO_OK;
}
