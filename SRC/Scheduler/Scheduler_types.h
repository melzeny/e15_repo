/*
 * Scheduler_types.h
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_SCHEDULER_SCHEDULER_TYPES_H_
#define E15_REPO_SRC_SCHEDULER_SCHEDULER_TYPES_H_

/*========================================
 * TYPES
 * ======================================*/
typedef struct
{
	Ptr2FuncType Ptr2Task;
	uint32 Periodicity;
}Scheduler_TaskType;

#endif /* E15_REPO_SRC_SCHEDULER_SCHEDULER_TYPES_H_ */
