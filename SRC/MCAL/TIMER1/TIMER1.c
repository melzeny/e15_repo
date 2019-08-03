/*
 * TIMER1.c
 *
 *  Created on: Jul 19, 2019
 *      Author: Muhammad.Elzeiny
 */
/*================================
 * Defines
 * ===============================*/
#define	TIMER1_PRESCALER_clr_msk		0b11111000
#define TIMER1_PRESCALER_1_msk			0b00000001
#define TIMER1_PRESCALER_8_msk			0b00000010
#define TIMER1_PRESCALER_64_msk			0b00000011
#define TIMER1_PRESCALER_256_msk		0b00000100
#define TIMER1_PRESCALER_1024_msk		0b00000101

#define TIMER1_MODE_clr_msk				0b11100111
#define TIMER1_MODE_NORMAL_msk  		0b00000000
#define TIMER1_MODE_CTC_TOP_OCR1A_msk 	0b00001000
#define TIMER1_MODE_CTC_TOP_ICR1_msk  	0b00011000

#define TIMER1_ICU_EDGE_clr_msk			0b10111111
#define TIMER1_ICU_EDGE_RISING_msk		0b01000000
#define TIMER1_ICU_EDGE_FALLING_msk		0b00000000

/*
 * INCLUDES
 * */
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../utils/Interrupts.h"
#include "../../config/TIMER1_cfg.h"
#include "../../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "TIMER1_hw.h"
#include "TIMER1_types.h"
#include "TIMER1.h"

static uint16 t0_steps,ton_steps,toff_steps,SingleStep_time_us;
static uint32 TIMER1_Freq_Hz;
static uint8 TIMER1_DutyCycle_per;


void TIMER1_init(void)
{


	/*set mode - nonPWM */
	TCCR1B &= TIMER1_MODE_clr_msk;
	TCCR1B |= TIMER1_MODE_SELECTOR;

	/*set edge mode for ICU */
	TCCR1B &= TIMER1_ICU_EDGE_clr_msk;
	TCCR1B |= TIMER1_ICU_EDGE_SELECTOR;

	/*set steps*/
	OCR1A = TIMER1_COMPARE_STEP_A;
	OCR1B = TIMER1_COMPARE_STEP_B;

	/*set prescaler */
	TCCR1B &= TIMER1_PRESCALER_clr_msk;
	TCCR1B |= TIMER1_PRESCALER_SELECTOR;

}
void TIMER1_enInterrupt(TIMER1_IntType Int)
{
	switch(Int)
	{
	case TIMER1_INT_ICR:
		SET_BIT(TIMSK,5);
		break;
	case TIMER1_INT_OCRA:
		SET_BIT(TIMSK,4);
		break;
	case TIMER1_INT_OCRB:
		SET_BIT(TIMSK,3);
		break;
	case TIMER1_INT_OVF:
		SET_BIT(TIMSK,2);
		break;
	default:

		break;
	}

}
void TIMER1_diInterrupt(TIMER1_IntType Int)
{
	switch(Int)
	{
	case TIMER1_INT_ICR:
		CLR_BIT(TIMSK,5);
		break;
	case TIMER1_INT_OCRA:
		CLR_BIT(TIMSK,4);
		break;
	case TIMER1_INT_OCRB:
		CLR_BIT(TIMSK,3);
		break;
	case TIMER1_INT_OVF:
		CLR_BIT(TIMSK,2);
		break;
	default:

		break;
	}
}
void TIMER1_readPwm(uint32* FreqPtr_Hz,uint8* DutyCyclePtr)
{

	*FreqPtr_Hz = TIMER1_Freq_Hz;
	*DutyCyclePtr =  TIMER1_DutyCycle_per;
}
uint32 TIMER1_getHiLevelTime(void)
{
	return (ton_steps*TIMER1_SINGLE_STEP_TIME_us);

}
void ISR(TIMER1_CAPT)
{
	static uint8 flag = 0;
	if(flag == 0)
	{
		/*set edge to falling */
		CLR_BIT(TCCR1B,6);
		/* copy ICR in t0 */
		TCNT1 = 0;
		t0_steps = 0;
		flag =1;
	}
	else if (flag == 1)
	{
		/* set edge rising */
		SET_BIT(TCCR1B,6);
		/*copy ICR in t1*/
		ton_steps = ICR;
		flag = 2;
	}
	else
	{
		/* set edge to rising ( already set ) */

		/* copy ICR in t2 */
		toff_steps = ICR;
		flag =0;

		/* calculate freq and duty cycle */
		TIMER1_Freq_Hz = 1000000 / ( TIMER1_SINGLE_STEP_TIME_us * (toff_steps - t0_steps) );
		TIMER1_DutyCycle_per = 100 * (ton_steps - t0_steps) / (toff_steps - t0_steps) ;
	}
}
void ISR(TIMER1_COMPA)
{

}
void ISR(TIMER1_COMPB)
{

}
void ISR(TIMER1_OVF)
{

}














