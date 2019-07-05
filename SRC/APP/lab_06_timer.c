/*
 * lab_06_timer.c
 *
 *  Created on: Jul 5, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../utils/Compiler.h"

void lab_06_timer(void)
{
	PORT_init();
	TIMER0_init();
	GI_EN();

	while(1)
	{

		;
	}

}
void ISR(TIMER0_COMP)
{
	Dio_FlipChannel(Dio_Channel_A4);

}
