/*
 * TIMER_prog.h
 *
 *  Created on: Aug 14, 2024
 *      Author: k.m
 */

#ifndef MCAL_TIMER_TIMER_PROG_H_
#define MCAL_TIMER_TIMER_PROG_H_

/****************** FILE INCLUDES ******************/
#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"
#include "TIMER_priv.h"
#include "TIMER_config.h"
#include "../GIE/GIE_prog.h"

/****************** CONFIGURATION FOR TIMER ******************/


typedef struct{
	enu_TimerChannel    TMR_TimerChannel;
	enu_prescale_modes  TMR_Prescale;
	enu_TimerToggleMode TMR_ToggleMode;
	enu_TimerOCMode		TMR_OCMode;
}TMR_cfg_t;
void __vector_5(void) __attribute__((signal));
extern TMR_cfg_t TIMER2;
extern u8 timer2_flag;
/****************** FUNCTIONS PROTOTYPES ******************/

// This function is responsible for enabling timer
void TMR_vInit(const TMR_cfg_t *TMR);

// This function is responsible for disabling timer
void TMR_vStop(const TMR_cfg_t *TMR);

// This function is responsible for setting the ICR top value
void TMR_vSetICRValue(const TMR_cfg_t *TMR, u16 Copy_u16ICRValue);

// This function is responsible for setting the OCR top value
void TMR_vSetOCRValue(const TMR_cfg_t *TMR, u16 Copy_u16OCRValue);

// This function starts the timer
void TMR_vStartTimer(const TMR_cfg_t *TMR);




#endif /* MCAL_TIMER_TIMER_PROG_H_ */
