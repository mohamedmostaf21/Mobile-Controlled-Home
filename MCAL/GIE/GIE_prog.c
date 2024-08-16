/*
 * GIE_prog.c
 *
 *  Created on: Aug 4, 2024
 *      Author: k.m
 */
#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"
#include "GIE_priv.h"
#include "GIE_prog.h"
/*
The I-bit is cleared by hardware after an interrupt
has occurred, and is set by the RETI instruction to enable subsequent interrupts.
The I-bit can also be set and cleared by the application with ---the SEI and CLI---  instruction
  */
void GIE_Enable(){
	SET_BIT(SREG, 7);
}

void GIE_Disable(){
	CLR_BIT(SREG, 7);
}
