/*
 * SEV.h
 *
 *  Created on: Jul 30, 2024
 *      Author: k.m
 */

#ifndef HAL_SEVEN_SEGMENT_SEV_H_
#define HAL_SEVEN_SEGMENT_SEV_H_

/************** prototypes **************/
tenuErrorStatus Sev_Display(u8 u8sevIndex, u8 u8num);
tenuErrorStatus Sev_PowerOn(u8 u8sevIndex);
tenuErrorStatus Sev_PowerOff(u8 u8sevIndex);

#endif /* HAL_SEVEN_SEGMENT_SEV_H_ */
