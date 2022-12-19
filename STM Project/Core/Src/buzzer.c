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

// Set a linear equation for the speed of the buzzer
// Take 2 points : (time, delay) = {(BASE_TIME, BASE_DELAY); (0, LAST_DELAY)}
// Built the coefficients a, b of : y = ax + b

const int a = (BASE_DELAY - LAST_DELAY) / BASE_TIME;
const int b = LAST_DELAY;

// Set a linear equation for the volume of the buzzer
// Take 2 points : (time, delay) = ((BASE_TIME, BASE_VALUE); (0, LAST_VALUE))
// Built the coefficients c, d of : y = cx + d

const int c = (BASE_VALUE - LAST_VALUE) / BASE_TIME;
const int d = LAST_VALUE;

void buzzerRun()
{

	green_pedes_on();
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
