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
#include "../utils/Interrupts.h"

#include "../MCAL/TIMER0/TIMER0.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"

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

/*========================================
 * FUNCTIONS Definitions
 * ======================================*/
void Scheduler_init(void)
{
	GI_EN();
	TIMER0_init();

}
void Scheduler_createTask(
		uint8 TaskIdCpy,
		Ptr2FuncType TaskPtr,
		uint32 TaskPeriodicity,
		STD_StatusType TaskStatus)
{
	if(TaskIdCpy < SCHEDULER_MAX_NO_OF_TASKS)
	{
		TasksArr[TaskIdCpy].TaskId = TaskIdCpy;
		TasksArr[TaskIdCpy].Ptr2Task = TaskPtr;
		TasksArr[TaskIdCpy].Periodicity = TaskPeriodicity;
		TasksArr[TaskIdCpy].TaskStatus = TaskStatus;
	}
}
void Scheduler_setTaskStatus(uint8 Id,STD_StatusType Status)
{
	TasksArr[Id].TaskStatus = Status;
}
void Scheduler_setTaskPeriodicity(uint8 Id,uint32 Periodicity)
{
	TasksArr[Id].Periodicity = Periodicity;
}
inline static void Scheduler(void)
{
	uint8 i;
	static uint32 Scheduler_Counter = 0;

	for(i=0; i<SCHEDULER_MAX_NO_OF_TASKS; i++)
	{
		if(TasksArr[i].Ptr2Task != 0)
		{
			if((Scheduler_Counter% TasksArr[i].Periodicity) == 0)
			{
				if(TasksArr[i].TaskStatus == STD_Active)
				{
					TasksArr[i].Ptr2Task();
				}
			}
		}
	}
	Scheduler_Counter++;
}

void ISR(TIMER0_COMP)
{
	Scheduler();

}
