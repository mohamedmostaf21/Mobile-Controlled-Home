/*
 * Bluetooth_prog.h
 *
 *  Created on: Aug 13, 2024
 *      Author: k.m
 */

#ifndef HAL_BLUETOOTH_MODULE_BLUETOOTH_PROG_H_
#define HAL_BLUETOOTH_MODULE_BLUETOOTH_PROG_H_



#include "../../MCAL/UART/UART_prog.h"

void Bluetooth_vInit();

void Bluetooth_vEnable();

void Bluetooth_vDisable();

void Bluetooth_vSendData(u8 Copy_u8Data);

u8 Bluetooth_u8ReceiveData(void);

void Bluetooth_vSendString(u8 *Copy_u8Str);

void Bluetooth_vClearBuffer();


#endif /* HAL_BLUETOOTH_MODULE_BLUETOOTH_PROG_H_ */
