/*
 * EXTI.h
 *
 *  Created on: Aug 5, 2024
 *      Author: k.m
 */

#ifndef MCAL_EXTI_EXTI_H_
#define MCAL_EXTI_EXTI_H_
#include "../../LIBS/STD_TYPES.h"
typedef void (*pf)(void);

void EXTI_Enable(u8 INT); //Enable specific interrupt

void EXTI_Disable(u8 INT); //disable specific interrupt

tenuErrorStatus EXTI_InitMode(u8 INT, u8 mode);

u8 EXTI_CheckIntFlag(u8 INT);

void EXTI_FnCallBack_INT0(pf callback); //send function to INT0 routine
void EXTI_FnCallBack_INT1(pf callback); //send function to INT1 routine
void EXTI_FnCallBack_INT2(pf callback); //send function to INT2 routine

void __vector_1 (void) __attribute__((signal, used));
void __vector_2 (void) __attribute__((signal, used));
void __vector_3 (void) __attribute__((signal, used));
#endif /* MCAL_EXTI_EXTI_H_ */
