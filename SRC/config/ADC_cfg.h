/*
 * ADC_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Moustafa
 */

#ifndef E15_MS_PROJECT_E15_REPO_SRC_CONFIG_ADC_CFG_H_
#define E15_MS_PROJECT_E15_REPO_SRC_CONFIG_ADC_CFG_H_

#include "../utils/STD_Types.h"

/*=========================================================
 * Reference Selection Bits
 * ========================================================
* ADC_VoltageReference_clr_msk			0b00111111
* ADC_VoltageReference_AREF_msk			0b00000000
* ADC_VoltageReference_AVCC_msk			0b01000000
* ADC_VoltageReference_2_56V_msk		0b11000000
* */
#define ADC_VoltageReference_Selector		ADC_VoltageReference_AVCC_msk

/*=========================================================
* ADC Left Adjust Result
 * ========================================================
* ADC_Adjust_clr_msk					0b11011111
* ADC_Adjust_RightAdjust_msk			0b00000000
* ADC_Adjust_LeftAdjust_msk			    0b00100000
*/
#define ADC_Adjust_Selector				ADC_Adjust_RightAdjust_msk


/*=========================================================
* ADC Prescaler Select Bits
 * ========================================================
#define ADC_Prescaler_clr_msk				0b11111000
#define ADC_Prescaler_2_msk					0b00000000
#define ADC_Prescaler_2_msk					0b00000001
#define ADC_Prescaler_4_msk					0b00000010
#define ADC_Prescaler_8_msk					0b00000011
#define ADC_Prescaler_16_msk				0b00000100
#define ADC_Prescaler_32_msk				0b00000101
#define ADC_Prescaler_64_msk				0b00000110
#define ADC_Prescaler_128_msk				0b00000111
*/
#define ADC_Prescaler_Selector				ADC_Prescaler_64_msk
#define ADC_Prescaler_Value					64

/*=========================================================
* ADC Auto Trigger Enable
 * ========================================================
#define ADC_Mode_clr_msk					0b11011111
#define ADC_SingleConversion_msk			0b00000000
#define ADC_AutoTrigging_msk				0b00100000
*/
#define ADC_Mode_Selector					ADC_SingleConversion_msk

/*=========================================================
* ADC Auto Trigger Source
 * ========================================================
#define ADC_Trigger_clr_msk							0b00011111
#define ADC_Trigger_Free_Running_mode_msk			0b00000000
#define ADC_Trigger_Analog_Comparator_msk			0b00100000
#define ADC_Trigger_Exti0_msk						0b01000000
#define ADC_Trigger_Timer0Comp_msk					0b01100000
#define ADC_Trigger_Timer0_OVF_msk					0b10000000
#define ADC_Trigger_Timer1CompB_msk					0b10100000
#define ADC_Trigger_Timer1_OVF_msk					0b11000000
#define ADC_Trigger_Timer1_CAPT_msk					0b11100000
*/
#define ADC_Trigger_Selector						ADC_Trigger_Free_Running_mode_msk

#define ADC_VOLTAGE_REF_mv 							5000
/*
 * choose between 255, 1023
 * */
#define ADC_TOTAL_STEPS								1023

#endif /* E15_MS_PROJECT_E15_REPO_SRC_CONFIG_ADC_CFG_H_ */
