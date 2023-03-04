/*
 * DIO_Interface.h
 *
 * Created: 2/14/2023 6:39:15 AM
 *  Author: SONY
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/* Group A Registers */
#define PORTA_Register  *((volatile u8*)0x3B)
#define DDRA_Register   *((volatile u8*)0x3A)
#define PINA_Register   *((volatile u8*)0x39)

/* Group B Registers */
#define PORTB_Register  *((volatile u8*)0x38)
#define DDRB_Register   *((volatile u8*)0x37)
#define PINB_Register   *((volatile u8*)0x36)

/* Group C Registers */
#define PORTC_Register  *((volatile u8*)0x35)
#define DDRC_Register   *((volatile u8*)0x34)
#define PINC_Register   *((volatile u8*)0x33)

/* Group D Registers */
#define PORTD_Register  *((volatile u8*)0x32)
#define DDRD_Register   *((volatile u8*)0x31)
#define PIND_Register   *((volatile u8*)0x30)


/* Port Defines */
#define PORTA    0
#define PORTB    1
#define PORTC    2
#define PORTD    3

/* PIN Defines */
#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7


/* PORT Directions */
#define PORT_INPUT  0x00
#define PORT_OUTPUT 0xff
/* PORT Value Options */
#define PORT_LOW  0x00
#define PORT_HIGH 0xff
/* PIN Directions */
#define PIN_INPUT  0
#define PIN_OUTPUT 1
/* PIN Value Options */
#define PIN_LOW  0
#define PIN_HIGH 1

/* IO Pins */
enum DIO
{
	DIO_OK,
	DIO_SetPinValError,
	DIO_SetPinDirError,
};
u8 DIO_SetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinValCopy);
u8 DIO_GetPinValue(u8 u8PortIdCopy,u8 u8PinIdCopy);
u8 DIO_SetPinDirection(u8 u8PortIdCopy,u8 u8PinIdCopy,u8 u8PinDirCopy);






#endif /* DIO_INTERFACE_H_ */