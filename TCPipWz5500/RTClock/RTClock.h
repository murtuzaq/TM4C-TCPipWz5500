/*
 * RTClock.h
 *
 *  Created on: Sep 10, 2016
 *      Author: Murtuza
 */

#ifdef __cplusplus
extern "C" {
#endif


#ifndef RTCLOCK_RTCLOCK_H_
#define RTCLOCK_RTCLOCK_H_



extern void Timer1_Callback(void);
extern void Timer_ms_Init(void);
extern void Timer_ms(void);
extern unsigned long millis(void);


#endif /* RTCLOCK_RTCLOCK_H_ */

#ifdef __cplusplus
}
#endif

