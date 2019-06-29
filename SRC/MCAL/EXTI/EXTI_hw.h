/*
 * EXTI_hw.h
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_MCAL_EXTI_EXTI_HW_H_
#define E15_REPO_SRC_MCAL_EXTI_EXTI_HW_H_

#define MCUCR					*((volatile uint8*)0x55)
#define MCUCSR					*((volatile uint8*)0x54)
#define GICR					*((volatile uint8*)0x5B)
#define GIFR					*((volatile uint8*)0x5A)

#endif /* E15_REPO_SRC_MCAL_EXTI_EXTI_HW_H_ */
