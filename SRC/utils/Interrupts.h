/*
 * compiler.h
 *
 *  Created on: Jul 1, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_UTILS_INTERRUPTS_H_
#define E15_REPO_SRC_UTILS_INTERRUPTS_H_

#define EXTI_INT0				   	__vector_1
#define EXTI_INT1				   	__vector_2
#define EXTI_INT2				   	__vector_3
#define TIMER2_COMP					__vector_4
#define TIMER2_OVF					__vector_5
#define TIMER0_COMP					__vector_10
#define TIMER0_OVF					__vector_11
#define TIMER1_CAPT					__vector_6
#define TIMER1_COMPA				__vector_7
#define TIMER1_COMPB				__vector_8
#define TIMER1_OVF					__vector_9


#define ISR(vector)				   	vector(void) __attribute__((signal,used));\
									void vector(void)

#define TIMER2_COMP_USER			0


#endif /* E15_REPO_SRC_UTILS_INTERRUPTS_H_ */
