/*
 * lab_07_Scheduler.c
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../MCAL/DIO/DIO.h"
#include "../Scheduler/Scheduler.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
void Task_1(void)
{
	static uint8  counter = 0;
	counter ++;
	if(counter == 1)
	{
		Dio_WriteChannel(Dio_Channel_D7,STD_high);
	}
	else if(counter ==4)
	{
		Dio_WriteChannel(Dio_Channel_D7,STD_low);
		counter =0;
	}

}
void lab_07_Scheduler(void)
{
	PORT_init();
	Scheduler_createTask(0,Task_1,1,STD_Active);
	Scheduler_init();
	while(1)
	{
		;
	}

}

