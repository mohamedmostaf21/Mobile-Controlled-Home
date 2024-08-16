/////*
//// * Test_Siren.c
//// *
//// *  Created on: Aug 14, 2024
//// *      Author: k.m
//// */
//#include "../HAL/Siren/SIREN_prog.h"
//#include "../LIBS/delay.h"
//#include "../MCAL/TIMER/TIMER_prog.h"
//TMR_cfg_t TIMER2 = {
//		.TMR_TimerChannel = TIMER2_NORMAL,
//		.TMR_ToggleMode = TMR_InterruptMode,
//		.TMR_OCMode = OC_Disconnected,
//		.TMR_Prescale = PRE_1024
//};

//int main(){
//	Siren_vInit();
//	/* Enable timer 2 */
//		TMR_vStartTimer(&TIMER2);
//		timer2_flag = FLAG_OFF;
//		/* While loop until flag is off */
//		while(timer2_flag == FLAG_OFF){
//			SIREN_vChangeSound(500);  // produce low sound
//			Delay_ms(250);  // wait for 500ms
//			SIREN_vChangeSound(1100); // produce high sound
//			Delay_ms(250);  // wait for 500ms
//			SIREN_vChangeSound(500);  // produce low sound
//			Delay_ms(250);  // wait for 500ms
//			SIREN_vChangeSound(1100); // produce high sound
//			Delay_ms(250);
//			SIREN_vStop();
//			Delay_ms(1000);
//		}
//		TMR_vStop(&TIMER2);
//
//
//	return 0;
//}
