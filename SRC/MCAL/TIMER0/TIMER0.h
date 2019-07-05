/*
 * TIMER0.h
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_MCAL_TIMER0_TIMER0_H_
#define F15_REPO_SRC_MCAL_TIMER0_TIMER0_H_

#include "../../utils/STD_Types.h"

void TIMER0_init(void);
void TIMER0_enInterrupt(void);
void TIMER0_diInterrupt(void);
void TIMER0_setCounterSteps(uint8 StepsToCount);
uint8 TIMER0_readCounterSteps(void);

#endif /* F15_REPO_SRC_MCAL_TIMER0_TIMER0_H_ */
