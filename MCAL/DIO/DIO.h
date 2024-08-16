/**************************************/
/* Description : DIO interface file   */
/* Author      : Mohamed Mostafa        */
/* Version     : 0.1v                 */
/* Date        : 29 july 2024         */
/* History     : 0.1v initial creation*/
/**************************************/
#ifndef DIO_H
#define DIO_H
//
#include "../../LIBS/STD_TYPES.h"
#define DIO_LOW    0
#define DIO_HIGH   1


#define DIO_DEACTIVATE    0
#define DIO_ACTIVATE      1

#define DIO_PIN_NUM_0   0
#define DIO_PIN_NUM_1   1
#define DIO_PIN_NUM_2   2
#define DIO_PIN_NUM_3   3
#define DIO_PIN_NUM_4   4
#define DIO_PIN_NUM_5   5
#define DIO_PIN_NUM_6   6
#define DIO_PIN_NUM_7   7
#define DIO_PIN_NUM_8   8
#define DIO_PIN_NUM_9   9
#define DIO_PIN_NUM_10  10
#define DIO_PIN_NUM_11  11
#define DIO_PIN_NUM_12  12
#define DIO_PIN_NUM_13  13
#define DIO_PIN_NUM_14  14
#define DIO_PIN_NUM_15  15

#define DIO_PIN_NUM_16  16
#define DIO_PIN_NUM_17  17
#define DIO_PIN_NUM_18  18
#define DIO_PIN_NUM_19  19
#define DIO_PIN_NUM_20  20
#define DIO_PIN_NUM_21  21
#define DIO_PIN_NUM_22  22
#define DIO_PIN_NUM_23  23

#define DIO_PIN_NUM_24  24
#define DIO_PIN_NUM_25  25
#define DIO_PIN_NUM_26  26
#define DIO_PIN_NUM_27  27
#define DIO_PIN_NUM_28  28
#define DIO_PIN_NUM_29  29
#define DIO_PIN_NUM_30  30
#define DIO_PIN_NUM_31  31


#include "DIO_priv.h"
/**
 * @brief Initializes the DIO direction registers for all ports (A to D).
 *
 * @param None.
 *
 * @return None.
 */
void DIO_voidInit(void);
//sets data direction of 1 pin in a port
void DIO_vSetPinDir(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8PinDir);

void DIO_InitCertainPort(u8 PORT);
/**
 * @brief Writes a value (DIO_LOW or DIO_HIGH) to a specified DIO pin.
 *
 * @param pinNum Pin number to write (0 to 31).
 * @param pinVal Value to write (DIO_LOW or DIO_HIGH).
 *
 * @return tenuErrorStatus Returns EOK if successful, PARAM_OUT_RANGE if parameters are out of range.
 */
tenuErrorStatus DIO_enuWritePin(u8 u8PinNumCpy,u8 u8PinValueCpy);


/**
 * @brief Reads the current value of a DIO pin.
 *
 * @param pinNum Pin number to read (0 to 31).
 * @param pinVal Pointer to store the read value (DIO_LOW or DIO_HIGH).
 *
 * @return tenuErrorStatus Returns EOK if successful, PARAM_OUT_RANGE if parameters are out of range, PARAM_NULL_PTR if pinVal is NULL.
 */
tenuErrorStatus DIO_enuReadPin(u8 u8PinNumCpy ,u8 *pu8PinValueCpy);


/**
 * @brief Sets the state (DIO_LOW or DIO_HIGH) of a DIO pin for pull-up or pull-down.
 *
 * @param pinNum Pin number to set state (0 to 31).
 * @param state State to set (DIO_LOW or DIO_HIGH).
 *
 * @return tenuErrorStatus Returns result of DIO_WritePin function.
 */
tenuErrorStatus DIO_enuStatePullup(u8 u8PinNumCpy, u8 u8StateCpy);



/**
 * @brief Writes values to a group of DIO pins.
 *
 * @param pinNum Array of pin numbers to write.
 * @param pinVal Array of values to write.
 * @param size Number of elements in pinNum and pinVal arrays.
 *
 * @return tenuErrorStatus Returns EOK if successful, PARAM_OUT_RANGE if parameters are out of range.
 */

tenuErrorStatus DIO_enuWriteGroup(u8 *pau8PinNumCpy,u8 *pau8PinValueCpy , u8 u8SizeCpy);

#endif
