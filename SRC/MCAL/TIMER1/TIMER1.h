/*
 * TIMER1.h
 *
 *  Created on: Jul 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_MCAL_TIMER1_TIMER1_H_
#define E15_REPO_SRC_MCAL_TIMER1_TIMER1_H_

#include "../../utils/STD_Types.h"
#include "TIMER1_types.h"

void TIMER1_init(void);
void TIMER1_enInterrupt(TIMER1_IntType Int);
void TIMER1_diInterrupt(TIMER1_IntType Int);
void TIMER1_readPwm(uint32* FreqPtr_Khz,uint8* DutyCyclePtr);

#endif /* E15_REPO_SRC_MCAL_TIMER1_TIMER1_H_ */
