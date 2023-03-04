/*
 * Pedstairs_Interface.h
 *
 * Created: 2/15/2023 1:57:38 AM
 *  Author: SONY
 */ 


#ifndef PEDSTAIRS_INTERFACE_H_
#define PEDSTAIRS_INTERFACE_H_

#define Green	0
#define Yellow	1
#define Red		2

#define Pedstairs PORTB


enum PED_ERROR
{
	PED_OK,
	PED_CrossModeError,
	PED_TransientModeError,
	PED_StopModeError
};

u8 PED_Init(void);
u8 PED_CrossMode(void);
u8 PED_TransientMode(u8 H);
u8 PED_StopMode(void);


#endif /* PEDSTAIRS_INTERFACE_H_ */