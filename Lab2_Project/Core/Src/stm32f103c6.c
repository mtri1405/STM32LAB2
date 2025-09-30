/*
 * stm32f103c6.c
 *
 *  Created on: Sep 30, 2025
 *      Author: mtri1
 */

#include "stm32f103c6.h"

int hour = 0, minute = 0, second = 0;
int counter = 0;
int index_led = 0;
int led_buffer[MAX_LED] = {0, 0, 0, 0};

// EN pins
const uint16_t EN[MAX_LED] = { EN0_Pin, EN1_Pin, EN2_Pin, EN3_Pin };

// ---- Enable one digit ----
void EnablePin(int num) {
    for (int i = 0; i < MAX_LED; i++) {
        HAL_GPIO_WritePin(GPIOA, EN[i], GPIO_PIN_SET);
    }
    HAL_GPIO_WritePin(GPIOA, EN[num], GPIO_PIN_RESET);
}

// ---- Blink red LED ----
void blinkLED() {
    HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
}

// ---- Display number on 7SEG ----
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

    uint16_t pins[7] = { SEG0_Pin, SEG1_Pin, SEG2_Pin, SEG3_Pin, SEG4_Pin,
                         SEG5_Pin, SEG6_Pin };

    if (num < 0 || num > 9) num = 0;

    for (int i = 0; i < 7; i++) {
        HAL_GPIO_WritePin(GPIOB, pins[i],
            seg_pattern[num][i] ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
}

// ---- Update one digit ----
void update7SEG(int index) {
    if (index < 0 || index >= MAX_LED) return;
    EnablePin(index);
    display7SEG(led_buffer[index]);
}

// ---- Display clock cycle ----
void displayClock() {
    update7SEG(counter++);
    if (counter >= MAX_LED) counter = 0;
}

// ---- Set clock time ----
void setClock(int Hour, int Minute, int Second) {
    hour = Hour;
    minute = Minute;
    second = Second;
    updateClockBuffer();
}

// ---- Update led buffer ----
void updateClockBuffer() {
    led_buffer[0] = hour / 10;
    led_buffer[1] = hour % 10;
    led_buffer[2] = minute / 10;
    led_buffer[3] = minute % 10;
}

// ---- Increase time ----
void updateTime() {
    second++;
    if (second >= 60) {
        second = 0;
        minute++;
    }
    if (minute >= 60) {
        minute = 0;
        hour++;
    }
    if (hour >= 24) {
        hour = 0;
    }
    updateClockBuffer();
}
