/*
 * PWM_prog.h
 *
 *  Created on: Aug 13, 2024
 *      Author: k.m
 */

#ifndef MCAL_PWM_PWM_PROG_H_
#define MCAL_PWM_PWM_PROG_H_



/* Section : Includes */
#include "PWM_config.h"
#include "PWM_priv.h"
#include "../DIO/DIO.h"
#include "../../LIBS/BIT_MATH.h"
#include "../../LIBS/STD_TYPES.h"

/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef struct{
	enu_pwmRunningMode 		PWM_TimerChannel;
	enu_TimerPrescale 		PWM_TimerPrescale;
	enu_pwmToggleMode		PWM_ToggleMode;
	enu_pwmInverting		PWM_InvertOrNot;
}PWM_cfg_t;

/* Section : Function Declarations */
void PWM_vInit(const PWM_cfg_t *PWM);

void PWM_vSetICR(const PWM_cfg_t *PWM, u16 Copy_u16ICRValue);

void PWM_vSetOCR(const PWM_cfg_t *PWM, u16 Copy_u16OCRValue);

void PWM_vStart(const PWM_cfg_t *PWM);

void PWM_vStop(const PWM_cfg_t *PWM);


#endif /* MCAL_PWM_PWM_PROG_H_ */
