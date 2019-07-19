/*
 * TIMER1_hw.h
 *
 *  Created on: Jul 19, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_MCAL_TIMER1_TIMER1_HW_H_
#define E15_REPO_SRC_MCAL_TIMER1_TIMER1_HW_H_


#define TCCR1A			*((volatile uint8*)0x4F)
#define TCCR1B			*((volatile uint8*)0x4E)
#define TCNT1			*((volatile uint16*)0x4C)
#define OCR1A			*((volatile uint16*)0x4A)
#define OCR1B			*((volatile uint16*)0x48)
#define ICR1			*((volatile uint16*)0x46)
#define TIMSK			*((volatile uint8*)0x59)
#define TIFR			*((volatile uint8*)0x58)

/*
* address of TCNT1H ==> 0x4D
* address of TCNT1L ==> 0x4C
*/
#endif /* E15_REPO_SRC_MCAL_TIMER1_TIMER1_HW_H_ */
