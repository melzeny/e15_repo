/*
 * ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ENG: Moustafa Sayed _ Nancy Sayed
 */

#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "ADC_hw.h"
#include "ADC_types.h"
#include "ADC.h"
#include "../../config/ADC_cfg.h"
#include "../../MCAL/GLOBAL_INTERRUPT/GI.h"

/*=========================================================
 * Reference Selection Bits
 * ========================================================*/
#define ADC_VoltageReference_clr_msk	           	0b00111111
#define ADC_VoltageReference_AREF_msk	           	0b00000000
#define ADC_VoltageReference_AVCC_msk	           	0b01000000
#define ADC_VoltageReference_2_56V_msk	           	0b11000000

/*=========================================================
 * ADC Adjust Result
 * ========================================================*/
#define ADC_Adjust_clr_msk				          	0b11011111
#define ADC_Adjust_RightAdjust_msk		          	0b00000000
#define ADC_Adjust_LeftAdjust_msk		          	0b00100000

/*=========================================================
 * ADC Auto Trigger Enable
 * ========================================================*/
#define ADC_Mode_clr_msk			        		0b11011111
#define ADC_SingleConversion_msk	        		0b00000000
#define ADC_AutoTrigging_msk		        		0b00100000


/*=========================================================
 * ADC Prescaler Select Bits
 * ========================================================*/
#define ADC_Prescaler_clr_msk		         		0b11111000
#define ADC_Prescaler_2_msk			         		0b00000000
#define ADC_Prescaler_2_msk			         		0b00000001
#define ADC_Prescaler_4_msk			         		0b00000010
#define ADC_Prescaler_8_msk			         		0b00000011
#define ADC_Prescaler_16_msk		         		0b00000100
#define ADC_Prescaler_32_msk		         		0b00000101
#define ADC_Prescaler_64_msk		         		0b00000110
#define ADC_Prescaler_128_msk		         		0b00000111

/*=========================================================
 * ADC Auto Trigger Source
 * ========================================================*/
#define ADC_Trigger_clr_msk							0b00011111
#define ADC_Trigger_Free_Running_mode_msk			0b00000000
#define ADC_Trigger_Analog_Comparator_msk			0b00100000
#define ADC_Trigger_Exti0_msk						0b01000000
#define ADC_Trigger_Timer0Comp_msk					0b01100000
#define ADC_Trigger_Timer0_OVF_msk					0b10000000
#define ADC_Trigger_Timer1CompB_msk					0b10100000
#define ADC_Trigger_Timer1_OVF_msk					0b11000000
#define ADC_Trigger_Timer1_CAPT_msk					0b11100000

#define ADC_CHANNEL_clr_msk 						0b11100000
#define ADC_Enable_Pin								7
#define ADC_StartConversion							6
#define ADC_InterruptFlag							4
#define ADC_InterruptEnable_pin						3
#define F_CPU										16000000

void ADC_init(DCS_Ch_type Channel)
{
	/*Voltage Reference Selection Bits*/
	ADMUX &= ADC_VoltageReference_clr_msk;
	ADMUX |= ADC_VoltageReference_Selector;

	/* ADC Adjust Result */
	ADMUX &= ADC_Adjust_clr_msk;
	ADMUX |= ADC_Adjust_Selector;

	/* ADC Mode Selector */
	ADCSRA &= ADC_Mode_clr_msk;
	ADCSRA |= ADC_Mode_Selector;

	/* ADC AutoTrigger Source */
#if ADC_Mode_Selector==ADC_AutoTrigging_msk
	SFIOR &= ADC_Trigger_clr_msk;
	SFIOR |= ADC_Trigger_Selector;
#endif

	/* ADC Prescalar */
	ADCSRA &= ADC_Prescaler_clr_msk;
	ADCSRA |= ADC_Prescaler_Selector;

	/* ADC Enable */
	SET_BIT(ADCSRA,ADC_Enable_Pin);

	/*start conversion if adc mode is auto trigger*/
#if ADC_Mode_Selector == ADC_AutoTrigging_msk
	/* ADC Selection */
	ADMUX &= ADC_CHANNEL_clr_msk;
	ADMUX |= Channel;

	/* Start Conversion */
	SET_BIT(ADCSRA,ADC_StartConversion);
#endif
}

uint16 ADC_ReadChannel(DCS_Ch_type Channel)
{
	/*start conversion if adc mode is single conversion */
#if ADC_Mode_Selector == ADC_SingleConversion_msk

	/* ADC Selection */
	ADMUX &= 0b11100000;
	ADMUX |= Channel;

	/* Start Conversion */
	SET_BIT(ADCSRA,ADC_StartConversion);

#endif
	/*wait until conversion is done */
	while(GET_BIT(ADCSRA,4) == 0)
	{
		;
	}
	return ADC;
}

void ADC_enInterrupt(void)
{
	SET_BIT(ADCSRA,ADC_InterruptEnable_pin);
}

void ADC_diInterrupt(void)
{
	CLR_BIT(ADCSRA,ADC_InterruptEnable_pin);
}

uint32 ADC_getVoltage_m(DCS_Ch_type Channel)
{
	uint32 StepsNum,TotalSteps;
	StepsNum=ADC_ReadChannel(Channel);

	return StepsNum*(ADC_VOLTAGE_REF_mv/ADC_TOTAL_STEPS);

}
