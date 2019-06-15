/*
 * PORT_lcfg.c
 *
 *  Created on: Jun 15, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "PORT_lcfg.h"
typedef enum
{
	Port_Channel_A0,
	Port_Channel_A1,
	Port_Channel_A2,
	Port_Channel_A3,
	Port_Channel_A4,
	Port_Channel_A5,
	Port_Channel_A6,
	Port_Channel_A7,

	Port_Channel_B0,
	Port_Channel_B1,
	Port_Channel_B2,
	Port_Channel_B3,
	Port_Channel_B4,
	Port_Channel_B5,
	Port_Channel_B6,
	Port_Channel_B7,

	Port_Channel_C0,
	Port_Channel_C1,
	Port_Channel_C2,
	Port_Channel_C3,
	Port_Channel_C4,
	Port_Channel_C5,
	Port_Channel_C6,
	Port_Channel_C7,

	Port_Channel_D0,
	Port_Channel_D1,
	Port_Channel_D2,
	Port_Channel_D3,
	Port_Channel_D4,
	Port_Channel_D5,
	Port_Channel_D6,
	Port_Channel_D7

}Port_ChannelType;
typedef enum
{
	Dir_Input,
	Dir_Output
}PORT_PinDirType;

typedef enum
{
	Mode_Dio,
	Mode_Adc
}PORT_PinModeType;

typedef struct
{
	Port_ChannelType id;
	PORT_PinDirType PinDir;
	PORT_PinModeType PinMode;
}PORT_PinType;

const PORT_PinType PORT_PinGroup[PORT_ACTIVATED_PINS_NUMBER] =
{
		/*             Group A                        */
		/*  {Port_Channel_A0, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_A1, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_A2, Dir_Input, Mode_Dio },  */
		  	{Port_Channel_A3, Dir_Input, Mode_Dio },
		/*  {Port_Channel_A4, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_A5, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_A6, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_A7, Dir_Input, Mode_Dio },  */
        /*             Group B                        */
		/*  {Port_Channel_B0, Dir_Input, Mode_Dio },  */
		    {Port_Channel_B1, Dir_Input, Mode_Dio },
		    {Port_Channel_B2, Dir_Input, Mode_Dio }
		/*  {Port_Channel_B3, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_B4, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_B5, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_B6, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_B7, Dir_Input, Mode_Dio },  */
        /*            Group C                         */
		/*  {Port_Channel_C0, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_C1, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_C2, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_C3, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_C4, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_C5, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_C6, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_C7, Dir_Input, Mode_Dio },  */
        /*            Group D                         */
		/*  {Port_Channel_D0, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_D1, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_D2, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_D3, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_D4, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_D5, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_D6, Dir_Input, Mode_Dio },  */
		/*  {Port_Channel_D7, Dir_Input, Mode_Dio }   */

};
