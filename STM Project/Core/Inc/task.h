/*
 * task.h
 *
 *  Created on: 30 Nov 2022
 *      Author: DLCH
 */

#ifndef INC_TASK_H_
#define INC_TASK_H_

#include "global.h"

void green_blink();
void red_blink();
void yellow_blink();

void red1_on();
void red2_on();
void green1_on();
void green2_on();
void yellow1_on();
void yellow2_on();

// Light for pedestrians
void red_pedes_on();
void green_pedes_on();


// UART transmission of count-down time
void UART_Parse(uint32_t time);

void turn_all_led_off();
#endif /* INC_TASK_H_ */
