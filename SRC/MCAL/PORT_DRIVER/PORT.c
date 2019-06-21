/*
 * PORT.c
 *
 *  Created on: Jun 15, 2019
 *      Author: Muhammad.Elzeiny
 */

/*********************************************************************
 * 			INCLUDES
 *
 * *******************************************************************/
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/PORT_cfg.h"
#include "PORT_types.h"
#include "PORT_hw.h"
#include "PORT.h"

/*********************************************************************
 * 			EXTERNS
 *
 * *******************************************************************/
extern const PORT_PinType PORT_PinGroup[PORT_ACTIVATED_PINS_NUMBER];


/*********************************************************************
 * 			FUNCTIONS DEFINTIONS
 *
 * *******************************************************************/
void PORT_init(void)
{
	uint8 i;
	PORT_PortType PortId;
	Port_ChannelType ChannelPos;
	PORT_PinDirType PinDir;
	PORT_PinModeType PinMode;
	/****************** INIT DIRECTION ***********************/
	for(i=0;i<PORT_ACTIVATED_PINS_NUMBER;i++)
	{
		PortId = (PORT_PinGroup[i].id) / 8;
		ChannelPos = (PORT_PinGroup[i].id) % 8;
		PinDir = PORT_PinGroup[i].PinDir;
		PinMode = PORT_PinGroup[i].PinMode;

		switch(PortId)
		{
		case PORT_Port_A:
			if(PinDir == Dir_Output)
			{
				SET_BIT(DDRA_REG,ChannelPos);
			}
			else
			{
				CLR_BIT(DDRA_REG,ChannelPos);
				/* Activate Pull up resistor*/
				if(PinMode == Mode_Dio_With_Pullup_Res)
				{
					SET_BIT(PORTA_REG,ChannelPos);
				}
			}
			break;
		case PORT_Port_B:
			if(PinDir == Dir_Output)
			{
				SET_BIT(DDRB_REG,ChannelPos);
			}
			else
			{
				CLR_BIT(DDRB_REG,ChannelPos);
				if(PinMode == Mode_Dio_With_Pullup_Res)
				{
					SET_BIT(PORTB_REG,ChannelPos);
				}
			}
			break;
		case PORT_Port_C:
			if(PinDir == Dir_Output)
			{
				SET_BIT(DDRC_REG,ChannelPos);
			}
			else
			{
				CLR_BIT(DDRC_REG,ChannelPos);
				if(PinMode == Mode_Dio_With_Pullup_Res)
				{
					SET_BIT(PORTC_REG,ChannelPos);
				}
			}
			break;
		case PORT_Port_D:
			if(PinDir == Dir_Output)
			{
				SET_BIT(DDRD_REG,ChannelPos);
			}
			else
			{
				CLR_BIT(DDRD_REG,ChannelPos);
				if(PinMode == Mode_Dio_With_Pullup_Res)
				{
					SET_BIT(PORTD_REG,ChannelPos);
				}
			}
			break;
		default:
			/*error*/
			break;
		}
	}
}
