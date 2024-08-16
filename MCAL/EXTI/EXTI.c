/*
 * EXTI.c
 *
 *  Created on: Aug 5, 2024
 *      Author: k.m
 */
#include "../../LIBS/BIT_MATH.h"
#include "../../LIBS/STD_TYPES.h"
#include "../DIO/DIO.h"
#include "EXTI.h"
#include "EXTI_cfg.h"
#include "EXTI_priv.h"


static pf PF1_CallBack ;
static pf PF2_CallBack;
static pf PF3_CallBack;

void EXTI_Enable(u8 INT){
	//Enable Interrupt
	SET_BIT(GICR, INT);
}


void EXTI_Disable(u8 INT){
	CLR_BIT(GICR, INT); //Disable bit INT in GICR REG (INT0 , INT1 ,INT2)
}

tenuErrorStatus EXTI_InitMode(u8 INT, u8 mode){
	tenuErrorStatus enuReturnStateLoc = EOK;
	if(INT == EXTI_INT0){
		if (mode == EXTI_LOW_SGNL){
			CLR_BIT(MCUCR, EXTI_ISC00);
			CLR_BIT(MCUCR, EXTI_ISC01);
		}else if (mode == EXTI_LOG_CHNG){
			SET_BIT(MCUCR, EXTI_ISC00);
			CLR_BIT(MCUCR, EXTI_ISC01);
		}else if (mode == EXTI_FAL_EDGE){
			CLR_BIT(MCUCR, EXTI_ISC00);
			SET_BIT(MCUCR, EXTI_ISC01);
		}else if(mode == EXTI_RAIS_EDGE){
			SET_BIT(MCUCR, EXTI_ISC00);
			SET_BIT(MCUCR, EXTI_ISC01);
		}else{
			enuReturnStateLoc = PARAM_OUT_RANGE;
		}

	}else if(INT == EXTI_INT1){
		if (mode == EXTI_LOW_SGNL){
			CLR_BIT(MCUCR, EXTI_ISC10);
			CLR_BIT(MCUCR, EXTI_ISC11);
		}else if (mode == EXTI_LOG_CHNG){
			SET_BIT(MCUCR, EXTI_ISC10);
			CLR_BIT(MCUCR, EXTI_ISC11);
		}else if (mode == EXTI_FAL_EDGE){
			CLR_BIT(MCUCR, EXTI_ISC10);
			SET_BIT(MCUCR, EXTI_ISC11);
		}else if(mode == EXTI_RAIS_EDGE){
			SET_BIT(MCUCR, EXTI_ISC10);
			SET_BIT(MCUCR, EXTI_ISC11);
		}else{
			enuReturnStateLoc = PARAM_OUT_RANGE;
		}

	}else if(INT == EXTI_INT2){
		if(mode == EXTI_FAL_EDGE){
			CLR_BIT(MCUCSR, EXTI_ISC2);
		}else if(mode == EXTI_RAIS_EDGE){
			SET_BIT(MCUCSR, EXTI_ISC2);
		}else{
			enuReturnStateLoc = PARAM_OUT_RANGE;
		}
	}
	else{
		enuReturnStateLoc = PARAM_OUT_RANGE;
	}

	return enuReturnStateLoc;

}

u8 EXTI_CheckIntFlag(u8 INT)    //check if  specific interrupt flag is up
{
	if(INT == EXTI_INT0)
	{
		if (GET_BIT(GIFR, EXTI_INTF0) == HIGH)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if(INT == EXTI_INT1)
	{
		if (GET_BIT(GIFR, EXTI_INTF1) == HIGH)
		{
			return 1 ;
		}
		else
		{
			return 0;
		}
	}
	else if(INT == EXTI_INT2)
	{
		if (GET_BIT(GIFR, EXTI_INTF2) == HIGH)
		{
			return 1 ;
		}
		else
		{
			return 0;
		}
	}

	return -1;
}

void EXTI_FnCallBack_INT0(pf callback){
	PF1_CallBack = callback;
}
void EXTI_FnCallBack_INT1(pf callback){
	PF2_CallBack = callback;
}
void EXTI_FnCallBack_INT2(pf callback){
	PF3_CallBack = callback;
}

void __vector_1() {
	PF1_CallBack();
}


void __vector_2() {
	PF2_CallBack();
}


void __vector_3() {
	PF3_CallBack();
}
