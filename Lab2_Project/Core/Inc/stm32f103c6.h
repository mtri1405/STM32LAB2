/*
 * stm32f103c6.h
 *
 *  Created on: Sep 28, 2025
 *      Author: MinhTri
 */

#ifndef INC_STM32F103C6_H_
#define INC_STM32F103C6_H_

#include "main.h"

// ---- Constants ----
#define EN0 0
#define EN1 1
#define EN2 2
#define EN3 3
#define MAX_LED 4
#define MAX_LED_MATRIX 8

// ---- External variables ----
extern int hour, minute, second;
extern int led_buffer[MAX_LED];
extern int index_led_matrix;
// ---- Function prototypes ----
void setMatrixBuffer_A(void);
void EnablePin(int num);
void blinkLED(void);
void display7SEG(int num);
void update7SEG(int index);
void displayClock(void);
void setClock(int Hour, int Minute, int Second);
void updateClockBuffer(void);
void updateTime(void);
void updateLEDMatrix(int);
void animationMatrix();
#endif /* INC_STM32F103C6_H_ */
