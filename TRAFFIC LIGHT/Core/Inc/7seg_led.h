/*
 * 7seg_led.h
 *
 *  Created on: Sep 23, 2024
 *      Author: Administrator
 */

#ifndef INC_7SEG_LED_H_
#define INC_7SEG_LED_H_

#include "global.h"
//extern int led_buffer_A[2];
//extern int led_buffer_B[2];
//extern int index_led_A;
//extern int index_led_B;
void display7segA(int num);
void display7segB(int num);
void update7segA();
void update7segB();
void update_led_buffer_A(int num);
void update_led_buffer_B(int num);
void display();
#endif /* INC_7SEG_LED_H_ */
