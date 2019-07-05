/*
 * TIMER0.c
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */
/*
 * =============================================
 * Private Defines
 * ============================================*/
#define TIMER0_PRESCALER_CLR_msk		0b11111000
#define TIMER0_PRESCALER_1_msk			0b00000001
#define TIMER0_PRESCALER_8_msk			0b00000010
#define TIMER0_PRESCALER_64_msk			0b00000011
#define TIMER0_PRESCALER_256_msk		0b00000100
#define TIMER0_PRESCALER_1024_msk		0b00000101

#define TIMER0_MODE_CLR_msk				0b10110111
#define TIMER0_MODE_NORMAL_msk			0b00000000
#define TIMER0_MODE_PHASE_CORRECT_msk	0b01000000
#define TIMER0_MODE_CTC_msk				0b00001000
#define TIMER0_MODE_FAST_PWM_msk		0b01001000
/* =============================================
 * INCLUDES
 * ============================================*/
#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "../../config/TIMER0_cfg.h"
#include "TIMER0_hw.h"
#include "TIMER0.h"

/* =============================================
 * FUNCTIONS DEFINITIONS
 * ============================================*/
void TIMER0_init(void)
{

	/* set timer mode */
	TCCR0 &= TIMER0_MODE_CLR_msk;
	TCCR0 |= TIMER0_MODE_TYPE_SELECTOR_msk;

	/*set Steps to count */
	TIMER0_setCounterSteps(TIMER0_STEPS_TO_COUNT);

	/*enable Interrupt */
	TIMER0_enInterrupt();

	/*set Pre-scaler*/
	TCCR0 &= TIMER0_PRESCALER_CLR_msk;
	TCCR0 |= TIMER0_PRESCALER_SELECTOR_msk;

}

void TIMER0_enInterrupt(void)
{
#if TIMER0_MODE_TYPE_SELECTOR_msk == TIMER0_MODE_CTC_msk
	SET_BIT(TIMSK,1);
#elif
	SET_BIT(TIMSK,0);
#endif
}
void TIMER0_diInterrupt(void)
{
#if TIMER0_MODE_TYPE_SELECTOR_msk == TIMER0_MODE_CTC_msk
	CLR_BIT(TIMSK,1);
#elif
	CLR_BIT(TIMSK,0);
#endif
}
void TIMER0_setCounterSteps(uint8 StepsToCount)
{
#if TIMER0_MODE_TYPE_SELECTOR_msk == TIMER0_MODE_CTC_msk
	OCR0 = StepsToCount;
	TCNT0 = 0x00 ;
#elif TIMER0_MODE_TYPE_SELECTOR_msk == TIMER0_MODE_NORMAL_msk
	TCNT0 = 255 - StepsToCount;
#endif
}
uint8 TIMER0_readCounterSteps(void)
{
	return TCNT0;
}
