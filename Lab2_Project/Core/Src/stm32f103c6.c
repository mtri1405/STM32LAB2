/*
 * stm32f103c6.c
 *
 *  Created on: Sep 28, 2025
 *      Author: MinhTri
 */
#include "stm32f103c6.h"
#include "software_timer.h"

void blinkLED(){
	HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
}

void display7SEG(int num) {

    const uint8_t seg_pattern[10][7] = {
        {0,0,0,0,0,0,1}, // 0
        {1,0,0,1,1,1,1}, // 1
        {0,0,1,0,0,1,0}, // 2
        {0,0,0,0,1,1,0}, // 3
        {1,0,0,1,1,0,0}, // 4
        {0,1,0,0,1,0,0}, // 5
        {0,1,0,0,0,0,0}, // 6
        {0,0,0,1,1,1,1}, // 7
        {0,0,0,0,0,0,0}, // 8
        {0,0,0,0,1,0,0}  // 9
    };

    uint16_t pins[7] = {SEG0_Pin, SEG1_Pin, SEG2_Pin, SEG3_Pin, SEG4_Pin, SEG5_Pin, SEG6_Pin};

    if (num < 0 || num > 9) num = 0;

    for (int i = 0; i < 7; i++) {
        HAL_GPIO_WritePin(GPIOB, pins[i], seg_pattern[num][i]);
    }
}
