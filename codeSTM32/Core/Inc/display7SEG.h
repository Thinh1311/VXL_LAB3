/*
 * display7SEG.h
 *
 *  Created on: Oct 22, 2024
 *      Author: Hii
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "main.h"
#include "global.h"
extern int num;
extern int index_led;
extern int counter_lane1, counter_lane2;
void display7SEG(int num);
void update7SEG(int index);

void updateClockBufferMode1();
void updateClockBufferMode2();
void updateClockBufferMode3();
void updateClockBufferMode4();
#endif /* INC_DISPLAY7SEG_H_ */
