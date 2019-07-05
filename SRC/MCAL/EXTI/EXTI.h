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


#endif /* E15_REPO_SRC_MCAL_EXTI_EXTI_H_ */
