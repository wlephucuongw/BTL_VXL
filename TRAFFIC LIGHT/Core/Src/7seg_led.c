/*
 * 7seg_led.c
 *
 *  Created on: Sep 23, 2024
 *      Author: Administrator
 */
#include "traffic_light.h"
int led_buffer_A[2]={0,0};
int led_buffer_B[2]={0,0};
int index_led = 0;
//void display7segA(int num){
//	    uint8_t segments[10] = {
//	        0b00111111, // 0
//	        0b00000110, // 1
//	        0b01011011, // 2
//	        0b01001111, // 3
//	        0b01100110, // 4
//	        0b01101101, // 5
//	        0b01111101, // 6
//	        0b00000111, // 7
//	        0b01111111, // 8
//	        0b01101111  // 9
//	    };
//
//	    uint8_t segment_value = segments[num];
//
//	    HAL_GPIO_WritePin(GPIOA, SEG0_A_Pin, (segment_value & 0x01) ? RESET : SET);  // Segment A
//	    HAL_GPIO_WritePin(GPIOA, SEG1_A_Pin, (segment_value & 0x02) ? RESET : SET);  // Segment B
//	    HAL_GPIO_WritePin(GPIOA, SEG2_A_Pin, (segment_value & 0x04) ? RESET : SET);  // Segment C
//	    HAL_GPIO_WritePin(GPIOA, SEG3_A_Pin, (segment_value & 0x08) ? RESET : SET);  // Segment D
//	    HAL_GPIO_WritePin(GPIOA, SEG4_A_Pin, (segment_value & 0x10) ? RESET : SET);  // Segment E
//	    HAL_GPIO_WritePin(GPIOA, SEG5_A_Pin, (segment_value & 0x20) ? RESET : SET);  // Segment F
//	    HAL_GPIO_WritePin(GPIOA, SEG6_A_Pin, (segment_value & 0x40) ? RESET : SET);  // Segment G
//	}
//void display7segB(int num){
//	    uint8_t segments[10] = {
//	        0b00111111, // 0
//	        0b00000110, // 1
//	        0b01011011, // 2
//	        0b01001111, // 3
//	        0b01100110, // 4
//	        0b01101101, // 5
//	        0b01111101, // 6
//	        0b00000111, // 7
//	        0b01111111, // 8
//	        0b01101111  // 9
//	    };
//
//	    uint8_t segment_value = segments[num];
//
//	    HAL_GPIO_WritePin(GPIOA, SEG0_B_Pin, (segment_value & 0x01) ? RESET : SET);  // Segment A
//	    HAL_GPIO_WritePin(GPIOA, SEG1_B_Pin, (segment_value & 0x02) ? RESET : SET);  // Segment B
//	    HAL_GPIO_WritePin(GPIOA, SEG2_B_Pin, (segment_value & 0x04) ? RESET : SET);  // Segment C
//	    HAL_GPIO_WritePin(GPIOA, SEG3_B_Pin, (segment_value & 0x08) ? RESET : SET);  // Segment D
//	    HAL_GPIO_WritePin(GPIOA, SEG4_B_Pin, (segment_value & 0x10) ? RESET : SET);  // Segment E
//	    HAL_GPIO_WritePin(GPIOA, SEG5_B_Pin, (segment_value & 0x20) ? RESET : SET);  // Segment F
//	    HAL_GPIO_WritePin(GPIOA, SEG6_B_Pin, (segment_value & 0x40) ? RESET : SET);  // Segment G
//	}
//void update7segA(int index){	// scan led A
//    HAL_GPIO_WritePin(GPIOB, EN0_A_Pin, SET);
//    HAL_GPIO_WritePin(GPIOB, EN1_A_Pin, SET);
//    switch (index){
//        case 0:
//        	HAL_GPIO_WritePin(GPIOB, EN0_A_Pin, RESET);
//        	display7segA(led_buffer_A[0]);
//            break;
//        case 1:
//            HAL_GPIO_WritePin(GPIOB, EN1_A_Pin, RESET);
//        	display7segA(led_buffer_A[1]);
//            break;
//        default:
//            break;
//    }
//}
//void update7segB(int index){   // scan led B
//    HAL_GPIO_WritePin(GPIOB, EN0_B_Pin, SET);
//    HAL_GPIO_WritePin(GPIOB, EN1_B_Pin, SET);
//    switch (index){
//        case 0:
//        	HAL_GPIO_WritePin(GPIOB, EN0_B_Pin, RESET);
//        	display7segB(led_buffer_B[0]);
//            break;
//        case 1:
//            HAL_GPIO_WritePin(GPIOB, EN1_B_Pin, RESET);
//        	display7segB(led_buffer_B[1]);
//            break;
//        default:
//            break;
//    }
//}
//void update_led_buffer_A(int num){	// update buffer led A
//	if(num <= 9){
//		led_buffer_A[0] = 0;
//		led_buffer_A[1] = num;
//	}
//	else{
//		led_buffer_A[0] = num / 10;
//		led_buffer_A[1] = num % 10;
//	}
//}
//void update_led_buffer_B(int num){	// update buffer led B
//	if(num <= 9){
//		led_buffer_B[0] = 0;
//		led_buffer_B[1] = num;
//	}
//	else{
//		led_buffer_B[0] = num / 10;
//		led_buffer_B[1] = num % 10;
//	}
//}
//void display(){	// display
//	if(timers[9].flag == 1){
//		setTimer(9, 100);
//		index_led = index_led % 2;
//		update7segA(index_led);
//		update7segB(index_led);
//		index_led++;
//	}
//}
