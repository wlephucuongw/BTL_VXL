/*
 * traffic_light.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Administrator
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "global.h"

void init();
void auto_green_red();
void auto_amber_red();
void auto_red_green();
void auto_red_amber();
void modify_red_led();
void modify_green_led();
void modify_amber_led();
void clear_all_led();
void manual_green_red();
void manual_red_green();
#endif /* INC_TRAFFIC_LIGHT_H_ */
