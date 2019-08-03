/*
 * ADC_hw.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Moustafa
 */

#ifndef E15_MS_PROJECT_E15_REPO_SRC_MCAL_ADC_ADC_HW_H_
#define E15_MS_PROJECT_E15_REPO_SRC_MCAL_ADC_ADC_HW_H_

#include "../../utils/STD_Types.h"

#define ADMUX 					*((volatile uint8*)0x27)
#define ADCSRA                  *((volatile uint8*)0x26)

#define ADC                     *((volatile uint16*)0x24)
#define ADCL                    *((volatile uint8*)0x24)
#define ADCH                    *((volatile uint8*)0x25)

#define SFIOR                   *((volatile uint8*)0x50)

#endif /* E15_MS_PROJECT_E15_REPO_SRC_MCAL_ADC_ADC_HW_H_ */
