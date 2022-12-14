/*
 * fsm_auto.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Admin
 */
#include "fsm_auto.h"

/*
 * We have 4 automatic state: S1 -> S2 -> S3 -> S4 -> S1 ->...
 * 			and an INIT state for initial and checking error
 * S1: road1 green, road2 red
 * S2: road1 yellow, road2 red
 * S3: road1 red, road2 green
 * S4: road1 red, road2 yellow
 * INIT: check error and initiate timer
 *
 * Timer1: control time of road1
 * Timer2: control time of road2
 */
void fsm_automatic_run()
{
	switch(state)
	{
	case INIT:
		if(yellow_time + green_time != red_time){
			//error state
			//trap here until mode_button is pressed
			//and go to RED_ADJUST mode to change value again
			turn_all_led_off();
			if(is_button1_pressed()){
				state = RED_ADJUST;
				//reset all button flag
				is_button2_pressed();
				is_button3_pressed();
			}
			break;
		}
		//no error, prepare for changing to S1
		setTimer1(green_time);
		setTimer2(red_time);
		setTimer3(BLINK_TIME);
		state = S1;
		break;
	case S1:
		green1_on();
		red2_on();

		//road1 timeout -> turn to state S2
		if(timer1_flag == 1){
			setTimer1(yellow_time);
			state = S2;
		}

		//Mode_button is pressed -> turn to manual: RED_ADJUST
		if(is_button1_pressed()){
			state = RED_ADJUST;
			red1_on();
			red2_on();
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();
		}
		break;
	case S2:
		yellow1_on();
		red2_on();

		//road1 timeout -> turn to state S3
		if(timer1_flag == 1){
			setTimer1(red_time);
			setTimer2(green_time);
			state = S3;
		}

		//Mode_button is pressed -> turn to RED_ADJUST
		if(is_button1_pressed()){
			state = RED_ADJUST;
			red1_on();
			red2_on();
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();
		}
		break;
	case S3:
		red1_on();
		green2_on();

		//road2 timeout -> turn to state S4
		if(timer2_flag == 1){
			setTimer2(yellow_time);
			state = S4;
		}

		//Mode_button is pressed -> turn to manual RED_ADJUST
		if(is_button1_pressed()){
			state = RED_ADJUST;
			red1_on();
			red2_on();
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();
		}
		break;
	case S4:
		red1_on();
		yellow2_on();

		//road2 timeout -> turn to state S4
		if(timer2_flag == 1){
			setTimer1(green_time);
			setTimer2(red_time);
			state = S4;
		}
		//Mode_button is pressed -> turn to manual RED_ADJUST
		if(is_button1_pressed()){
			state = RED_ADJUST;
			red1_on();
			red2_on();
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();
		}
		break;
	default:
		break;
	}
}
