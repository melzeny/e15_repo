/*
 * TIMER0_cfg.h
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_CONFIG_TIMER0_CFG_H_
#define F15_REPO_SRC_CONFIG_TIMER0_CFG_H_


#define TIMER0_PRESCALER_SELECTOR_msk		TIMER0_PRESCALER_1024_msk
#define TIMER0_STEPS_TO_COUNT				250
/*
 * Choose mode from following list:-
 *
 * TIMER0_MODE_NORMAL_msk
 * TIMER0_MODE_PHASE_CORRECT_msk
 * TIMER0_MODE_CTC_msk
 * TIMER0_MODE_FAST_PWM_msk
 * */
#define TIMER0_MODE_TYPE_SELECTOR_msk		TIMER0_MODE_CTC_msk




#endif /* F15_REPO_SRC_CONFIG_TIMER0_CFG_H_ */
