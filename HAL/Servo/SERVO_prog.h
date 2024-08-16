/*
 * SERVO_prog.h
 *
 *  Created on: Aug 13, 2024
 *      Author: k.m
 */

#ifndef HAL_SERVO_SERVO_PROG_H_
#define HAL_SERVO_SERVO_PROG_H_


/* Section : Includes */
#include "servo_config.h"
#include "servo_priv.h"
#include "../../MCAL/PWM/PWM_prog.h"

#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"



typedef struct{
	PWM_cfg_t ServoPWM;
	enu_servoDirections ServoInitialDirection;
	u16	ICR_Value;
	u16 OCR_0degree_Value;
	u16 OCR_90degree_Value;
	u16 OCR_180degree_Value;
}SERVO_PWM_cfg_t;

/* Section : Function Declarations */
void SERVO_vInit(const SERVO_PWM_cfg_t *Servo_PWM);

void SERVO_vChangeDirection(const SERVO_PWM_cfg_t *Servo_PWM, enu_servoDirections Copy_enuDirection);

void SERVO_vStart(const SERVO_PWM_cfg_t *Servo_PWM);

void SERVO_vStop(const SERVO_PWM_cfg_t *Servo_PWM);




#endif /* HAL_SERVO_SERVO_PROG_H_ */
