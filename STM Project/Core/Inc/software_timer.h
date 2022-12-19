/*
 * software_timer.h
 *
 *  Created on: Nov 30, 2022
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"
#include "main.h"

#define BLINK_TIME 1000

extern int timer1_flag; // For road1
extern int timer2_flag;	// For road2
extern int timer3_flag;	// For blinky LED in MANUAL
extern int timer4_flag; // For the buzzer
extern int timer5_flag; // For

void timerRun();

void setTimer1(uint32_t duration);
void setTimer2(uint32_t duration);
void setTimer3(uint32_t duration);
void setTimer4(uint32_t duration);
void setTimer5(uint32_t duration);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);


#endif /* INC_SOFTWARE_TIMER_H_ */
