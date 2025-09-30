/*
 * software_timer.h
 *
 *  Created on: Sep 28, 2025
 *      Author: mtri1
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include <stdbool.h>

extern bool timerLED_flag;
extern bool timer1_flag;
extern bool timer2_flag;
extern bool timer3_flag;

void setTimerLED(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
