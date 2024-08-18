/*
 * SEV.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Mohamed
 */
#include "../../LIBS/STD_TYPES.h"
#include "../../LIBS/BIT_MATH.h"
#include "../../MCAL/DIO/DIO.h"
#include "SEV.h"
#include "SEV_cfg.h"
#include "SEV_priv.h"



tenuErrorStatus Sev_Display(u8 u8sevIndex, u8 u8num){
    tenuErrorStatus enuReturnLoc = EOK;
    u8 au8Cathode[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    if(u8sevIndex < MAX_SEV_SEGMENT){
        if(u8num < 10){
            if(SEV_ConfigSet[u8sevIndex].common_mode == Common_Cathode){
            	PutOnBus(u8sevIndex, au8Cathode[u8num]);
            }
            else{
            	PutOnBus(u8sevIndex, ~au8Cathode[u8num]);
            }
        }
    }else{
        enuReturnLoc = PARAM_OUT_RANGE;
    }
    return enuReturnLoc;
}

static void PutOnBus(u8 u8sevIndex, u8 u8num){
    u8 u8Num[7]; //0x0011 1111
	u8 cntr;
	for(cntr = 0; cntr < 7; cntr++){
		u8Num[cntr] = GET_BIT(u8num, cntr);
	}
    DIO_enuWriteGroup(SEV_ConfigSet[u8sevIndex].Au8Pin, u8Num, 7 );
}

tenuErrorStatus Sev_PowerOn(u8 u8sevIndex){
    tenuErrorStatus enuReturnLoc = EOK;
    
    if(u8sevIndex < MAX_SEV_SEGMENT){
        if(SEV_ConfigSet[u8sevIndex].common_mode == Common_Cathode){
            enuReturnLoc = DIO_enuWritePin(SEV_ConfigSet[u8sevIndex].common, Common_Cathode);
        }else{
        	 enuReturnLoc = DIO_enuWritePin(SEV_ConfigSet[u8sevIndex].common, Common_Anode);
        }
       
    }else{
        enuReturnLoc = PARAM_OUT_RANGE;
    }
    return enuReturnLoc;
}

tenuErrorStatus Sev_PowerOff(u8 u8sevIndex){
    tenuErrorStatus enuReturnLoc = EOK;
    
    if(u8sevIndex < MAX_SEV_SEGMENT){
        if(SEV_ConfigSet[u8sevIndex].common_mode == Common_Cathode){
        	 enuReturnLoc = DIO_enuWritePin(SEV_ConfigSet[u8sevIndex].common, Common_Anode);
        }else{
        	 enuReturnLoc = DIO_enuWritePin(SEV_ConfigSet[u8sevIndex].common, Common_Cathode);
        }
       
    }else{
        enuReturnLoc = PARAM_OUT_RANGE;
    }
    return enuReturnLoc;
}
