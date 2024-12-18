/*
 * software_timer.h
 *
 *  Created on: Sep 17, 2024
 *      Author: Administrator
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"
 typedef struct {
    int counter;
    int flag;
} Timer;

#define NUM_TIMERS 10 // Define the number of timers
extern Timer timers[NUM_TIMERS];
extern int timer_cycle;

extern void setTimer(int index, int duration);
void timerRun();
#endif /* INC_SOFTWARE_TIMER_H_ */

