/*
 * LCD_cfg.h
 *
 *  Created on: Aug 4, 2024
 *      Author: k.m
 */

#ifndef HAL_LCD_LCD_CFG_H_
#define HAL_LCD_LCD_CFG_H_

/*============================================================================
 * LCD Connections
 *============================================================================
 * in 4Bit mode:
 * - Control  and data registers must be the same
 * - Data bits are connected D4->Bit4 D5->Bit5 D6->Bit6 D7->Bit7
 */

/*
 -----------                   ----------
 | ATmega32  |                 |   LCD    |
 |           |                 |          |
 |        PD7|---------------->|D7        |
 |        PD6|---------------->|D6        |
 |        PD5|---------------->|D5        |
 |        PD4|---------------->|D4        |
 |        PD3|---------------->|D3        |
 |        PD2|---------------->|D2        |
 |        PD1|---------------->|D1        |
 |        PD0|---------------->|D0        |
 |           |                 |          |
 |        PC5|---------------->|E         |
 |        PC6|---------------->|RW        |
 |        PC7|---------------->|RS        |
 -----------                   ----------
 */





#define LCD_MODE_8_BIT  1
#define LCD_MODE_4_BIT  2

#define LCD_MODE        LCD_MODE_8_BIT

#define LCD_PIN_RS      DIO_PIN_NUM_7
#define LCD_PIN_RW     	DIO_PIN_NUM_6
#define LCD_PIN_EN      DIO_PIN_NUM_5

#if LCD_MODE == LCD_MODE_8_BIT
#define LCD_PIN_D0       DIO_PIN_NUM_16
#define LCD_PIN_D1       DIO_PIN_NUM_17
#define LCD_PIN_D2       DIO_PIN_NUM_18
#define LCD_PIN_D3       DIO_PIN_NUM_19
#endif
#define LCD_PIN_D4       DIO_PIN_NUM_20
#define LCD_PIN_D5       DIO_PIN_NUM_21
#define LCD_PIN_D6       DIO_PIN_NUM_22
#define LCD_PIN_D7       DIO_PIN_NUM_23

#endif /* HAL_LCD_LCD_CFG_H_ */
