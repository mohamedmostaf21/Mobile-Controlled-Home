/*
 * EXTI_priv.h
 *
 *  Created on: Aug 5, 2024
 *      Author: k.m
 */

#ifndef MCAL_EXTI_EXTI_PRIV_H_
#define MCAL_EXTI_EXTI_PRIV_H_

#define MCUCR 		*((volatile u8*) 0x55)  //Micro controller Unit control reg Definition
#define GICR		*((volatile u8*) 0x5B) //Global interrupt control reg Definition
#define GIFR 		*((volatile u8*) 0x5A) //Global interrupt flag reg Definition
#define MCUCSR 		*((volatile u8*)(0x54)) //Micro controller Unit control and status reg Definition

//Interrupt modes
#define EXTI_LOW_SGNL  1
#define EXTI_LOG_CHNG  2
#define EXTI_FAL_EDGE  3
#define EXTI_RAIS_EDGE 4

#define EXTI_ISC00 	0
#define EXTI_ISC01 	1
#define EXTI_ISC10 	2
#define EXTI_ISC11 	3
#define EXTI_ISC2  	6
//Interrupt names
#define EXTI_INT0 	6
#define EXTI_INT1 	7
#define EXTI_INT2 	5

//interrupt flags
#define EXTI_INTF0 	6
#define EXTI_INTF1 	7
#define EXTI_INTF2 	5


#define EXTI_INT0_PIN 	DIO_PIN_NUM_26 //PD2
#define EXTI_INT1_PIN 	DIO_PIN_NUM_27 //PD3
#define EXTI_INT2_PIN 	DIO_PIN_NUM_10 //PB2

#endif /* MCAL_EXTI_EXTI_PRIV_H_ */
