/*
 * global.c
 *
 *  Created on: Nov 30, 2022
 *      Author: Admin
 */
#include "global.h"

// time of 3 led (ms)
uint32_t red_time = 10000;
uint32_t green_time = 7000;
uint32_t yellow_time = 3000;

// temporary time of 3 led
// use in adjusting mode
// when set_button is pressed, this value is copy to real time above
uint32_t temp_red_time = 1000;
uint32_t temp_green_time = 1000;
uint32_t temp_yellow_time = 1000;

// Declare the counter to red_time
uint32_t SEG_counter = 10; // Initial time of red_time

//state use in fsm
enum status state = INIT;

// UART Callback declare
uint8_t temp = 0;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART2)
	{
		HAL_UART_Transmit(&huart2, &temp, 1, 50);
		HAL_UART_Receive_IT(&huart2, &temp, 1);
	}
}


