/*
 * PWM_config.h
 *
 *  Created on: Aug 13, 2024
 *      Author: k.m
 */

#ifndef MCAL_PWM_PWM_CONFIG_H_
#define MCAL_PWM_PWM_CONFIG_H_



/* Section : Data Type Declarations */
typedef enum{
	TIMER0_PhaseCorrect,
	TIMER0_FastPWM,
	TIMER1_Phase8,
	TIMER1_Phase9,
	TIMER1_Phase10,
	TIMER1_Fast8,
	TIMER1_Fast9,
	TIMER1_Fast10,
	TIMER1_PhaseFreqICR,
	TIMER1_PhaseFreqOCR,
	TIMER1_PhaseICR,
	TIMER1_PhaseOCR,
	TIMER1_FastICR,
	TIMER1_FastOCR,
	TIMER2_PhaseCorrect,
	TIMER2_FastPWM
}enu_pwmRunningMode;

typedef enum{
	PRE_NO_CLK,
	PRE_0,
	PRE_8,
	PRE_64,
	PRE_256,
	PRE_1024,
	PRE_EXT_FALLING,
	PRE_EXT_RISING,
	PRE_32,
	PRE_128
}enu_TimerPrescale;

typedef enum{
	PWM_InvertingMode,
	PWM_NonInvertingMode
}enu_pwmInverting;

typedef enum{
	PWM_OCmode,
	PWM_InterruptMode
}enu_pwmToggleMode;




#endif /* MCAL_PWM_PWM_CONFIG_H_ */
