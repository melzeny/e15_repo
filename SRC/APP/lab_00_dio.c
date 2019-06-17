#include "../MCAL/DIO/DIO.h"
#include "../MCAL/PORT_DRIVER/PORT.h"



void lab_00_dio(void)
{
	STD_levelType CurrStatus = STD_low,
			PrevStatus= STD_low;
	PORT_init();

	while(1)
	{
		CurrStatus = Dio_ReadChannel(Dio_Channel_D0);

		if(CurrStatus == STD_high)
		{
			if(PrevStatus == STD_low)
			{
				Dio_FlipChannel(Dio_Channel_D5);
			}
		}
		else
		{

		}
		PrevStatus = CurrStatus;
	}
}
