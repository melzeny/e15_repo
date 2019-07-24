/*
 * TIMER2_cfg.h
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef F15_REPO_SRC_CONFIG_TIMER2_CFG_H_
#define F15_REPO_SRC_CONFIG_TIMER2_CFG_H_

/*
 * Choose one of the following prescaler
 * TIMER2_PRESCALER_1_msk
 * TIMER2_PRESCALER_8_msk
 * TIMER2_PRESCALER_32_msk
 * TIMER2_PRESCALER_64_msk
 * TIMER2_PRESCALER_128_msk
 * TIMER2_PRESCALER_256_msk
 * TIMER2_PRESCALER_1024_msk
 *
 * */

#define TIMER2_PRESCALER_SELECTOR_msk		TIMER2_PRESCALER_128_msk
#define TIMER2_STEPS_TO_COUNT				125
/*
 * Choose mode from following list:-
 *
 * TIMER2_MODE_NORMAL_msk
 * TIMER2_MODE_PHASE_CORRECT_msk
 * TIMER2_MODE_CTC_msk
 * TIMER2_MODE_FAST_PWM_msk
 * */
#define TIMER2_MODE_TYPE_SELECTOR_msk		TIMER2_MODE_CTC_msk

/*
 * TIMER2_NON_PWM_OC2_DISBALE
 * TIMER2_NON_PWM_OC2_TOGGLE
 * TIMER2_NON_PWM_OC2_CLR
 * TIMER2_NON_PWM_OC2_SET
 * */

#define TIMER2_OC2_PIN_MODE_NON_PWM			TIMER2_NON_PWM_OC2_TOGGLE

/*
*TIMER2_PWM_OC2_DISBALE
*TIMER2_PWM_OC2_NON_INVERTING    (start with high level)
*TIMER2_PWM_OC2_INVERTING
*/
#define TIMER2_OC2_PIN_MODE_PWM				TIMER2_PWM_OC2_NON_INVERTING



#endif /* F15_REPO_SRC_CONFIG_TIMER2_CFG_H_ */
