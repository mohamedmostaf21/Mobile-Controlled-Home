/*
 * Initialization.c
 *
 *  Created on: Aug 17, 2024
 *      Author: k.m
 */
#include "Initialization.h"


User users[MAX_NUM_USER] = {
    {"ahmed mohamed", "1111"},
    {"mohamed mostafa", "2222"},
    {"manar mahmoud", "3333"},
    {"arwa gomaa", "4444"},
	{"mohab said", "5555"},
	{"ali gamal", "6666"},
	{"sayed shalaby", "7777"},
	{"michael samir", "8888"},
	{"mohamed hossam", "9999"},
	{"mostafa mohamed","1010"}
};
//initialize servo
SERVO_PWM_cfg_t SERVO1 = {
		.ServoPWM.PWM_TimerChannel = TIMER1_FastICR,
		.ServoPWM.PWM_TimerPrescale  = PRE_64,
		.ServoPWM.PWM_ToggleMode  = PWM_OCmode,
		.ServoPWM.PWM_InvertOrNot   = PWM_NonInvertingMode,
		.ServoInitialDirection = SERVO_0,
		.ICR_Value = 8000,
		.OCR_0degree_Value = 100,
		.OCR_90degree_Value = 188,
		.OCR_180degree_Value = 250
};
//initialize Timer
TMR_cfg_t TIMER2 = {
		.TMR_TimerChannel = TIMER2_NORMAL,
		.TMR_ToggleMode = TMR_InterruptMode,
		.TMR_OCMode = OC_Disconnected,
		.TMR_Prescale = PRE_1024
};
void app_Init(void){
	DIO_voidInit();
	Bluetooth_vInit();
	SERVO_vInit(&SERVO1);
	Siren_vInit();
	Bluetooth_vEnable();
	SERVO_vStart(&SERVO1);
	TMR_vInit(&TIMER2);
	Lcd_DisplayControlType LCD_type;
	LCD_type.cursor = LCD_STATE_OFF;
	LCD_type.display = LCD_STATE_ON;
	LCD_type.cursorBlink = LCD_STATE_OFF;
	LCD_type.font = LCD_FONT_5X7;
	LCD_type.lines = LCD_LINES_2;
	Lcd_Init(&LCD_type);
	Lcd_ClearDisplay();
	Lcd_ReturnHome();
}

