/*
 * Initialization.h
 *
 *  Created on: Aug 17, 2024
 *      Author: k.m
 */

#ifndef APP_INITIALIZATION_INITIALIZATION_H_
#define APP_INITIALIZATION_INITIALIZATION_H_
#include "../../LIBS/STD_TYPES.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/UART/UART_prog.h"
#include "../../HAL/Bluetooth_Module/Bluetooth_prog.h"
#include "../../HAL/Servo/SERVO_prog.h"
#include "../../HAL/Siren/SIREN_prog.h"
#include "../../HAL/SEVEN_SEGMENT/SEV.h"
#include "../../MCAL/TIMER/TIMER_prog.h"
#include <string.h>
#include "../../LIBS/delay.h"
#include "../../MCAL/GIE/GIE_prog.h"
#include "../../HAL/LCD/LCD.h"
#include <stdlib.h>
#define MAX_NUM_USER	10
#define MAX_CHARACTER_LIMIT_USER		30
#define MAX_CHARACTER_LIMIT_PASSWORD	10
//DataBase user(name, password)
typedef struct {
	u8 user_name[MAX_CHARACTER_LIMIT_USER];
	u8 password[MAX_CHARACTER_LIMIT_PASSWORD];
}User;

extern SERVO_PWM_cfg_t SERVO1;
extern User users[MAX_NUM_USER];

void app_Init(void);
#endif /* APP_INITIALIZATION_INITIALIZATION_H_ */
