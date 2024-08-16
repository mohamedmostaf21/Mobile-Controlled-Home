#ifndef BIT_MATH_H
#define BIT_MATH_H

#include "STD_TYPES.h"

#define CLR_BIT(byte, pos) 		( (byte) &= ~(1 << (pos) ) )
#define SET_BIT(byte, pos) 			( (byte) |= (1 << (pos) ) )
#define TOGGLE_BIT(byte, pos) 		( (byte) ^= (1 << (pos) ) )
#define GET_BIT(byte, pos) 		 	( (byte >> pos) & 1  ) 
#define  L_UTILS_SET_BIT_VALUE(REG,BIT,Value) ( (Value == 0) ? ( REG &= ~(1<<BIT) ) : ( REG |= (1<<BIT) ) )

#endif /* BIT_MATH_H */
