/**************************************/
/* Description : DIO program file     */
/* Author      : Mohamed Mostafa        */
/* Version     : 0.1v                 */
/* Date        : 29 july 2024         */
/* History     : 0.1v initial creation*/
/**************************************/



#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"


#include "DIO.h"
#include "DIO_cfg.h"
#include "DIO_priv.h"



void DIO_voidInit(void)
{
   DDRA = CONC(DIO_PIN_DIR_7 ,DIO_PIN_DIR_6 ,DIO_PIN_DIR_5 ,DIO_PIN_DIR_4 ,DIO_PIN_DIR_3 ,DIO_PIN_DIR_2 ,DIO_PIN_DIR_1 ,DIO_PIN_DIR_0 );
   DDRB = CONC(DIO_PIN_DIR_15,DIO_PIN_DIR_14,DIO_PIN_DIR_13,DIO_PIN_DIR_12,DIO_PIN_DIR_11,DIO_PIN_DIR_10,DIO_PIN_DIR_9 ,DIO_PIN_DIR_8 );
   DDRC = CONC(DIO_PIN_DIR_23,DIO_PIN_DIR_22,DIO_PIN_DIR_21,DIO_PIN_DIR_20,DIO_PIN_DIR_19,DIO_PIN_DIR_18,DIO_PIN_DIR_17,DIO_PIN_DIR_16);
   DDRD = CONC(DIO_PIN_DIR_31,DIO_PIN_DIR_30,DIO_PIN_DIR_29,DIO_PIN_DIR_28,DIO_PIN_DIR_27,DIO_PIN_DIR_26,DIO_PIN_DIR_25,DIO_PIN_DIR_24);

}
//sets data direction of 1 pin in a port
void DIO_vSetPinDir(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8PinDir){
	if(Copy_u8PinDir == DIO_OUTPUT)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: SET_BIT(DDRA, Copy_u8PinNum); break;
		case PORTB: SET_BIT(DDRB, Copy_u8PinNum); break;
		case PORTC: SET_BIT(DDRC, Copy_u8PinNum); break;
		case PORTD: SET_BIT(DDRD, Copy_u8PinNum); break;
		}
	}
	else if(Copy_u8PinDir == DIO_INPUT)
	{
		switch(Copy_u8PortName)
		{
		case PORTA: CLR_BIT(DDRA, Copy_u8PinNum); break;
		case PORTB: CLR_BIT(DDRB, Copy_u8PinNum); break;
		case PORTC: CLR_BIT(DDRC, Copy_u8PinNum); break;
		case PORTD: CLR_BIT(DDRD, Copy_u8PinNum); break;
		}
	}
}
void DIO_InitCertainPort(u8 PORT)
{
	if(PORT == ODRA){
		DDRA = CONC(DIO_PIN_DIR_7 ,DIO_PIN_DIR_6 ,DIO_PIN_DIR_5 ,DIO_PIN_DIR_4 ,DIO_PIN_DIR_3 ,DIO_PIN_DIR_2 ,DIO_PIN_DIR_1 ,DIO_PIN_DIR_0 );
	}else if(PORT == ODRB){
		DDRB = CONC(DIO_PIN_DIR_15,DIO_PIN_DIR_14,DIO_PIN_DIR_13,DIO_PIN_DIR_12,DIO_PIN_DIR_11,DIO_PIN_DIR_10,DIO_PIN_DIR_9 ,DIO_PIN_DIR_8 );
	}else if(PORT == ODRC){
		DDRC = CONC(DIO_PIN_DIR_23,DIO_PIN_DIR_22,DIO_PIN_DIR_21,DIO_PIN_DIR_20,DIO_PIN_DIR_19,DIO_PIN_DIR_18,DIO_PIN_DIR_17,DIO_PIN_DIR_16);
	}else if(PORT == ODRD){
		DDRD = CONC(DIO_PIN_DIR_31,DIO_PIN_DIR_30,DIO_PIN_DIR_29,DIO_PIN_DIR_28,DIO_PIN_DIR_27,DIO_PIN_DIR_26,DIO_PIN_DIR_25,DIO_PIN_DIR_24);
	}
	return;
}



