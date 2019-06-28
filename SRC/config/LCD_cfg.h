/*
 * LCD_cfg.h
 *
 *  Created on: Jun 28, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_CONFIG_LCD_CFG_H_
#define E15_REPO_SRC_CONFIG_LCD_CFG_H_


/*
 * define LCD_ mode with the following options
 * LCD_MODE_4_PIN
 * LCD_MODE_8_PIN
 * */

#define LCD_MAX_NUMBER_OF_CHR	16

#define LCD_MODE_SELECTOR		LCD_MODE_4_PIN

#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN
#define LCD_PIN_D0				Dio_Channel_C0
#define LCD_PIN_D1				Dio_Channel_C1
#define LCD_PIN_D2				Dio_Channel_C2
#define LCD_PIN_D3				Dio_Channel_C3
#endif

#define LCD_PIN_D4				Dio_Channel_A4
#define LCD_PIN_D5				Dio_Channel_A5
#define LCD_PIN_D6				Dio_Channel_A6
#define LCD_PIN_D7				Dio_Channel_A7

#define LCD_PIN_RS				Dio_Channel_B1
#define LCD_PIN_RW				Dio_Channel_B2
#define LCD_PIN_E				Dio_Channel_B3


#endif /* E15_REPO_SRC_CONFIG_LCD_CFG_H_ */
