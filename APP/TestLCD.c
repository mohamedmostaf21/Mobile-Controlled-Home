///////*
////// * TestLCD.c
////// *
////// *  Created on: Aug 4, 2024
////// *      Author: k.m
////// */
//////
//#include "../MCAL/DIO/DIO.h"
//#include "../HAL/LCD/LCD.h"
//#include "../LIBS/STD_TYPES.h"
//#include "../LIBS/delay.h"
//#include "../HAL/Keypad_driver/keypad.h"
//#include <util/delay.h>
//int main(){
//	DIO_voidInit();
//	//Keypad_voidInit();
//	Lcd_DisplayControlType LCD_type;
//	LCD_type.cursor = LCD_STATE_OFF;
//	LCD_type.display = LCD_STATE_ON;
//	LCD_type.cursorBlink = LCD_STATE_OFF;
//	LCD_type.font = LCD_FONT_5X7;
//	LCD_type.lines = LCD_LINES_2;
//	Lcd_Init(&LCD_type);
//	//Lcd_Init(LCD_type->display);
//	Lcd_ClearDisplay();
//	Lcd_ReturnHome();
//	s8 key;
//	Lcd_SetCursorPosition(0, 0);
//	Lcd_DisplayString("press key");
//	Lcd_SetCursorPosition(1, 0);
//	while(1){
//
//		key = KEYPAD_getPressedKey();
//		if((key <= 9) && (key >= 0))
//		{
//			Lcd_DisplayNumber(key);   /* display the pressed keypad switch */
//		}
//		else
//		{
//			Lcd_DisplayCharcter(key); /* display the pressed keypad switch */
//		}
//
//		_delay_ms(100); /* Press time */
//
//	}
//	return 0;
//}