tenuErrorStatus DIO_enuWritePin(u8 u8PinNumCpy,u8 u8PinValueCpy)
{

	tenuErrorStatus enuReturnStateLoc = EOK;
	if (u8PinNumCpy >= DIO_PIN_NUM_0 && u8PinNumCpy <= DIO_PIN_NUM_7)
	{
		switch (u8PinValueCpy)
		{
			case DIO_LOW :
			 CLR_BIT (ODRA ,  u8PinNumCpy);
			break;
			case DIO_HIGH :
			 SET_BIT(ODRA , u8PinNumCpy);
			break ;
			default :
			enuReturnStateLoc = PARAM_OUT_RANGE ;
		}
	}
	else if (u8PinNumCpy >= DIO_PIN_NUM_8 && u8PinNumCpy <= DIO_PIN_NUM_15)
	{
		switch (u8PinValueCpy)
		{
			case DIO_LOW :
			 CLR_BIT (ODRB ,  u8PinNumCpy%8); //0 1 2 3 4 5 6 7 => 8%8 = 0, 9%8 = 1, 10%8 = 2, 11%8 = 3, 12%8 = 4, 13%8 = 5, 14%8 = 6, 15%8 = 7
			break;
			case DIO_HIGH :
			 SET_BIT(ODRB , u8PinNumCpy%8);
			break ;
			default :
			enuReturnStateLoc = PARAM_OUT_RANGE ;
		}
	}
	else if (u8PinNumCpy >= DIO_PIN_NUM_16 && u8PinNumCpy <= DIO_PIN_NUM_23)
	{
		switch (u8PinValueCpy)
		{
			case DIO_LOW :
			 CLR_BIT (ODRC ,  u8PinNumCpy%16);
			break;
			case DIO_HIGH :
			 SET_BIT(ODRC , u8PinNumCpy%16);
			break ;
			default :
			enuReturnStateLoc = PARAM_OUT_RANGE ;
		}
	}
	else if (u8PinNumCpy >= DIO_PIN_NUM_24 && u8PinNumCpy <= DIO_PIN_NUM_31)
	{
		switch (u8PinValueCpy)
		{
			case DIO_LOW :
			 CLR_BIT (ODRD ,  u8PinNumCpy%24);
			break;
			case DIO_HIGH :
			 SET_BIT(ODRD , u8PinNumCpy%24);
			break ;
			default :
			enuReturnStateLoc = PARAM_OUT_RANGE ;
		}
	}
	else
	{
		enuReturnStateLoc = PARAM_OUT_RANGE ;
	}

	return enuReturnStateLoc ;

}
//#define GET_BIT(byte,pos) ( (byte >> pos) & 1 )
//4 => 0100 
//GET_BIT(4, 1)     0100 >> 1 = 00010 & 0001 = 0

tenuErrorStatus DIO_enuReadPin(u8 u8PinNumCpy ,u8 *pu8PinValueCpy )
{
	tenuErrorStatus  enuReturnStateLoc = EOK;

	if (pu8PinValueCpy != NULL_PTR)
	{
		//IDR
		if (u8PinNumCpy >= DIO_PIN_NUM_0 && u8PinNumCpy <= DIO_PIN_NUM_7)
		{
			*pu8PinValueCpy  = GET_BIT(IDRA , u8PinNumCpy);
		}
		else if (u8PinNumCpy >= DIO_PIN_NUM_8 && u8PinNumCpy <= DIO_PIN_NUM_15)
		{
			*pu8PinValueCpy  = GET_BIT(IDRB , u8PinNumCpy%8);
		}
		else if (u8PinNumCpy >= DIO_PIN_NUM_16 && u8PinNumCpy <= DIO_PIN_NUM_23)
		{
			*pu8PinValueCpy  = GET_BIT(IDRC , u8PinNumCpy%16);
		}
		else if (u8PinNumCpy >= DIO_PIN_NUM_24 && u8PinNumCpy <= DIO_PIN_NUM_31)
		{
			*pu8PinValueCpy  = GET_BIT(IDRD , u8PinNumCpy%24);
		}
		else
		{
			enuReturnStateLoc = PARAM_OUT_RANGE ;
		}
	}
	else
	{
		enuReturnStateLoc = PARAM_NULL_PTR ;
	}

	return enuReturnStateLoc ;

}

tenuErrorStatus DIO_enuStatePullup(u8 u8PinNumCpy, u8 u8StateCpy)
{
   return DIO_enuWritePin(u8PinNumCpy,u8StateCpy);
}



tenuErrorStatus DIO_enuWriteGroup(u8 *pau8PinNumCpy,u8 * pau8PinValueCpy , u8 u8SizeCpy)
{
	tenuErrorStatus enuReturnStateLoc = EOK;
	u8 u8CntrLoc;
	for (u8CntrLoc = 0 ; u8CntrLoc < u8SizeCpy ; u8CntrLoc++)
	{
		enuReturnStateLoc = DIO_enuWritePin(pau8PinNumCpy[u8CntrLoc],pau8PinValueCpy[u8CntrLoc]);
		if (enuReturnStateLoc != EOK)
		{
			break;
		}
	}
	return enuReturnStateLoc;
}

