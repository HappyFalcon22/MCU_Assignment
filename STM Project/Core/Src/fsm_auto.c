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
 * Timer3: count down for uart in auto
 */
int buzz_flag = 0;
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
				red1_on();
				red2_on();
				//display temp time
				SEG_counter = temp_red_time/1000;
				UART_Parse();
				//reset all button flag
				is_button2_pressed();
				is_button3_pressed();
			}
			break;
		}
		//no error, prepare for changing to S1

		//send time via uart
		SEG_counter = green_time/1000;
		UART_Parse();

		setTimer4(1000);// Init the counter
		setTimer1(green_time);
		setTimer2(red_time);
		setTimer3(1000);
		state = S1;
		break;
	case S1:
		buzz_flag = 0;
		green1_on();
		red2_on();
		//uart count down
		if(timer3_flag == 1){
			SEG_counter--;
			UART_Parse();
			setTimer3(1000);
		}

		//road1 timeout -> turn to state S2
		if(timer1_flag == 1){
			setTimer1(yellow_time);
			state = S2;
			SEG_counter = yellow_time/1000;
			UART_Parse();
			setTimer3(1000);
		}

		//Mode_button is pressed -> turn to manual: RED_ADJUST
		if(is_button1_pressed()){
			state = RED_ADJUST;
			red1_on();
			red2_on();
			//display temp time
			SEG_counter = temp_red_time/1000;
			UART_Parse();
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();

			// Turn off buzzer and light
			turn_pedes_off();
			mode_flag = 0;
		}

		// Pedes light
		if (is_pede_button_pressed())
		{
			if (mode_flag == 0)
				mode_flag = 1;
			setTimer5(SEG_counter * 1000 + red_time);
		}

		if (mode_flag == 1)
		{
			red_pedes_on();
		}

		if (timer5_flag == 1)
		{
			turn_pedes_off();
			mode_flag = 0;
		}
		break;
	case S2:
		buzz_flag = 0;
		yellow1_on();
		red2_on();

		//uart count down
		if(timer3_flag == 1){
			SEG_counter--;
			UART_Parse();
			setTimer3(1000);
		}

		//road1 timeout -> turn to state S3
		if(timer1_flag == 1){
			setTimer1(red_time);
			setTimer2(green_time);
			state = S3;

			SEG_counter = red_time/1000;
			UART_Parse();
			setTimer3(1000);
		}


		//Mode_button is pressed -> turn to RED_ADJUST
		if(is_button1_pressed()){
			state = RED_ADJUST;
			red1_on();
			red2_on();
			//display temp time
			SEG_counter = temp_red_time/1000;
			UART_Parse();
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();

			// Turn off buzzer and light
			turn_pedes_off();
			mode_flag = 0;
		}

		// Pedes light
		if (is_pede_button_pressed())
		{
			if (mode_flag == 0)
				mode_flag = 1;
			setTimer5(SEG_counter * 1000 + red_time);
		}

		if (mode_flag == 1)
		{
			red_pedes_on();
		}

		if (timer5_flag == 1)
		{
			turn_pedes_off();
			mode_flag = 0;
		}

		break;
	case S3:
		buzz_flag = 1;
		red1_on();
		green2_on();

		//uart count down
		if(timer3_flag == 1){
			SEG_counter--;
			UART_Parse();
			setTimer3(1000);
		}

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
			//display temp time
			SEG_counter = temp_red_time/1000;
			UART_Parse();
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();

			// Turn off buzzer and light
			turn_pedes_off();
			mode_flag = 0;
		}

		// Pedes light
		if (is_pede_button_pressed())
		{
			if (mode_flag == 0)
				mode_flag = 1;
			setTimer5(SEG_counter * 1000 + 2 * red_time);
		}

		if (mode_flag == 1)
		{
			green_pedes_on();
		}

		if ((mode_flag == 1) && (buzz_flag == 1))
		{
			buzzerRun();
		}
		// Timeout
		if (timer5_flag == 1)
		{
			turn_pedes_off();
			mode_flag = 0;
		}

		break;
	case S4:
		buzz_flag = 1;
		red1_on();
		yellow2_on();

		//uart count down
		if(timer3_flag == 1){
			SEG_counter--;
			UART_Parse();
			setTimer3(1000);
		}

		//road2 timeout -> turn to state S1
		if(timer2_flag == 1){
			setTimer1(green_time);
			setTimer2(red_time);
			state = S1;

			// Turn off pedes light
			HAL_GPIO_WritePin(PEDE_LIGHT_A_GPIO_Port, PEDE_LIGHT_A_Pin, RESET);
			HAL_GPIO_WritePin(PEDE_LIGHT_B_GPIO_Port, PEDE_LIGHT_B_Pin, RESET);

			SEG_counter = green_time/1000;
			UART_Parse();
			setTimer3(1000);
		}

		//Mode_button is pressed -> turn to manual RED_ADJUST
		if(is_button1_pressed()){
			state = RED_ADJUST;
			red1_on();
			red2_on();
			//display temp time
			SEG_counter = temp_red_time/1000;
			UART_Parse();
			//reset all button flag
			is_button2_pressed();
			is_button3_pressed();

			// Turn off buzzer and light
			turn_pedes_off();
			mode_flag = 0;
		}

		// Pedes light
		if (is_pede_button_pressed())
		{
			if (mode_flag == 0)
				mode_flag = 1;
			setTimer5(SEG_counter * 1000 + 2 * red_time);
		}
		if (mode_flag == 1)
		{
			green_pedes_on();
		}

		if ((mode_flag == 1) && (buzz_flag == 1))
		{
			buzzerRun();
		}
		// Timeout
		if (timer5_flag == 1)
		{
			turn_pedes_off();
			mode_flag = 0;
		}
		break;
	default:
		break;
	}
}
