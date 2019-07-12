/*
 * TIMER2_cfg.h
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_CONFIG_TIMER2_CFG_H_
#define F15_REPO_SRC_CONFIG_TIMER2_CFG_H_


#define TIMER2_PRESCALER_SELECTOR_msk		TIMER2_PRESCALER_64_msk
#define TIMER2_STEPS_TO_COUNT				250
/*
 * Choose mode from following list:-
 *
 * TIMER2_MODE_NORMAL_msk
 * TIMER2_MODE_PHASE_CORRECT_msk
 * TIMER2_MODE_CTC_msk
 * TIMER2_MODE_FAST_PWM_msk
 * */
#define TIMER2_MODE_TYPE_SELECTOR_msk		TIMER2_MODE_CTC_msk




#endif /* F15_REPO_SRC_CONFIG_TIMER2_CFG_H_ */
