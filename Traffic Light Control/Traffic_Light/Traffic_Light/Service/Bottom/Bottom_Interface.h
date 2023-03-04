/*
 * Bottom_Interface.h
 *
 * Created: 2/15/2023 1:52:31 AM
 *  Author: SONY
 */ 


#ifndef BOTTOM_INTERFACE_H_
#define BOTTOM_INTERFACE_H_

#define Car_Cross 0
#define Car_trans 1
#define Car_Stop  2

enum Bottom_Error
{
	Bottom_OK,
	Bottom_error
	}; 

u8 Bottom_Init(void);



#endif /* BOTTOM_INTERFACE_H_ */