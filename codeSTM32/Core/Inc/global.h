/*
 * global.h
 *
 *  Created on: Oct 22, 2024
 *      Author: Hii
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "button.h"
#include "software_timer.h"

#define INIT 				1
#define MODE1				2
#define MODE2				3
#define MODE3				4
#define MODE4				5

#define AUTO_RED1_GREEN2	11
#define AUTO_RED1_YELLOW2	12
#define AUTO_GREEN1_RED2	13
#define	AUTO_YELLOW1_RED2	14

#define AUTO_RED			21
#define INC_RED				22

#define AUTO_YELLOW			31
#define INC_YELLOW			32

#define AUTO_GREEN			41
#define INC_GREEN			42

extern int status;

extern int RED;
extern int YELLOW;
extern int GREEN;

extern int MAX_LED;
#endif /* INC_GLOBAL_H_ */
