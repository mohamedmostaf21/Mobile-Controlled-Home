/*
 * SIREN_prog.c
 *
 *  Created on: Aug 14, 2024
 *      Author: k.m
 */

#include "SIREN_prog.h"

void __vector_11(void) __attribute__((signal));
static PWM_cfg_t CURRENT_SIREN;
static enu_siren_state CURRENT_STATE;

void Siren_vInit(){
#if SIREN_TIMER == SIREN_TIMER0
	/* PWM0 implementation */

	CURRENT_SIREN.PWM_InvertOrNot = PWM_NonInvertingMode;
	CURRENT_SIREN.PWM_TimerChannel = TIMER0_FastPWM;
	CURRENT_SIREN.PWM_TimerPrescale = PRE_64;
	CURRENT_SIREN.PWM_ToggleMode = PWM_OCmode;
	DIO_vSetPinDir(PORTB, DIO_PIN_NUM_3, DIO_OUTPUT);
	PWM_vInit(&CURRENT_SIREN);
	TIMSK_REG = (1<<TOIE0);
	GIE_Enable();
	CURRENT_STATE = siren_off;
#elif SIREN_TIMER == SIREN_TIMER1
	/* PWM1 implementation */

#elif SIREN_TIMER == SIREN_TIMER2
	/* PWM2 implementation */

#endif
}

void SIREN_vChangeSound(u16 Copy_u16Frequency){
	u8 prescaler = 1;
	if(siren_off == CURRENT_STATE){
		PWM_vStart(&CURRENT_SIREN);
		CURRENT_STATE = siren_on;
	}
#if SIREN_TIMER == SIREN_TIMER0
	OCR0_REG = (u16)(F_CPU / (2 * Copy_u16Frequency * prescaler)) - 1;
#elif SIREN_TIMER == SIREN_TIMER1
	/* PWM1 implementation */

#elif SIREN_TIMER == SIREN_TIMER2
	/* PWM2 implementation */

#endif
}

void SIREN_vStop(){
#if SIREN_TIMER == SIREN_TIMER0
	PWM_vStop(&CURRENT_SIREN);
	CURRENT_STATE = siren_off;
#elif SIREN_TIMER == SIREN_TIMER1
	/* PWM1 implementation */

#elif SIREN_TIMER == SIREN_TIMER2
	/* PWM2 implementation */

#endif
}

/* TIMER0 OVF ISR */
void __vector_11(void){
	TOGGLE_BIT(ODRB, DIO_PIN_NUM_3);
}
