#include "../../utils/Bit_Math.h"
#include "../../utils/STD_Types.h"
#include "DIO_hw.h"
#include "DIO.h"

STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{


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

		break;

	case Dio_Port_C:

		break;
	case Dio_Port_D:

		break;
	default:
		/*error*/
		break;
	}
}
uint8 Dio_ReadPort(Dio_PortType PortId )
{

}
void Dio_WritePort( Dio_PortType PortId, uint8 Level)
{


}
void Dio_FlipChannel( Dio_ChannelType ChannelId)
{

}
void Dio_FlipPort(Dio_PortType PortId)
{

}
