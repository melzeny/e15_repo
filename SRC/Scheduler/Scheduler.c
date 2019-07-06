/*
 * Scheduler.c
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */
/*========================================
 * INCLUDES
 * ======================================*/
#include "../utils/Bit_Math.h"
#include "../utils/STD_Types.h"
#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include "../utils/Compiler.h"

#include "../config/Scheduler_cfg.h"
#include "Scheduler_types.h"
#include "Scheduler.h"
/*========================================
 * LOCAL PROTOTYPES FUNCTIONS
 * ======================================*/
inline static void Scheduler(void);

/*========================================
 * STATIC VARIABLE
 * ======================================*/
static Scheduler_TaskType TasksArr[SCHEDULER_MAX_NO_OF_TASKS];
static uint8 CurrentNumOfTasks =0;
/*========================================
 * FUNCTIONS Definitions
 * ======================================*/
void Scheduler_init(void)
{
	GI_EN();
	TIMER0_init();

}
void Scheduler_createTask(Ptr2FuncType TaskPtr,uint32 TaskPeriodicity)
{
	if(CurrentNumOfTasks < SCHEDULER_MAX_NO_OF_TASKS)
	{
		TasksArr[CurrentNumOfTasks].Ptr2Task = TaskPtr;
		TasksArr[CurrentNumOfTasks].Periodicity = TaskPeriodicity;
		CurrentNumOfTasks++;
	}
}
inline static void Scheduler(void)
{
	uint8 i;
	static uint32 Scheduler_Counter = 0;

	for(i=0;i<CurrentNumOfTasks;i++)
	{
		if((Scheduler_Counter% TasksArr[i].Periodicity) == 0)
		{
			TasksArr[i].Ptr2Task();
		}
	}
	Scheduler_Counter++;
}

void ISR(TIMER0_COMP)
{
	Scheduler();

}

