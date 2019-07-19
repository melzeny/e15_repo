/*
 * Scheduler_cgf.h
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_CONFIG_SCHEDULER_CFG_H_
#define E15_REPO_SRC_CONFIG_SCHEDULER_CFG_H_

/*==========================================================================================
 * Scheduler Dependencies
 *	Timer0 Driver : 1- Timer0 shall be configured to INTERRUPT CPU every system tick
 *e.g. for sys-tick = 10ms in MCU with system frequency = 16MHz,
 *		the following parameter shall be configures as follows:-
 *
 *		TIMER0_PRESCALER_SELECTOR_msk ===> TIMER0_PRESCALER_1024_msk
 *		TIMER0_MODE_TYPE_SELECTOR_msk ===> TIMER0_MODE_CTC_msk
 *		TIMER0_MODE_TYPE_SELECTOR_msk ===> TIMER0_MODE_CTC_msk
 *=======================================================================================*/


#define SCHEDULER_MAX_NO_OF_TASKS				6

#endif /* E15_REPO_SRC_CONFIG_SCHEDULER_CFG_H_ */
