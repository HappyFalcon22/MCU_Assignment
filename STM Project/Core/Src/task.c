#include "task.h"
#include "software_timer.h"

//toggle all led when timer flag is on
//the set up pin is depend on real board
//in this case:
//	A	B
//	0	0	off
//	0	1	green
//	1	0	red
//	1	1	yellow
void green_blink()
{
	if(timer3_flag == 1){
		setTimer3(BLINK_TIME);
		HAL_GPIO_TogglePin(LIGHT1_B_GPIO_Port, LIGHT1_B_Pin);
		HAL_GPIO_TogglePin(LIGHT2_B_GPIO_Port, LIGHT2_B_Pin);
	}
}
void red_blink()
{
	if(timer3_flag == 1){
		setTimer3(BLINK_TIME);
		HAL_GPIO_TogglePin(LIGHT1_A_GPIO_Port, LIGHT1_A_Pin);
		HAL_GPIO_TogglePin(LIGHT2_A_GPIO_Port, LIGHT2_A_Pin);
	}
}

void yellow_blink()
{
	if(timer3_flag == 1){
		setTimer3(BLINK_TIME);
		HAL_GPIO_TogglePin(LIGHT1_B_GPIO_Port, LIGHT1_B_Pin);
		HAL_GPIO_TogglePin(LIGHT2_B_GPIO_Port, LIGHT2_B_Pin);
		HAL_GPIO_TogglePin(LIGHT1_A_GPIO_Port, LIGHT1_A_Pin);
		HAL_GPIO_TogglePin(LIGHT2_A_GPIO_Port, LIGHT2_A_Pin);
	}
}

//turn the led corresponding to this road on
void red1_on()
{
	HAL_GPIO_WritePin(LIGHT1_A_GPIO_Port, LIGHT1_A_Pin, SET);
	HAL_GPIO_WritePin(LIGHT1_B_GPIO_Port, LIGHT1_B_Pin, RESET);
}
void red2_on()
{
	HAL_GPIO_WritePin(LIGHT2_A_GPIO_Port, LIGHT2_A_Pin, SET);
	HAL_GPIO_WritePin(LIGHT2_B_GPIO_Port, LIGHT2_B_Pin, RESET);
}
void green1_on()
{
	HAL_GPIO_WritePin(LIGHT1_A_GPIO_Port, LIGHT1_A_Pin, RESET);
	HAL_GPIO_WritePin(LIGHT1_B_GPIO_Port, LIGHT1_B_Pin, SET);
}
void green2_on()
{
	HAL_GPIO_WritePin(LIGHT2_A_GPIO_Port, LIGHT2_A_Pin, RESET);
	HAL_GPIO_WritePin(LIGHT2_B_GPIO_Port, LIGHT2_B_Pin, SET);
}
void yellow1_on()
{
	HAL_GPIO_WritePin(LIGHT1_A_GPIO_Port, LIGHT1_A_Pin, SET);
	HAL_GPIO_WritePin(LIGHT1_B_GPIO_Port, LIGHT1_B_Pin, SET);
}
void yellow2_on()
{
	HAL_GPIO_WritePin(LIGHT2_A_GPIO_Port, LIGHT2_A_Pin, SET);
	HAL_GPIO_WritePin(LIGHT2_B_GPIO_Port, LIGHT2_B_Pin, SET);
}

// Add task for pedestrian light (synchronized with Light_1)
void red_pedes_on()
{
	HAL_GPIO_WritePin(PEDE_LIGHT_A_GPIO_Port, PEDE_LIGHT_A_Pin, SET);
	HAL_GPIO_WritePin(PEDE_LIGHT_B_GPIO_Port, PEDE_LIGHT_B_Pin, RESET);
}

void green_pedes_on()
{
	HAL_GPIO_WritePin(PEDE_LIGHT_A_GPIO_Port, PEDE_LIGHT_A_Pin, RESET);
	HAL_GPIO_WritePin(PEDE_LIGHT_B_GPIO_Port, PEDE_LIGHT_B_Pin, SET);
}


//this function is used when error detected
void turn_all_led_off()
{
	HAL_GPIO_WritePin(LIGHT1_A_GPIO_Port, LIGHT1_A_Pin, RESET);
	HAL_GPIO_WritePin(LIGHT1_B_GPIO_Port, LIGHT1_B_Pin, RESET);
	HAL_GPIO_WritePin(LIGHT2_A_GPIO_Port, LIGHT2_A_Pin, RESET);
	HAL_GPIO_WritePin(LIGHT2_B_GPIO_Port, LIGHT2_B_Pin, RESET);
}

// Add task for UART
void UART_Parse(uint32_t time)
{
	char str[15];
	sprintf(str, "!7SEG:%d#\r\n", time);
	HAL_UART_Transmit(&huart2, str, sizeof(str), 1000);
}

