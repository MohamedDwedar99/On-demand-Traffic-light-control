/*
 * Traffic_Interface.h
 *
 * Created: 2/15/2023 1:59:07 AM
 *  Author: SONY
 */ 


#ifndef TRAFFIC_INTERFACE_H_
#define TRAFFIC_INTERFACE_H_

#define Green	0
#define Yellow	1
#define Red		2

#define Traffic PORTA

enum TRAF_ERROR
{
	TRAF_OK,
	TRAF_CrossModeError,
	TRAF_TransientModeError,
	TRAF_StopModeError
}TRAF_ERROR;

u8 TRAF_Init(void);
u8 TRAF_CrossMode(void);
u8 TRAF_TransientMode(u8 H);
u8 TRAF_StopMode(void);



#endif /* TRAFFIC_INTERFACE_H_ */