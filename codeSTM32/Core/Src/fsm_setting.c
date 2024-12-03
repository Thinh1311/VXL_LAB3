/*
 * fsm_setting.c
 *
 *  Created on: Dec 2, 2024
 *      Author: Hii
 */


#include "fsm_setting.h"

void fsm_setting_run(){
	switch(status){
	case MODE2:
		clearTimer(0);
		clearTimer(1);
		setTimer2(250);
		setTimer3(500);
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);
		status = INC_RED;
		break;
	case INC_RED:
		if(timer2_flag == 1){
			updateClockBufferMode2();
			update7SEG(index_led++);
			if(index_led >= MAX_LED) index_led = 0;
			setTimer2(250);
		}
		if(timer3_flag == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			setTimer3(500);
		}
		if (isButtonPressed(0) == 1) {
			status = MODE3;
		}
		if(isButtonPressed(1) == 1){
			if(RED < 99){
				RED++;
			}
			else{
				RED = YELLOW + 1;
			}
		}
		if(isButtonPressed(2) == 1){
			if(RED <= YELLOW){
			     RED = YELLOW + 1;
			}
			GREEN = RED - YELLOW;
			clearTimer(3);
			setTimer0(GREEN * 1000);
			setTimer1(1000);
			setTimer2(250);
			status = AUTO_RED1_GREEN2;
		}
		break;
	case MODE3:
		clearTimer(0);
		clearTimer(1);
		setTimer2(250);
		setTimer3(500);
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_RESET);

		status = INC_YELLOW;
		break;
	case INC_YELLOW:
		if(timer2_flag == 1){
			update7SEG(index_led++);
			updateClockBufferMode3();
			if(index_led >= MAX_LED) index_led = 0;
			setTimer2(250);
		}
		if(timer3_flag == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			setTimer3(500);
		}
		if(isButtonPressed(0) == 1){
			status = MODE4;
		}
		if(isButtonPressed(1) == 1){
			if(YELLOW < 99 && YELLOW < RED - 1) {
				YELLOW++;
			} else {
			    YELLOW = 1;
			}
		}
		if(isButtonPressed(2) == 1){
			if (RED <= YELLOW) RED = YELLOW + 1;
			GREEN = RED - YELLOW;
			clearTimer(3);
			setTimer0(GREEN * 1000);
			setTimer1(1000);
			setTimer2(250);
			status = AUTO_RED1_GREEN2;
		}
		break;
	case MODE4:
		clearTimer(0);
		clearTimer(1);
		setTimer2(250);
		setTimer3(500);
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);

		HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, GPIO_PIN_SET);

		status = INC_GREEN;
		break;
	case INC_GREEN:
		if(timer2_flag == 1){
			update7SEG(index_led++);
			updateClockBufferMode4();
			if(index_led >= MAX_LED) index_led = 0;
			setTimer2(250);
		}
		if(timer3_flag == 1){
			HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
			setTimer3(500);
		}
		if(isButtonPressed(0) == 1){
			status = MODE1;
		}
		if(isButtonPressed(1) == 1){
			if (GREEN < 99 && GREEN < RED - 1){
				GREEN++;
			}
			else{
				GREEN = 1;
			}
		}
		if(isButtonPressed(2) == 1){
			RED = GREEN + YELLOW;
			clearTimer(3);
			setTimer0(GREEN * 1000);
			setTimer1(1000);
			setTimer2(250);
			status = AUTO_RED1_GREEN2;
		}
		break;
	default:
		break;
	}
}
