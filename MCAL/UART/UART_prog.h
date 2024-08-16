/*
 * UART_prog.h
 *
 *  Created on: Aug 13, 2024
 *      Author: k.m
 */

#ifndef MCAL_UART_UART_PROG_H_
#define MCAL_UART_UART_PROG_H_


/* Section : Includes */
#include "../UART/UART_config.h"
#include "../UART/UART_priv.h"


/* Section : Macro Declarations */

/* Section : Macro Functions Declarations */

/* Section : Data Type Declarations */
typedef struct{
	CharSize_tcfg		GLOBAL_tcfgCharSize;
	ParityState_tcfg	GLOBAL_tcfgParityState;
	StopBitsNum_tcfg	GLOBAL_tcfgStopBits;
	UARTInterrupt_tcfg	GLOBAL_tcfgUartInterrupt;
	UARTBaudRate2X_tcfg	GLOBAL_tcfgUartBaudRate2X;
	UARTBaudRate1X_tcfg	GLOBAL_tcfgUartBaudRate1X;
	UART_ClkMode_tcfg	GLOBAL_tcfgUartClkMode;
	UARTCommMode_tcfg	GLOBAL_tcfgUartCommMode;
}UART_tcfgInitialize;

/* Section : Function Declarations */
void UART_vInit(const UART_tcfgInitialize *LOCAL_tcfgUART);

void UART_vEnable(const UART_tcfgInitialize *LOCAL_tcfgUART);

void UART_vDisable(const UART_tcfgInitialize *LOCAL_tcfgUART);

void UART_vSendData(u8 LOCAL_u8Data);

u8 UART_u8ReceiveData(void);

void UART_vSendString(u8 *Copy_u8Str);

void UART_vClearBuffer();




#endif /* MCAL_UART_UART_PROG_H_ */
