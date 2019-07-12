/*
 * compiler.h
 *
 *  Created on: Jul 1, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_UTILS_COMPILER_H_
#define E15_REPO_SRC_UTILS_COMPILER_H_

#define EXTI_INT0				   	__vector_1
#define EXTI_INT1				   	__vector_2
#define EXTI_INT2				   	__vector_3
#define TIMER0_COMP					__vector_10
#define TIMER0_OVF					__vector_11
#define TIMER2_OVF					__vector_5
#define TIMER2_COMP					__vector_4
#define ISR(vector)				   	vector(void) __attribute__((signal,used));\
									void vector(void)



#endif /* E15_REPO_SRC_UTILS_COMPILER_H_ */
