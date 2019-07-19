/*
 * KP_cfg.h
 *
 *  Created on: Jun 22, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_CONFIG_KP_CFG_H_
#define E15_REPO_SRC_CONFIG_KP_CFG_H_

/*================================================================================
 * Keypad Dependencies
 * DIO Driver
 * PORT Driver 	: 1- Row pins shall be configured as INPUT
 * 				: 2- Columns pins shall be configured as OUTPUT
 * 				: 3- PORT Driver shall be initialized before using this module
 ================================================================================*/

#define KP_PIN_R0			Dio_Channel_A0
#define KP_PIN_R1			Dio_Channel_A1
#define KP_PIN_R2			Dio_Channel_A2
#define KP_PIN_R3			Dio_Channel_A3
#define KP_PIN_C0			Dio_Channel_A4
#define KP_PIN_C1			Dio_Channel_A5
#define KP_PIN_C2			Dio_Channel_A6
#define KP_PIN_C3			Dio_Channel_A7

#define KP_ACTIVATE_TYPE	STD_low

/*
 * Please Configure values for the following layout
 * 		___________________________________________________________
 *		|KP_BUTON_0	 |	KP_BUTON_1	|	KP_BUTON_2	|	KP_BUTON_3 |
 *      |____________|______________|_______________|______________|
 * 		|KP_BUTON_4	 |	KP_BUTON_5	|	KP_BUTON_6	|	KP_BUTON_7 |
 *      |____________|______________|_______________|______________|
 * 		|KP_BUTON_8	 |	KP_BUTON_9	|	KP_BUTON_10	|	KP_BUTON_11|
 *      |____________|______________|_______________|______________|
 * 		|KP_BUTON_12 |	KP_BUTON_13	|	KP_BUTON_14	|	KP_BUTON_15|
 * 		|____________|______________|_______________|______________|
 */
#define KP_BUTON_0								'1'
#define KP_BUTON_1								'2'
#define KP_BUTON_2								'3'
#define KP_BUTON_3								'+'

#define KP_BUTON_4								'4'
#define KP_BUTON_5								'5'
#define KP_BUTON_6								'6'
#define KP_BUTON_7								'-'

#define KP_BUTON_8								'7'
#define KP_BUTON_9								'8'
#define KP_BUTON_10								'9'
#define KP_BUTON_11								'*'

#define KP_BUTON_12								'='
#define KP_BUTON_13								'0'
#define KP_BUTON_14								'^'
#define KP_BUTON_15								'/'

#define KP_RELEASED								255

#define KP_INTERNAL_PULL_UP_RESISTOR_EN			ENABLE


#endif /* E15_REPO_SRC_CONFIG_KP_CFG_H_ */
