/*
 * traffic_light.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Administrator
 */
#include "traffic_light.h"
#include "i2c-lcd.h"
int TIME_FOR_GREEN = 3;
int TIME_FOR_RED = 5;
int TIME_FOR_AMBER = 2;
int time_red;
int time_green;
int time_amber;
int newTime = 0;
//void updateBufferA(int num){
//	if(num <= 9){
//		bufferA[0] = 0;
//		bufferA[1] = num;
//	}
//	else{
//		bufferA[0] = num / 10;
//		bufferB[1] = num % 10;
//	}
//}
//void updateBufferB(int num){
//	if(num <= 9){
//		bufferB[0] = 0;
//		bufferB[1] = num;
//	}
//	else{
//		bufferB[0] = num / 10;
//		bufferB[1] = num % 10;
//	}
//}

void init(){
	// HAL_GPIO_TogglePin(GPIOA, SIGNAL_Pin);
	if(TIME_FOR_GREEN < TIME_FOR_RED){
		 time_red = TIME_FOR_RED;
		 time_green = TIME_FOR_GREEN;
		 time_amber = TIME_FOR_RED - TIME_FOR_GREEN - 1;
	}
	else {
	 time_red = 5;
	 time_green = 3;
	 time_amber = 2;
	}
}
void auto_green_red(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, RESET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, RESET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, SET);

	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);


	HAL_GPIO_WritePin(LED3_A_GPIO_Port, LED3_A_Pin, SET);
	HAL_GPIO_WritePin(LED3_B_GPIO_Port, LED3_B_Pin, SET);

//	update_led_buffer_A(time_green);
//	update_led_buffer_B(time_red);
	display_lcd(time_green, time_red);
	if(timers[1].flag == 1) // flag for display 7
		{
			time_green--;
			time_red--;
			setTimer(1, 1000);
		}
}
void auto_amber_red(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, RESET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, SET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, RESET);

	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);


	HAL_GPIO_WritePin(LED3_A_GPIO_Port, LED3_A_Pin, SET);
	HAL_GPIO_WritePin(LED3_B_GPIO_Port, LED3_B_Pin, SET);

//	update_led_buffer_A(time_amber);
//	update_led_buffer_B(time_red);
//	display();
	display_lcd(time_amber, time_red);
	if(timers[1].flag == 1) // flag for display 7
		{
			time_amber--;
			time_red--;
			setTimer(1, 1000);
		}
}
void auto_red_green(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, SET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, SET);

	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, RESET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);


	HAL_GPIO_WritePin(LED3_A_GPIO_Port, LED3_A_Pin, RESET);
	HAL_GPIO_WritePin(LED3_B_GPIO_Port, LED3_B_Pin, SET);

//	update_led_buffer_A(time_red);
//	update_led_buffer_B(time_green);
//	display();
	display_lcd(time_red, time_green);
	if(timers[1].flag == 1) // flag for display 7
		{
			time_red--;
			time_green--;
			setTimer(1, 1000);
		}
}
void auto_red_amber(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, SET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, SET);

	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, RESET);


	HAL_GPIO_WritePin(LED3_A_GPIO_Port, LED3_A_Pin, SET);
	HAL_GPIO_WritePin(LED3_B_GPIO_Port, LED3_B_Pin, RESET);

//	update_led_buffer_A(time_red);
//	update_led_buffer_B(time_amber);
//	display();
	display_lcd(time_red, time_amber);
	if(timers[1].flag == 1) // flag for display 7
		{
			time_red--;
			time_amber--;
			setTimer(1, 1000);
		}
}

// use timer 3
void modify_red_led(){

	if(timers[3].flag == 1){

		HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
		HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);

		HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
		HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);

		HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, SET);
		HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, SET);

		HAL_GPIO_WritePin(LED3_A_GPIO_Port, LED3_A_Pin, SET);
		HAL_GPIO_WritePin(LED3_B_GPIO_Port, LED3_B_Pin, SET);
		setTimer(3, 500);
	}
//	update_led_buffer_B(2); // mode name
//	update_led_buffer_A(newTime); //new time
//	display();
	display_lcd(2, newTime);
}
void modify_green_led(){
	if(timers[3].flag == 1){

		HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, RESET);
		HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);

		HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, RESET);
		HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);

		HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, RESET);
		HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, SET);

		HAL_GPIO_WritePin(LED3_A_GPIO_Port, LED3_A_Pin, RESET);
		HAL_GPIO_WritePin(LED3_B_GPIO_Port, LED3_B_Pin, SET);
		setTimer(3, 500);
	}
//	update_led_buffer_B(3); // mode name
//	update_led_buffer_A(newTime); // new time
//	display();
	display_lcd(3, newTime);
}
void modify_amber_led(){
	if(timers[3].flag == 1){
		HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
		HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, RESET);

		HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
		HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, RESET);

		HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, SET);
		HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, RESET);

		HAL_GPIO_WritePin(LED3_A_GPIO_Port, LED3_A_Pin, SET);
		HAL_GPIO_WritePin(LED3_B_GPIO_Port, LED3_B_Pin, RESET);
		setTimer(3, 500);
	}
//	update_led_buffer_B(4); //  mode name
//	update_led_buffer_A(newTime); //new time
//	display();
	display_lcd(4, newTime);
}
void clear_all_led(){
	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, RESET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, RESET);

	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, RESET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, RESET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, RESET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, RESET);

	HAL_GPIO_WritePin(LED3_A_GPIO_Port, LED3_A_Pin, RESET);
	HAL_GPIO_WritePin(LED3_B_GPIO_Port, LED3_B_Pin, RESET);
}
void manual_green_red(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, RESET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, RESET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, SET);

	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, SET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);


	HAL_GPIO_WritePin(LED3_A_GPIO_Port, LED3_A_Pin, SET);
	HAL_GPIO_WritePin(LED3_B_GPIO_Port, LED3_B_Pin, SET);
//	update_led_buffer_B(1); //  mode name
//	update_led_buffer_A(0); //00
//	display();
	display_lcd(1, 0);
}
void manual_red_green(){

	HAL_GPIO_WritePin(LED0_A_GPIO_Port, LED0_A_Pin, SET);
	HAL_GPIO_WritePin(LED0_B_GPIO_Port, LED0_B_Pin, SET);

	HAL_GPIO_WritePin(LED2_A_GPIO_Port, LED2_A_Pin, SET);
	HAL_GPIO_WritePin(LED2_B_GPIO_Port, LED2_B_Pin, SET);

	HAL_GPIO_WritePin(LED1_A_GPIO_Port, LED1_A_Pin, RESET);
	HAL_GPIO_WritePin(LED1_B_GPIO_Port, LED1_B_Pin, SET);

	HAL_GPIO_WritePin(LED3_A_GPIO_Port, LED3_A_Pin, RESET);
	HAL_GPIO_WritePin(LED3_B_GPIO_Port, LED3_B_Pin, SET);
//	update_led_buffer_B(1); //  mode name
//	update_led_buffer_A(0); //00
//	display();
	display_lcd(1, 0);
}
