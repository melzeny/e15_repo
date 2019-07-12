/*
 * lab_05_Exti.c
 *
 *  Created on: Jun 29, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/EXTI/EXTI.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../utils/Interrupts.h"

void lab_05_Exti(void)
{

	PORT_init();
	EXTI_init();
	GI_EN();
	while(1)
	{
		;
	}

}

void ISR(EXTI_INT0)
{
	Dio_FlipChannel(Dio_Channel_D6);
}
