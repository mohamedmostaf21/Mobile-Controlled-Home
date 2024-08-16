///*
// * Test_Servo.c
// *
// *  Created on: Aug 13, 2024
// *      Author: k.m
// */
//
//#include "../HAL/Servo/SERVO_prog.h"
//#include "../MCAL/DIO/DIO.h"
//#include "../LIBS/delay.h"
//SERVO_PWM_cfg_t SERVO1 = {
//		.ServoPWM.PWM_TimerChannel = TIMER1_FastICR,
//		.ServoPWM.PWM_TimerPrescale  = PRE_64,
//		.ServoPWM.PWM_ToggleMode  = PWM_OCmode,
//		.ServoPWM.PWM_InvertOrNot   = PWM_NonInvertingMode,
//		.ServoInitialDirection = SERVO_0,
//		.ICR_Value = 2500,
//		.OCR_0degree_Value = 100,
//		.OCR_90degree_Value = 188,
//		.OCR_180degree_Value = 250
//};
//
//int main(){
//	DIO_voidInit();
//	SERVO_vInit(&SERVO1);
//	SERVO_vStart(&SERVO1);
//	while(1){
//			SERVO_vChangeDirection(&SERVO1, SERVO_180);
//			Delay_ms(2000);
//			SERVO_vChangeDirection(&SERVO1, SERVO_0);
//			Delay_ms(2000);
//			//SERVO_vChangeDirection(&SERVO1, SERVO_180);
//	}
//
//	return 0;
//}
