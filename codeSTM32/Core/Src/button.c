/*
 * button.c
 *
 *  Created on: Nov 5, 2024
 *      Author: Hii
 */


#include "button.h"

int button_flag[NUM_BUTTONS] = {0};
int buttonLongPress_flag[NUM_BUTTONS] = {0};

int KeyReg0[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NUM_BUTTONS] = {NORMAL_STATE};

int TimeOutForKeyPress[NUM_BUTTONS] = {0};

int isButtonPressed(int index){
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int index){
	button_flag[index] = 1;
}
void getKeyInput(){
	for (int i = 0; i < NUM_BUTTONS; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		if (i == 0){
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
		}
		else if (i == 1){
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
		}
		else if (i == 2){
			KeyReg2[i] = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
		}
		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE){
					subKeyProcess(i);	// Kich timer_flag[i] = 1;
					if (buttonLongPress_flag[i] == 0) {
						TimeOutForKeyPress[i] = 2000; // Set thoi gian 2s (dieu kien cho su kien longkeyPress dien ra)
					}
					else {
						TimeOutForKeyPress[i] = 250;  // Set thoi gian 0.25s (dieu kien cho nhung lan thay doi trang thai tiep theo)
					}
				}
			}
			else {
				TimeOutForKeyPress[i]--;
				// Neu sau khoang thoi gian TimeOutForKeyPress lan dau tien (2s) ma van con nhan giu button, thi buttonlong_flag[i] se bang 1, nguoc lai se bang 0
				if (TimeOutForKeyPress[i] == 0){
					KeyReg3[i] = NORMAL_STATE;
					buttonLongPress_flag[i] = 1;
				}
			}
		}
		else{
			buttonLongPress_flag[i] = 0;
		}
	}
}
