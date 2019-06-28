/*
 * PORT_lcfg.c
 *
 *  Created on: Jun 15, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../MCAL/PORT_DRIVER/PORT_types.h"
#include "PORT_cfg.h"

/*********************************************************************
 * un-comment the activated pin
 * choose from the following to set Direction
 * 				Dir_Input
 * 				Dir-Output
 * choose from the following to set the Mode
 * 				Mode_Dio
 *
 * *******************************************************************/
const PORT_PinType PORT_PinGroup[PORT_ACTIVATED_PINS_NUMBER] =
{
		/*             Group A                        */
		 /* {Port_Channel_A0, Dir_Output, Mode_Dio },  */
		 /* {Port_Channel_A1, Dir_Output, Mode_Dio },  */
		 /* {Port_Channel_A2, Dir_Output, Mode_Dio },  */
		 /* {Port_Channel_A3, Dir_Output, Mode_Dio },  */
		 {Port_Channel_A4, Dir_Output, Mode_Dio},
		 {Port_Channel_A5, Dir_Output, Mode_Dio},
		 {Port_Channel_A6, Dir_Output, Mode_Dio},
		 {Port_Channel_A7, Dir_Output, Mode_Dio},
        /*             Group B                        */
		/*  {Port_Channel_B0, Dir_Input, Mode_Dio },  */
		 {Port_Channel_B1, Dir_Output, Mode_Dio },
		 {Port_Channel_B2, Dir_Output, Mode_Dio },
		 {Port_Channel_B3, Dir_Output, Mode_Dio }
		/*  {Port_Channel_B4, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_B5, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_B6, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_B7, Dir_Input, Mode_Dio },  */
        /*            Group C                         */
		/*  {Port_Channel_C0, Dir_Output, Mode_Dio },  */
		/*  {Port_Channel_C1, Dir_Output, Mode_Dio },  */
		/*  {Port_Channel_C2, Dir_Output, Mode_Dio },  */
		/*  {Port_Channel_C3, Dir_Output, Mode_Dio },  */
		/*  {Port_Channel_C4, Dir_Output, Mode_Dio },  */
		/*  {Port_Channel_C5, Dir_Output, Mode_Dio },  */
		/*  {Port_Channel_C6, Dir_Output, Mode_Dio },  */
		/*  {Port_Channel_C7, Dir_Output, Mode_Dio },*/
        /*            Group D                         */
		/*  {Port_Channel_D0, Dir_Output, Mode_Dio },  */
		/*  {Port_Channel_D1, Dir_Output, Mode_Dio },   */
		/*  {Port_Channel_D2, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_D3, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_D4, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_D5, Dir_Output, Mode_Dio }, */
		/*  {Port_Channel_D6, Dir_Output, Mode_Dio }, */
		/*  {Port_Channel_D7, Dir_Output, Mode_Dio }  */

};
