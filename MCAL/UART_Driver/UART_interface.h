/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_interface.h
 *
 * Description: Header file for the  UART 
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"
/*******************************************************************************
 *                      Functions Prototypes                                   *
*******************************************************************************/

/*********************************************************************************/
/* Function: UART_voidInit
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  void
 * Description:	This Function used to initialized UART.
 */
/*********************************************************************************/
void UART_voidInit(void);


/*********************************************************************************/
/* Function: UART_voidSendData_Asynch
 * Input/outPut Parameters:
 * 			 INPUT : Copy_u8Data
 *
 * Returns:  void
 * Description:	This Function used to send data using UART interrupt.
 */
/*********************************************************************************/
void UART_voidSendData_Asynch(u8 Copy_u8Data);



/*********************************************************************************/
/* Function: UART_u8ReceiveData
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  u8
 * Description:	This Function used to receive data from UART .
 */
/*********************************************************************************/
u8  UART_ReceiveData(void);




void UARTTX_vidSetISR(void (*p)(void));   //CallBack for Tx
void UARTRX_vidSetISR(void (*p)(void));     //CallBack for Rx
void disable_tx(void);        /*disable tx*/
void enable_tx(void);  /*enable tx*/
#endif
