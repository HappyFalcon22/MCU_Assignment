/*
 * buzzer.h
 *
 *  Created on: Dec 15, 2022
 *      Author: Admin
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "main.h"
#include "software_timer.h"
#include "global.h"

#define	START	100
#define	OFF		0
#define BASE_TIME	10
#define BASE_DELAY	5000
#define LAST_DELAY	200

extern int value[2];
extern int step;
extern int delay;
extern TIM_HandleTypeDef htim3;

void buzzerRun();
void timer();


#endif /* INC_BUZZER_H_ */
