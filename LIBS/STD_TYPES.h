#ifndef STD_TYPES_H
#define STD_TYPES_H

#include <stdio.h>
// ****** standard datatypes  ******//
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef long double lf128;
typedef unsigned long long int u64;
#define NULL_PTR	((void*)0)
typedef enum{
	EOK,
	PARAM_OUT_RANGE,
	PARAM_NULL_PTR
}tenuErrorStatus;
#define HWREG8(_REG)		(*((volatile u8*) _REG))
#define HWREG16(_REG)		(*((volatile u16*) _REG))
#define HWREG32(_REG)		(*((volatile u32*) _REG))

typedef enum{
	E_NOT_OK,
	E_OK
}Std_ReturnType;

#endif /* STD_TYPES_H */
