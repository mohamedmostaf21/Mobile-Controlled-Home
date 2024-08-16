/*
 * SIREN_prog.h
 *
 *  Created on: Aug 14, 2024
 *      Author: k.m
 */

#ifndef HAL_SIREN_SIREN_PROG_H_
#define HAL_SIREN_SIREN_PROG_H_



/* Section : Includes */
#include "../../LIBS/BIT_MATH.h"
#include "../../LIBS/STD_TYPES.h"
#include "../../MCAL/PWM/PWM_prog.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/GIE/GIE_prog.h"

/* Section : Macro Declarations */
#define SIREN_TIMER0		0
#define SIREN_TIMER1		1
#define SIREN_TIMER2		2
#define SIREN_TIMER		SIREN_TIMER0
#define F_CPU			8000000UL


/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef enum{
	siren_off,
	siren_on
}enu_siren_state;

/* Section : Function Declarations */
void Siren_vInit();
void SIREN_vChangeSound(u16 Copy_u16Frequency);
void SIREN_vStop();



#endif /* HAL_SIREN_SIREN_PROG_H_ */
