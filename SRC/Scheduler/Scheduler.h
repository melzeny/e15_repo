/*
 * Scheduler.h
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_SCHEDULER_SCHEDULER_H_
#define E15_REPO_SRC_SCHEDULER_SCHEDULER_H_

/*========================================
 * FUNCTIONS PROTOTYPES
 * ======================================*/
#include "../utils/STD_Types.h"

void Scheduler_init(void);

void Scheduler_createTask(uint8 TaskId,Ptr2FuncType TaskPtr,
		uint32 TaskPeriodicity,STD_StatusType TaskStatus);

void Scheduler_setTaskStatus(uint8 Id,STD_StatusType Status);
void Scheduler_setTaskPeriodicity(uint8 Id,uint32 Periodicity);


#endif /* E15_REPO_SRC_SCHEDULER_SCHEDULER_H_ */
