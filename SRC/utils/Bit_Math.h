/*
 * Bit_Math.h
 *
 *  Created on: Jun 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_LAB_SRC_UTILS_BIT_MATH_H_
#define E15_LAB_SRC_UTILS_BIT_MATH_H_

#define SET_BIT(u8Var,BitNo)		u8Var |= (1<<BitNo)
#define CLR_BIT(u8Var,BitNo)		u8Var &= ~(1<<BitNo)
#define TOGGLE_BIT(u8Var,BitNo)		u8Var ^= (1<<BitNo)
#define GET_BIT(u8Var,BitNo)		(u8Var >> BitNo) & 0x01


#endif /* E15_LAB_SRC_UTILS_BIT_MATH_H_ */
