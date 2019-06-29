/*
 * EXTI.h
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_MCAL_EXTI_EXTI_H_
#define E15_REPO_SRC_MCAL_EXTI_EXTI_H_

#include "EXTI_Types.h"

void EXTI_init(void);
void EXTI_setEdge(EXTI_IntType IntNum,EXTI_EdgeType Edge);
void EXTI_enInterrupt(EXTI_IntType IntNum);
void EXTI_diInterrupt(EXTI_IntType IntNum);

#define EXTI_INT0_ISR(void)			__vector_1(void) __attribute__((signal,used));\
									void __vector_1(void)
#define EXTI_INT1_ISR(void)			__vector_2(void) __attribute__((signal,used));\
									void __vector_2(void)
#define EXTI_INT2_ISR(void)			__vector_3(void) __attribute__((signal,used));\
									void __vector_3(void)
#endif /* E15_REPO_SRC_MCAL_EXTI_EXTI_H_ */
