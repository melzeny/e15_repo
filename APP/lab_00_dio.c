#include "../MCAL/DIO/DIO.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
void lab_00_dio(void)
{
	PORT_init();
	Dio_WriteChannel(Dio_Channel_D5,STD_high);
	Dio_WriteChannel(Dio_Channel_D6,STD_high);
	Dio_WriteChannel(Dio_Channel_D7,STD_high);

	while(1)
	{
		;
	}
}
