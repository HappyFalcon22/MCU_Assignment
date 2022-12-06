/*
 * global.h
 *
 *  Created on: Nov 30, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"
#include "main.h"
#include "task.h"

extern uint32_t red_time;
extern uint32_t yellow_time;
extern uint32_t green_time;

extern uint32_t temp_red_time;
extern uint32_t temp_green_time;
extern uint32_t temp_yellow_time;

//define a fsm with 8 state
enum status{
	INIT = 0,				// initial state
	S1 = 1,					// 1 green, 2 red
	S2 = 2,					// 1 yellow, 2 red
	S3 = 4,					// 1 red, 2 green
	S4 = 5,					// 1 red, 2 yellow
	RED_ADJUST = 11,		// adjust time of red led
	YELLOW_ADJUST = 12,		// adjust time of amber led
	GREEN_ADJUST = 13		// adjust time of green led
};


extern enum status state;

#endif /* INC_GLOBAL_H_ */
