/*
 * fsm_manual.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Admin
 */
#include "fsm_manual.h"
/*
 * We have 3 manual state:
 * RED_ADJUST: modify red time, blink all red led every second
 * GREEN_ADJUST: modify green time, blink all green led every second
 * YELLOW_ADJUST: modify yellow time, blink all yellow led every second
 * Button1: change mode AUTO -> RED_ADJUST -> YELLOW_ADJUST -> GREEN_ADJUST
 * Button2: change time corresponding to mode
 * Button3: save time
 */
void fsm_manual_run()
{
	switch(state)
	{
	case YELLOW_ADJUST:
		yellow_blink();

		//when time_button pressed -> increase time by 1
		//when keep pressing -> increase 1 every 1 second
		//range of time is [1-30]
		if(is_button2_pressed() || is_button2_press1s()){
			temp_yellow_time = temp_yellow_time% 30000 + 1000;
			UART_Parse(temp_yellow_time);
		}

		//set_button is pressed -> save temp value
		if(is_button3_pressed()){
			yellow_time = temp_yellow_time;
		}

		//Mode_button is pressed -> turn to GREEN_ADJUST
		if(is_button1_pressed()){
			state = GREEN_ADJUST;
			green1_on();
			green2_on();
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();
		}
		break;
	case GREEN_ADJUST:
		green_blink();

		//when time_button pressed -> increase time by 1
		//when keep pressing -> increase 1 every 1 second
		//range of time is [1-30]
		if(is_button2_pressed() || is_button2_press1s()){
			temp_green_time = temp_green_time% 30000 + 1000;
			UART_Parse(temp_yellow_time);
		}

		//set_button is pressed -> save temp value
		if(is_button3_pressed()){
			green_time = temp_green_time;
		}

		//Mode_button is pressed -> turn to INIT
		if(is_button1_pressed()){
			state = INIT;
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();
		}
		break;
	case RED_ADJUST:
		red_blink();

		//when time_button pressed -> increase time by 1
		//when keep pressing -> increase 1 every 1 second
		//range of time is [1-30]
		if(is_button2_pressed() || is_button2_press1s()){
			temp_red_time = temp_red_time% 30000 + 1000;
			UART_Parse(temp_yellow_time);
		}
		//set_button is pressed -> save temp value
		if(is_button3_pressed()){
			red_time = temp_red_time;
		}

		//Mode_button is pressed -> turn to YELLOW_ADJUST
		if(is_button1_pressed()){
			state = YELLOW_ADJUST;
			yellow1_on();
			yellow2_on();
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();
		}
		break;
	default:
		break;
	}
}
