/*
 * stm32f103c6.h
 *
 *  Created on: Sep 28, 2025
 *      Author: MinhTri
 */

#ifndef INC_STM32F103C6_H_
#define INC_STM32F103C6_H_

#include "main.h"
#include "software_timer.h"

#define EN0 0
#define EN1 1
#define EN2 2
#define EN3 3

const uint16_t EN[4] = { EN0_Pin, EN1_Pin, EN2_Pin, EN3_Pin };
void EnablePin(int num){
	for (int i = 0; i < 4; i++){
		HAL_GPIO_WritePin(GPIOA, EN[i], GPIO_PIN_SET);
	}
	HAL_GPIO_WritePin(GPIOA, EN[num], GPIO_PIN_RESET);
}
void blinkLED() {
	HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
}

void display7SEG(int num) {

	const uint8_t seg_pattern[10][7] = { { 0, 0, 0, 0, 0, 0, 1 }, // 0
			{ 1, 0, 0, 1, 1, 1, 1 }, // 1
			{ 0, 0, 1, 0, 0, 1, 0 }, // 2
			{ 0, 0, 0, 0, 1, 1, 0 }, // 3
			{ 1, 0, 0, 1, 1, 0, 0 }, // 4
			{ 0, 1, 0, 0, 1, 0, 0 }, // 5
			{ 0, 1, 0, 0, 0, 0, 0 }, // 6
			{ 0, 0, 0, 1, 1, 1, 1 }, // 7
			{ 0, 0, 0, 0, 0, 0, 0 }, // 8
			{ 0, 0, 0, 0, 1, 0, 0 }  // 9
	};

	uint16_t pins[7] = { SEG0_Pin, SEG1_Pin, SEG2_Pin, SEG3_Pin, SEG4_Pin,
	SEG5_Pin, SEG6_Pin };

	if (num < 0 || num > 9)
		num = 0;

	for (int i = 0; i < 7; i++) {
		HAL_GPIO_WritePin(GPIOB, pins[i], seg_pattern[num][i]);
	}
}

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = { 1, 2, 3, 4 };
void update7SEG(int index) {
	switch (index) {
	case EN0:
		// Display first 7SEG with led_buffer[0]
		EnablePin(EN0);
		display7SEG(led_buffer[0]);
		break;
	case EN1:
		// Display first 7SEG with led_buffer[1]
		EnablePin(EN1);
		display7SEG(led_buffer[1]);
		break;
	case EN2:
		// Display first 7SEG with led_buffer[2]
		EnablePin(EN2);
		display7SEG(led_buffer[2]);
		break;
	case EN3:
		// Display first 7SEG with led_buffer[3]
		EnablePin(EN3);
		display7SEG(led_buffer[3]);
		break;
	default:
		break;
	}
}
#endif /* INC_STM32F103C6_H_ */
