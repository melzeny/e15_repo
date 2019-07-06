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

void Scheduler_createTask(Ptr2FuncType Task,uint32 TaskPeriodicity);
void Scheduler_init(void);

#endif /* E15_REPO_SRC_SCHEDULER_SCHEDULER_H_ */
