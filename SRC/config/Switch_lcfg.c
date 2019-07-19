/*
 * SWITCH_lcfg.c
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../EHAL/Switch/Switch_types.h"
#include "../utils/Std_Types.h"
#include "../MCAL/DIO/DIO_types.h"

/*==================================================================================================
 * Switch Dependencies
 * DIO Driver
 * PORT Driver 	: 1- all used pins shall be configured as INPUT
 * 				: 2- PORT Driver shall be initialized before using this module
 * 				: 3- Attached Pin shall be connected to PULL-UP Resistor if Switch is Active LOW
 * 				: 4- Attached Pin shall be connected to PULL-DOWN Resistor if Switch is Active HIGH
 *
 * 	NOTE: (For AVR)
 * 	Internal Pull up resistor could be connected
 * 	by setting direction as input Then writing high to attached channel.
 ==================================================================================================*/


const SW_SwitchType SW_CfgArr[SW_MaxNumOfSwitches] =
{
		{SW_Name_0, Dio_Channel_C0, Active_low},
		{SW_Name_1, Dio_Channel_C1, Active_low},
		{SW_Name_2, Dio_Channel_C2, Active_low},
		{SW_Name_3, Dio_Channel_C3, Active_high},
		{SW_Name_4, Dio_Channel_C4, Active_low},
		{SW_Name_5, Dio_Channel_C5, Active_low},
		{SW_Name_6, Dio_Channel_C6, Active_high},
		{SW_Name_7, Dio_Channel_C7, Active_low},

};
