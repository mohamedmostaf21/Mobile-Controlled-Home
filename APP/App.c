/*
 * App.c
 *
 *  Created on: Aug 14, 2024
 *      Author: k.m
 */
#include "Initialization/Initialization.h"


void main(void){
	app_Init();
	u8 receive;
	u8 i;
	u8 userName[30];
	u8 closed = 0;
	u8 opened = 0;
	u8 led_on=0;
	u8 led_off=0;
	u8 password[10];
	u8 user_num = 0;
	u8 pass_num = 0;
	u8 user_found = 0;
	u8 choice;
	u8 attempts = 0;
	u8 trials = 3;
	u8 errorPass  = 0;
	Lcd_SetCursorPosition(0, 0);
	Lcd_DisplayString("       Mobile");
	Lcd_SetCursorPosition(1, 0);
	Lcd_DisplayString("Controlled Home");
	while(1){
		Bluetooth_vClearBuffer();
		Bluetooth_vSendString((u8*)"=== Welcome to Mobile Controlled Home ===\r\n");
		Bluetooth_vClearBuffer();
		Bluetooth_vSendString((u8*)"Enter User Name: ");
		Bluetooth_vSendString((u8*)"\r\n");
		attempts = 0;
		errorPass = 0;
		trials = 3;
		for (i = 0; i < MAX_CHARACTER_LIMIT_USER; i++) {
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
		Lcd_SetCursorPosition(0, 0);
		Lcd_DisplayString(" Received User              ");
		Lcd_SetCursorPosition(1, 0);
		Lcd_DisplayString((char*)userName);
		Lcd_DisplayString("            ");
		Bluetooth_vSendString((u8*)"Enter Password: ");
		//Bluetooth_vSendString((u8*)"\r\n");
		while(attempts < 3){

			for (i = 0; i < MAX_CHARACTER_LIMIT_PASSWORD; i++) {
				 Bluetooth_vClearBuffer();
				receive = Bluetooth_u8ReceiveData();
				if (receive == '\r') break; // End input on carriage return
					password[i] = receive;
			}
			password[i] = '\0'; // Null-terminate the string

			for(i = 0; i < 10; i++){
				if(strcmp((char*) password, (char*) users[i].password) == 0){
					pass_num = i+1;
				}
			}
			for (i = 0; password[i] != '\0'; i++) {
				if(!(password[i] >= '0' && password[i] <= '9') ){
					errorPass = 1;
					break;
				}
			}
			if(errorPass == 1){
				Bluetooth_vSendString((u8*)"Error Enter Integers Only in Password\r\n");
				Lcd_ReturnHome();
				Lcd_SetCursorPosition(0, 0);
				Lcd_DisplayString(" Password Error     ");
				Lcd_SetCursorPosition(1, 0);
				Lcd_DisplayString("integers Only    ");
				break;
			}

			Lcd_ReturnHome();
			Lcd_SetCursorPosition(0, 0);
			Lcd_DisplayString("  Received Pass               ");
			Lcd_SetCursorPosition(1, 0);
			Lcd_DisplayString((char*)password);
			Lcd_DisplayString("          ");
			if(user_num == 0 || pass_num == 0 || user_num != pass_num){
				trials--;
				Bluetooth_vSendString((u8*)"User Not Found\r\n");
				Bluetooth_vSendString((u8*)"The remaining trials: ");
				Bluetooth_vSendData((u8)trials+48);
				Bluetooth_vSendString((u8*)"\r\n");
				attempts++;
				if(attempts == 3){
					Sev_PowerOn(0);
					Bluetooth_vSendString((u8*)"You are a Thief\r\n");
					TMR_vStartTimer(&TIMER2);
					timer2_flag = FLAG_OFF;
					//turn on red led
					DIO_enuWritePin(DIO_PIN_NUM_0, DIO_HIGH);
					/* While loop until flag is off */
					while(timer2_flag == FLAG_OFF){
						SIREN_vChangeSound(500);  // produce low sound
						Delay_ms(250);  // wait for 250ms
						SIREN_vChangeSound(1100); // produce high sound
						Delay_ms(250);  // wait for 250ms
						SIREN_vChangeSound(500);  // produce low sound
						Delay_ms(250);  // wait for 250ms
						SIREN_vChangeSound(1100); // produce high sound
						Delay_ms(250);
						SIREN_vStop();
						Delay_ms(1000);

					}
					//SIREN_vStop();
					TMR_vStop(&TIMER2);
				}
				if(attempts < 3){
					Bluetooth_vSendString((u8*)"Enter Your Password Again: ");
				}
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
					Delay_ms(200);
					if(opened == 1){
						Bluetooth_vSendString((u8*)"\r\nDoor is already opened\r\n\r\n");
						Bluetooth_vClearBuffer();
						break;
					}
					opened = 1;
					closed = 0;
					Bluetooth_vSendString((u8*)"\r\nDoor is opened\r\n\r\n");
					Bluetooth_vClearBuffer();
					break;
				case '2':
					SERVO_vChangeDirection(&SERVO1, SERVO_0);
					Delay_ms(200);
					if(closed == 1){
						Bluetooth_vSendString((u8*)"\r\nDoor is already closed\r\n\r\n");
						Bluetooth_vClearBuffer();
						break;
					}
					closed = 1;
					opened = 0;
					Bluetooth_vSendString((u8*)"\r\nDoor is closed\r\n\r\n");
					Bluetooth_vClearBuffer();
					break;
				case '3':
					DIO_enuWritePin(DIO_PIN_NUM_1, DIO_HIGH);
					Delay_ms(200);
					if(led_on == 1){
						Bluetooth_vSendString((u8*)"\r\nLed is already on\r\n\r\n");
						Bluetooth_vClearBuffer();
						break;
					}
					led_on = 1;
					led_off = 0;
					Bluetooth_vSendString((u8*)"\r\nLed is on\r\n\r\n");
					Bluetooth_vClearBuffer();
					break;
				case '4':
					DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
					Delay_ms(200);
					if(led_off == 1){
						Bluetooth_vSendString((u8*)"\r\nLed is already off\r\n\r\n");
						Bluetooth_vClearBuffer();
						break;
					}
					led_off = 1;
					led_on= 0;
					Bluetooth_vSendString((u8*)"\r\nLed is off\r\n\r\n");
					Bluetooth_vClearBuffer();
					break;
				case '5':
					Bluetooth_vSendString((u8*)"\r\nGood Bye\r\n\r\n");\
					DIO_enuWritePin(DIO_PIN_NUM_1, DIO_LOW);
					SERVO_vChangeDirection(&SERVO1, SERVO_0);
					Delay_ms(200);
					Bluetooth_vClearBuffer();
					exit(0);
				default:
					Bluetooth_vSendString((u8*)"\r\nEnter a right choice\r\n\r\n");
					Delay_ms(200);
					Bluetooth_vClearBuffer();
					break;
			}
		}
	}
}


