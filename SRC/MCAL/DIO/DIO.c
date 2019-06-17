#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "DIO_hw.h"
#include "DIO.h"

STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	STD_levelType ret;
	Dio_PortType PortId = ChannelId / 8;
	Dio_ChannelType ChannelPos = ChannelId % 8;
	switch(PortId)
	{
	case Dio_Port_A:
		ret = GET_BIT(PINA_REG,ChannelPos);
		break;

	case Dio_Port_B:
		ret = GET_BIT(PINB_REG,ChannelPos);
		break;

	case Dio_Port_C:
		ret = GET_BIT(PINC_REG,ChannelPos);
		break;
	case Dio_Port_D:
		ret = GET_BIT(PIND_REG,ChannelPos);
		break;
	default:
		/*error*/
		ret = 2;
		break;
	}
	return ret;

}
void Dio_WriteChannel(Dio_ChannelType ChannelId, STD_levelType Level)
{
	Dio_PortType PortId = ChannelId / 8;
	Dio_ChannelType ChannelPos = ChannelId % 8;
	switch(PortId)
	{
	case Dio_Port_A:
		if(Level == STD_low)
		{
			CLR_BIT(PORTA_REG,ChannelPos);
		}
		else
		{
			SET_BIT(PORTA_REG,ChannelPos);
		}
		break;

	case Dio_Port_B:
		if(Level == STD_low)
		{
			CLR_BIT(PORTB_REG,ChannelPos);
		}
		else
		{
			SET_BIT(PORTB_REG,ChannelPos);
		}
		break;

	case Dio_Port_C:
		if(Level == STD_low)
		{
			CLR_BIT(PORTC_REG,ChannelPos);
		}
		else
		{
			SET_BIT(PORTC_REG,ChannelPos);
		}
		break;
	case Dio_Port_D:
		if(Level == STD_low)
		{
			CLR_BIT(PORTD_REG,ChannelPos);
		}
		else
		{
			SET_BIT(PORTD_REG,ChannelPos);
		}
		break;
	default:
		/*error*/
		break;
	}
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{
	uint8 ret;
	switch(PortId)
	{
	case Dio_Port_A:
		ret = PINA_REG;
		break;

	case Dio_Port_B:
		ret = PINB_REG;
		break;

	case Dio_Port_C:
		ret = PINC_REG;
		break;
	case Dio_Port_D:
		ret = PIND_REG;
		break;
	default:
		/*error*/
		break;
	}

	return ret;
}
void Dio_WritePort( Dio_PortType PortId, uint8 value)
{
	switch(PortId)
	{
	case Dio_Port_A:
		PORTA_REG = value;
		break;

	case Dio_Port_B:
		PORTB_REG = value;
		break;

	case Dio_Port_C:
		PORTC_REG = value;
		break;
	case Dio_Port_D:
		PORTD_REG = value;
		break;
	default:
		/*error*/
		break;
	}
}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{
	Dio_PortType PortId = ChannelId / 8;
	Dio_ChannelType ChannelPos = ChannelId % 8;
	switch(PortId)
	{
	case Dio_Port_A:
		TOGGLE_BIT(PORTA_REG,ChannelPos);
		break;

	case Dio_Port_B:
		TOGGLE_BIT(PORTB_REG,ChannelPos);
		break;

	case Dio_Port_C:
		TOGGLE_BIT(PORTC_REG,ChannelPos);
		break;
	case Dio_Port_D:
		TOGGLE_BIT(PORTD_REG,ChannelPos);
		break;
	default:
		/*error*/
		break;
	}

}
void Dio_FlipPort(Dio_PortType PortId)
{
	switch(PortId)
	{
	case Dio_Port_A:
		PORTA_REG = ~PORTA_REG;
		break;

	case Dio_Port_B:
		PORTB_REG = ~PORTB_REG;
		break;

	case Dio_Port_C:
		PORTC_REG = ~PORTC_REG;
		break;
	case Dio_Port_D:
		PORTD_REG = ~PORTD_REG;
		break;
	default:
		/*error*/
		break;
	}
}
