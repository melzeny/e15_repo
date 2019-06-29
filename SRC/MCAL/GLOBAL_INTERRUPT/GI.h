/*
 * GI.h
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_MCAL_GLOBAL_INTERRUPT_GI_H_
#define E15_REPO_SRC_MCAL_GLOBAL_INTERRUPT_GI_H_

#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
/*
#define SREG			*((volatile uint8*)0x5F)
*/
#define GI_EN()			SET_BIT(*((uint8*)0x5F),7)
#define GI_DI()			CLR_BIT(*((uint8*)0x5F),7)

#endif /* E15_REPO_SRC_MCAL_GLOBAL_INTERRUPT_GI_H_ */
