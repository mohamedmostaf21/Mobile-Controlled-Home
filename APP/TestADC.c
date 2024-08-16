/////*
//// * TestADC.c
//// *
//// *  Created on: Aug 9, 2024
//// *      Author: k.m
//// */
//#include "../MCAL/ADC/ADC_prog.h"
//
//#include "../MCAL/DIO/DIO.h"
//#include "../HAL/LCD/LCD.h"
//#include "../LIBS/delay.h"
//#include "../MCAL/GIE/GIE_prog.h"
//#include "../LIBS/BIT_MATH.h"
//#include <stdlib.h>
//void routine();
//int main(){
//	DIO_voidInit();
//	ADC_voidInit();
//	ADC_voidEnable();
//	//GIE_Enable();
//	//ADC_voidEnableInterrupt();
//	ADC_voidStartConversion(ADC_CHANNEL_0);
//	//ADC_voidSetCallback(routine);
//	Lcd_DisplayControlType LCD_type;
//	LCD_type.cursor = LCD_STATE_OFF;
//	LCD_type.display = LCD_STATE_ON;
//	LCD_type.cursorBlink = LCD_STATE_OFF;
//	LCD_type.font = LCD_FONT_5X7;
//	LCD_type.lines = LCD_LINES_2;
//	Lcd_Init(&LCD_type);
//
//	Lcd_ClearDisplay();
//	Lcd_ReturnHome();
//	//Lcd_ShiftDisplayRight(2);
//	u16 data;
//
//	while(1){
//		Lcd_SetCursorPosition(0, 1);
//		//polling
//		data = ADC_u16ReadSync(ADC_CHANNEL_0);
//		if(data < 100){
//			Lcd_DisplayString("NEED WATER");
//			Lcd_DisplayString("          ");
//		}else if(data >= 100 && data <= 200){
//			Lcd_DisplayString("NEED FOOD");
//			Lcd_DisplayString("          ");
//		}else if(data > 200){
//			Lcd_DisplayString("THANKS");
//			Lcd_DisplayString("          ");
//		}
//
//
//
//	}
//
//	return 0;
//}
//
//void routine(){
//	ADC_voidStartConversion(ADC_CHANNEL_0);
//
//}
//
