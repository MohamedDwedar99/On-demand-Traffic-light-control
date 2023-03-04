/*
 * app.h
 *
 * Created: 2/17/2023 3:53:51 AM
 *  Author: SONY
 */ 


#ifndef APP_H_
#define APP_H_

enum AppError
{
	APP_OK,
	APP_Error,
	TimeSecError,
	Bottom_TapError
	};

u8 app(void);
u8 Time_Sec(void);
u8 Bottom_Tap(void);


#endif /* APP_H_ */