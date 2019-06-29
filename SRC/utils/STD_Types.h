/*
 * STD_Types.h
 *
 *  Created on: Jun 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_LAB_SRC_UTILS_STD_TYPES_H_
#define E15_LAB_SRC_UTILS_STD_TYPES_H_

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;

typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;

typedef float float32;

typedef enum
{
	STD_low,
	STD_high
}STD_levelType;

typedef enum
{
	false,
	true
}boolean;

#define ENABLE			1
#define DISABLE			0

#endif /* E15_LAB_SRC_UTILS_STD_TYPES_H_ */
