/******************************************************************************
 *
 * Module: UART
 *
 * File Name: UART_program.c
 *
 * Description: Header file for the  UART 
 *
 * Author: Elsayed Mohamed Shalby
 *
 *******************************************************************************/
#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

volatile u8 Global_Var=0;
void (*Tx_pf)(void)=NULL;
void (*Rx_pf)(void)=NULL;
u8 Data=0;



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
void UART_voidInit(void)
{
	u8 Local_Temp=0;
/******   Enable Rx Interrupt (RXCIE)   *******/
SET_BIT(UCSRB,UCSRB_RXCIE);
/******   Enable UDRIE          *******/
SET_BIT(UCSRB,UCSRB_UDRIE);

/******   Select 8-BIT Data *********/
CLR_BIT(UCSRB,UCSRB_UCSZ2);
/*select UCSRC Register*/
SET_BIT(Local_Temp,UCSRC_URSEL);
SET_BIT(Local_Temp,UCSRC_UCSZ0);
SET_BIT(Local_Temp,UCSRC_UCSZ1);
/******  Select UART Mode *********/
CLR_BIT(Local_Temp,UCSRC_UMSEL);//select  Asynchronous Mode
/******   Select Parity Mode *********/
CLR_BIT(Local_Temp,UCSRC_UPM0);//disable Parity
CLR_BIT(Local_Temp,UCSRC_UPM1);
/******   Select Stop bit *********/
CLR_BIT(Local_Temp,UCSRC_USBS);

UCSRC=Local_Temp;

/******   Select BuadRate *********/
UBRRL=BUAD_RATE;
/******   Enable Rx *********/
SET_BIT(UCSRB,UCSRB_RXEN);
/******   Enable Tx *********/
SET_BIT(UCSRB,UCSRB_TXEN);
}






/*********************************************************************************/
/* Function: UART_voidSendData_Asynch
 * Input/outPut Parameters:
 * 			 INPUT : Copy_u8Data
 *
 * Returns:  void
 * Description:	This Function used to send data using UART interrupt.
 */
/*********************************************************************************/
void UART_voidSendData_Asynch(u8 Copy_u8Data)
{
//Global_Var =Copy_u8Data;
UDR =Copy_u8Data;
}




/*********************************************************************************/
/* Function: UART_u8ReceiveData
 * Input/outPut Parameters:
 * 			NO INPUT : void
 *
 * Returns:  u8
 * Description:	This Function used to receive data from UART .
 */
/*********************************************************************************/
u8  UART_ReceiveData(void)
{
//GET_BIT(UCSRA,UCSRA_RXC);
return UDR;
}


// USART, RXC
void __vector_13 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_13 (void)
{
	Rx_pf();
}
// USART, UDRE
void __vector_14 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_14 (void)
{
	Tx_pf();
	//UART_voidSendData_Asynch();
}
//USART, TXC
void __vector_15 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_15 (void){

}
void UARTTX_vidSetISR(void (*p)(void))
{
	Tx_pf=p;
	//Data=value;
	}
void UARTRX_vidSetISR(void (*p)(void))
{
	Rx_pf=p;
	//Data=value;
	}




void disable_tx(void)
{
	CLR_BIT(UCSRB,UCSRB_UDRIE);

}
	
	
void enable_tx(void)
{
	SET_BIT(UCSRB,UCSRB_UDRIE);

}
