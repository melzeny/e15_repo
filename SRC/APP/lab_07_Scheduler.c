/*
 * lab_07_Scheduler.c
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../Scheduler/Scheduler.h"

void Task_1(void)
{


}
void Task_2(void)
{


}
void lab_07_Scheduler(void)
{

	Scheduler_createTask(Task_1,1);
	Scheduler_createTask(Task_2,4);
	Scheduler_init();
	while(1)
	{
		;
	}

}

