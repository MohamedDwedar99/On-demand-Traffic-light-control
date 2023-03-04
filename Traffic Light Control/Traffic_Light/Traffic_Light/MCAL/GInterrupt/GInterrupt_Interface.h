/*
 * GInterrupt_Interface.h
 *
 * Created: 2/14/2023 6:40:04 AM
 *  Author: SONY
 */ 


#ifndef GINTERRUPT_INTERFACE_H_
#define GINTERRUPT_INTERFACE_H_


#define SREG  *((volatile u8 *)(0x5F))
#define Global 7


u8 GInterrupt_Enable(void);



#endif /* GINTERRUPT_INTERFACE_H_ */