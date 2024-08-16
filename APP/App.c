/*
 * App.c
 *
 *  Created on: Aug 14, 2024
 *      Author: k.m
 */
#include "../LIBS/STD_TYPES.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/UART/UART_prog.h"
#include "../HAL/Bluetooth_Module/Bluetooth_prog.h"
#include "../HAL/Servo/SERVO_prog.h"
#include "../HAL/Siren/SIREN_prog.h"
#include "../MCAL/TIMER/TIMER_prog.h"
#include <string.h>
#include "../LIBS/delay.h"
#include "../MCAL/GIE/GIE_prog.h"
#include "../HAL/LCD/LCD.h"
#include <stdlib.h>

//DataBase user(name, password)
typedef struct {
	u8 user_name[30];
	u8 password[10];
}User;

User users[10] = {
    {"ahmed", "1111"},
    {"mohamed", "2222"},
    {"manar", "3333"},
    {"arwa", "4444"},
	{"mohab", "5555"},
	{"ali", "6666"},
	{"sayed", "7777"},
	{"micheal", "8888"},
	{"nada", "9999"},
	{"amr","1010"}
};
//initialize servo
SERVO_PWM_cfg_t SERVO1 = {
		.ServoPWM.PWM_TimerChannel = TIMER1_FastICR,
		.ServoPWM.PWM_TimerPrescale  = PRE_64,
		.ServoPWM.PWM_ToggleMode  = PWM_OCmode,
		.ServoPWM.PWM_InvertOrNot   = PWM_NonInvertingMode,
		.ServoInitialDirection = SERVO_0,
		.ICR_Value = 2500,
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
void main(void){
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
	u8 receive;
	u8 i;
	u8 userName[30];
	u8 password[10];
	u8 user_num = 0;
	u8 pass_num = 0;
	u8 user_found = 0;
	u8 choice;
	u8 attempts = 0;
	u8 trials = 3;
	Lcd_DisplayString("      Controlled Home");

	while(1){
		Bluetooth_vClearBuffer();

		Bluetooth_vSendString((u8*)"=== Welcome to Mobile Controlled Home ===\r\n");
		 Bluetooth_vClearBuffer();
		//Bluetooth_vSendData('\0');
		Bluetooth_vSendString((u8*)"Enter User Name: ");
		Bluetooth_vSendString((u8*)"\r\n");
		 for (i = 0; i < 30; i++) {

			receive = Bluetooth_u8ReceiveData();
			if (receive == '\r') break; // End input on carriage return
			userName[i] = receive;
		}
		 userName[i] = '\0'; // Null-terminate the string



		for(i = 0; i < 10; i++){
			if(strcmp((char*) userName, (char*) users[i].user_name) == 0){
				user_num = i+1;
			}
		}
		Lcd_ReturnHome();

		Lcd_DisplayString(" Received User     ");
		Lcd_SetCursorPosition(1, 0);
		Lcd_DisplayString((char*)userName);
		Lcd_DisplayString("        ");
		Bluetooth_vSendString((u8*)"Enter Password: ");
		//Bluetooth_vSendString((u8*)"\r\n");
		while(attempts < 3){
			for (i = 0; i < 10; i++) {
				 Bluetooth_vClearBuffer();
				receive = Bluetooth_u8ReceiveData();
				if (receive == '\r') break; // End input on carriage return
				if(receive >= '0' && receive <= '9')
					password[i] = receive;
			}
			password[i] = '\0'; // Null-terminate the string
			for(i = 0; i < 10; i++){
				if(strcmp((char*) password, (char*) users[i].password) == 0){
					pass_num = i+1;
				}
			}
			Lcd_SetCursorPosition(0,0);
			Lcd_DisplayString("Received Pass       ");
			Lcd_SetCursorPosition(1, 0);
			Lcd_DisplayString((char*)password);
			Lcd_DisplayString("        ");
			if(user_num == 0 || pass_num == 0 || user_num != pass_num){
				trials--;
				Bluetooth_vSendString((u8*)"User Not Found\r\n");
				Bluetooth_vSendString((u8*)"The remaining trials: ");
				Bluetooth_vSendData((u8)trials+48);
				Bluetooth_vSendString((u8*)"\r\n");

				attempts++;
				if(attempts == 3){
					Bluetooth_vSendString((u8*)"You are a Thief\r\n");
					TMR_vStartTimer(&TIMER2);
					timer2_flag = FLAG_OFF;
					//turn on red led
					DIO_enuWritePin(DIO_PIN_NUM_0, DIO_HIGH);
					/* While loop until flag is off */
					while(timer2_flag == FLAG_OFF){
						SIREN_vChangeSound(500);  // produce low sound
						Delay_ms(250);  // wait for 500ms
						SIREN_vChangeSound(1100); // produce high sound
						Delay_ms(250);  // wait for 500ms
						SIREN_vChangeSound(500);  // produce low sound
						Delay_ms(250);  // wait for 500ms
						SIREN_vChangeSound(1100); // produce high sound
						Delay_ms(250);
						SIREN_vStop();
						Delay_ms(1000);

					}
					//SIREN_vStop();
					TMR_vStop(&TIMER2);
					attempts = 0;
					trials = 3;
				}
				Bluetooth_vSendString((u8*)"Enter Your Password Again: ");

			}else{
				attempts = 0;
				trials = 3;
				Bluetooth_vSendString((u8*)"Welcome In Your Smart Home\r\n");
				user_found = 1;
			}

			if(user_found == 1){
				break;
			}
		}


		while(user_found == 1){
			Bluetooth_vClearBuffer();
			Bluetooth_vSendString((u8*)"Enter Your Choice\r\n");
			Bluetooth_vSendString((u8*)"1. For Open Door\r\n");
			Bluetooth_vSendString((u8*)"2. For Close Door\r\n");
			Bluetooth_vSendString((u8*)"3. For Turn On Led\r\n");
			Bluetooth_vSendString((u8*)"4. For Turn Off Led\r\n");
			Bluetooth_vSendString((u8*)"5. LogOut\r\n");
			Bluetooth_vClearBuffer();
			choice = Bluetooth_u8ReceiveData();

			switch (choice) {
				case '1':
					SERVO_vChangeDirection(&SERVO1, SERVO_180);
					Delay_ms(500);
					Bluetooth_vSendString((u8*)"Door is opened\r\n");
					Bluetooth_vClearBuffer();
					break;
				case '2':
					SERVO_vChangeDirection(&SERVO1, SERVO_0);
					Delay_ms(500);
					Bluetooth_vSendString((u8*)"Door is closed\r\n");
					Bluetooth_vClearBuffer();
					break;
				case '3':
					DIO_enuWritePin(DIO_PIN_NUM_1, DIO_HIGH);
					Delay_ms(500);
					Bluetooth_vSendString((u8*)"Led is on\r\n");
					Bluetooth_vClearBuffer();
					break;
				case '4':
					DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
					Delay_ms(500);
					Bluetooth_vSendString((u8*)"Led is off\r\n");
					Bluetooth_vClearBuffer();
					break;
				case '5':
					Bluetooth_vSendString((u8*)"Good Bye\r\n");
					Bluetooth_vClearBuffer();
					exit(0);
				default:
					Bluetooth_vSendString((u8*)"Enter a right choice\r\n");
					Delay_ms(500);
					Bluetooth_vClearBuffer();
					break;
			}
		}
	}



}


