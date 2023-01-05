/*
 * buzzer.c
 *
 *  Created on: Dec 15, 2022
 *      Author: Admin
 */
#include "buzzer.h"

// Initial config
int value[2] = {START, OFF};
int delay = BASE_DELAY;
int i = 0;

void buzzerRun()
{
	int base_time = red_time;
	int a = (BASE_DELAY - LAST_DELAY) / base_time;
	int b = LAST_DELAY;
	int c = (BASE_VALUE - LAST_VALUE) / base_time;
	int d = LAST_VALUE;
	if (timer4_flag == 1)
	{
		setTimer4(delay);
		__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, value[i]);
		i = (i + 1) % 2;
		// This is the equation with desired coefficients
		delay = a * SEG_counter + b;
		value[0] = c * SEG_counter + d;
	}
	// Delete this
}
