/*
 * SEV_priv.h
 *
 *  Created on: Jul 30, 2024
 *      Author: Mohamed
 */

#ifndef HAL_SEVEN_SEGMENT_SEV_PRIV_H_
#define HAL_SEVEN_SEGMENT_SEV_PRIV_H_



#define Common_Cathode     0
#define Common_Anode       1

typedef struct 
{
    u8 Au8Pin[7];
    u8 common;
    u8 common_mode;
}Sev_config;

extern Sev_config SEV_ConfigSet[MAX_SEV_SEGMENT];
static void PutOnBus(u8 u8sevIndex, u8 u8num);


#endif /* HAL_SEVEN_SEGMENT_SEV_PRIV_H_ */
