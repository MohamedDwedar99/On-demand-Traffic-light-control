/*
 * Interrupt_Interface.h
 *
 * Created: 2/14/2023 6:41:46 AM
 *  Author: SONY
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


// External Interrupt Registers
#define MCUCR_Register	*((volatile u8*)0x55)
#define MCUCSR_Register *((volatile u8*)0x54)
#define GICR_Register	*((volatile u8*)0x5B)
#define GIFR_Register	*((volatile u8*)0x5A)

//MCUCR BITS
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

//MCUCSR BITS
#define ISC2 6

//GICR BITS
#define INT0 6
#define INT1 7
#define INT2 5

//GIFR BITS
#define INTF0 6
#define INTF1 7
#define INTF2 5

//Mode
#define LOW		0
#define CHANGE	1
#define RISING	2
#define FALLING	4

enum EXTI_Error
{
	EXTI_OK,
	EXTI_INIT_Error,
	EXTI_EnableError,
	EXTI_SENSEError,
	EXTI0_SetCallBackError
};



u8 EXTI_INIT(u8 INTNO_COPY,u8 MODE_COPY);
u8 EXTI_Enable(u8 INT_COPY);
u8 EXTI_SENSE(u8 INT_COPY,u8 MODE_COPY);

void __vector_1 (void) __attribute__((signal,used));
void __vector_2 (void) __attribute__((signal,used));
void __vector_3 (void) __attribute__((signal,used));

u8 EXTI0_SetCallBack(void (*ptr)(void));


#endif /* INTERRUPT_INTERFACE_H_ */