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


void TIMER1_init(void)
{
	/*set mode*/
	TCCR1B &= TIMER1_MODE_clr_msk;
	TCCR1B |= TIMER1_MODE_SELECTOR;

	/*set edge mode for ICU*/
	TCCR1B &= TIMER1_ICU_EDGE_clr_msk;
	TCCR1B |= TIMER1_ICU_EDGE_SELECTOR;

	/*enable Interrupt*/
	GI_EN();
#if TIMER1_INT_CAPT_EN
	TIMER1_enInterrupt(TIMER1_INT_ICR);
#endif
#if TIMER1_INT_COMPA_EN
	TIMER1_enInterrupt(TIMER1_INT_OCRA);
#endif
#if TIMER1_INT_COMPB_EN
	TIMER1_enInterrupt(TIMER1_INT_OCRB);
#endif
#if TIMER1_INT_OVF_EN
	TIMER1_enInterrupt(TIMER1_INT_OVF);
#endif
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
void TIMER1_readPwm(uint32* FreqPtr_Khz,uint8* DutyCyclePtr)
{

}
void ISR(TIMER1_CAPT)
{
	static uint8 flag = 0;
	if(flag == 0)
	{
		/*set edg to falling */

		/* copy ICR in t0 */

		flag =1;
	}
	else if (flag == 1)
	{
		/* set edge rising */

		/*copy ICR in t1*/

		flag = 2;
	}
	else
	{
		/* set edge to rising */

		/* copy ICR in t2 */

		flag =0;
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














