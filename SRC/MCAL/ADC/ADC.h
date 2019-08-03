/*
 * ADC.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Moustafa
 */

#ifndef E15_MS_PROJECT_E15_REPO_SRC_MCAL_ADC_ADC_H_
#define E15_MS_PROJECT_E15_REPO_SRC_MCAL_ADC_ADC_H_

#include "../../utils/STD_Types.h"
#include "ADC_types.h"

void ADC_init(void);
void ADC_StartCon(DCS_Ch_type Channel);
uint16 ADC_ReadChannel(DCS_Ch_type Channel);
void ADC_enInterrupt(void);
void ADC_diInterrupt(void);
uint32 ADC_getVoltage_m(DCS_Ch_type Channel);

#endif /* E15_MS_PROJECT_E15_REPO_SRC_MCAL_ADC_ADC_H_ */
