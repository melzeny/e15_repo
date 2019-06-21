/*
 * PORT_hw.h
 *
 *  Created on: Jun 15, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_LAB_SRC_MCAL_PORT_DRIVER_PORT_HW_H_
#define E15_LAB_SRC_MCAL_PORT_DRIVER_PORT_HW_H_

#define DDRA_REG		*((volatile uint8*)0x3A)
#define DDRB_REG		*((volatile uint8*)0x37)
#define DDRC_REG		*((volatile uint8*)0x34)
#define DDRD_REG		*((volatile uint8*)0x31)

#define PORTA_REG		*((volatile uint8*)0x3B)
#define PORTB_REG		*((volatile uint8*)0x38)
#define PORTC_REG		*((volatile uint8*)0x35)
#define PORTD_REG		*((volatile uint8*)0x32)

#endif /* E15_LAB_SRC_MCAL_PORT_DRIVER_PORT_HW_H_ */
