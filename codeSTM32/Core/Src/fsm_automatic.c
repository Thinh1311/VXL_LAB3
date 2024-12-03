/*
 * fsm_automatic.c
 *
 *  Created on: Nov 5, 2024
 *      Author: Hii
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
		case INIT:
			status = MODE1;
			break;
		case MODE1:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);

			updateClockBufferMode1();

			setTimer0(GREEN * 1000);
			setTimer1(1000);
			setTimer2(250);
			clearTimer(3);

			status = AUTO_RED1_GREEN2;

			break;
		case AUTO_RED1_GREEN2:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
			if(timer0_flag == 1){
				status = AUTO_RED1_YELLOW2;
				setTimer0(YELLOW * 1000);
			}
			if(timer1_flag == 1){
				updateClockBufferMode1();
				setTimer1(1000);
			}
			if(timer2_flag == 1){
				update7SEG(index_led++);
				if(index_led >= MAX_LED) index_led = 0;
				setTimer2(250);
			}
			if(isButtonPressed(0) == 1){
				status = MODE2;
			}
			clearTimer(3);
			break;
		case AUTO_RED1_YELLOW2:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_RESET);

			if(timer0_flag == 1){
				status = AUTO_GREEN1_RED2;
				setTimer0(GREEN * 1000);
			}
			if(timer1_flag == 1){
				updateClockBufferMode1();
				setTimer1(1000);
			}
			if(timer2_flag == 1){
				update7SEG(index_led++);
				if(index_led >= MAX_LED) index_led = 0;
				setTimer2(250);
			}
			if(isButtonPressed(0) == 1){
				status = MODE2;
			}
			break;
		case AUTO_GREEN1_RED2:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);

			if(timer0_flag == 1){
				status = AUTO_YELLOW1_RED2;
				setTimer0(YELLOW * 1000);
			}
			if(timer1_flag == 1){
				updateClockBufferMode1();
				setTimer1(1000);
			}
			if(timer2_flag == 1){
				update7SEG(index_led++);
				if(index_led >= MAX_LED) index_led = 0;
				setTimer2(250);
			}
			if(isButtonPressed(0) == 1){
				status = MODE2;
			}
			break;
		case AUTO_YELLOW1_RED2:
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);

			if(timer0_flag == 1){
				status = AUTO_RED1_GREEN2;
				setTimer0(GREEN * 1000);
			}
			if(timer1_flag == 1){
				updateClockBufferMode1();
				setTimer1(1000);
			}
			if(timer2_flag == 1){
				update7SEG(index_led++);
				if(index_led >= MAX_LED) index_led = 0;
				setTimer2(250);
			}
			if(isButtonPressed(0) == 1){
				status = MODE2;
			}
			break;
		default:
			break;
	}
}
