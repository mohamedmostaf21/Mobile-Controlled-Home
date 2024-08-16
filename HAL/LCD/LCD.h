/*
 * LCD.h
 *
 *  Created on: Aug 4, 2024
 *      Author: k.m
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_
#include "../../LIBS/STD_TYPES.h"
#define LCD_SET_CURSOR_LOCATION 0x80
typedef enum {
    LCD_STATE_OFF,
    LCD_STATE_ON
} Lcd_StateType;

typedef enum {
    LCD_LINES_1,
    LCD_LINES_2
} Lcd_LinesType;

typedef enum {
    LCD_FONT_5X7,
    LCD_FONT_5X10
} Lcd_FontType;

typedef struct
{
    Lcd_StateType display;
    Lcd_StateType cursor;
    Lcd_StateType cursorBlink;
    Lcd_LinesType lines;
    Lcd_FontType font;
} Lcd_DisplayControlType;

//extern Lcd_DisplayControlType Lcd_Configuration;
void Lcd_moveCursor(u8 row,u8 col);
void Lcd_Init(const Lcd_DisplayControlType* control);
void Lcd_DisplayCharcter(char data);
void Lcd_DisplayString(const char* str);
void Lcd_DisplayNumber(s32 number);
void Lcd_ClearDisplay(void);
void Lcd_SetCursorPosition(u8 row, u8 column);
void Lcd_ShiftDisplayLeft(u8 count);
void Lcd_ShiftDisplayRight(u8 count);
void Lcd_ShiftCursorLeft(u8 count);
void Lcd_ShiftCursorRight(u8 count);
void Lcd_ReturnHome(void);
void Lcd_ControlDisplay(const Lcd_DisplayControlType* control);
void Lcd_SaveSpecialCharacter(u8 location, u8* pattern);
void Lcd_Print(char* str, ...);

#endif /* HAL_LCD_LCD_H_ */
