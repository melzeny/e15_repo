/*
 * EXTI_Types.h
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_MCAL_EXTI_EXTI_TYPES_H_
#define E15_REPO_SRC_MCAL_EXTI_EXTI_TYPES_H_

typedef enum
{
	EXTI_Edge_Falling,
	EXTI_Edge_Rising,
	EXTI_Edge_OnChange
}EXTI_EdgeType;

typedef enum
{
	EXTI_INT0,
	EXTI_INT1,
	EXTI_INT2
}EXTI_IntType;


#endif /* E15_REPO_SRC_MCAL_EXTI_EXTI_TYPES_H_ */
