/*
 * PORT_types.h
 *
 *  Created on: Jun 17, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_LAB_SRC_MCAL_PORT_DRIVER_PORT_TYPES_H_
#define E15_LAB_SRC_MCAL_PORT_DRIVER_PORT_TYPES_H_

/*TYPES*/
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

typedef enum
{
	PORT_Port_A,
	PORT_Port_B,
	PORT_Port_C,
	PORT_Port_D
}PORT_PortType;

typedef struct
{
	Port_ChannelType id;
	PORT_PinDirType PinDir;
	PORT_PinModeType PinMode;
}PORT_PinType;


#endif /* E15_LAB_SRC_MCAL_PORT_DRIVER_PORT_TYPES_H_ */
