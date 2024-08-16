///*
// * Test_UART.c
// *
// *  Created on: Aug 15, 2024
// *      Author: k.m
// */
//#include "../HAL/LCD/LCD.h"
//#include "../MCAL/UART_Driver/UART_interface.h"
//#include "../MCAL/DIO/DIO.h"
//#include "../MCAL/GIE/GIE_prog.h"
//void send_temp(void);
//void receive_temp(void);
//u8 temp;
//void main(void){
//	DIO_voidInit();
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
//	Lcd_SetCursorPosition(0, 0);
//	Lcd_DisplayString("       Welcome");
//	UART_voidInit();
//
//	UARTTX_vidSetISR(send_temp);
//
//	UARTRX_vidSetISR(receive_temp);
//	GIE_Enable();
//	Lcd_SetCursorPosition(1, 0);
//	while(1){
//		if(temp >= 'A' && temp <= 'Z'){
//			Lcd_DisplayCharcter(temp);
//		}else{
//			Lcd_DisplayString("Error");
//		}
//	}
//
//
//
//
//}
//
//void send_temp(void){
//
//	UART_voidSendData_Asynch(temp);
//
//}
//
//void receive_temp(void){
//	temp = UART_ReceiveData();
//
//}
