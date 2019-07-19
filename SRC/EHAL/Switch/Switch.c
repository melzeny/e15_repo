/*
 * SWITCH.c
 *
 *  Created on: Jul 6, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "Switch.h"
#include "../../Scheduler/Scheduler.h"
#include "../../config/Switch_cfg.h"
#include "../../utils/Std_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "Switch_types.h"

extern SW_SwitchType SW_CfgArr[SW_MaxNumOfSwitches];
static void SW_setSwitchStatus_Task(void);


void SW_init(void)
{
	Scheduler_createTask(0, SW_setSwitchStatus_Task,1,STD_Active);
	Scheduler_init();

}

SW_StatusType SW_getSwitchStatus(SW_NameType SwName)
{
	return SW_CfgArr[SwName].FinalStatus;
}

static void SW_setSwitchStatus_Task(void)
{
	uint8 i;
	for (i = 0; i < SW_MaxNumOfSwitches; i++)
	{

		if(SW_CfgArr[i].ModeType == Active_high)
		{
			SW_CfgArr[i].CurrStatus = Dio_ReadChannel( SW_CfgArr[i].Channel);
		}
		else
		{
			SW_CfgArr[i].CurrStatus = !Dio_ReadChannel( SW_CfgArr[i].Channel);
		}


		if(SW_CfgArr[i].CurrStatus == SW_CfgArr[i].PrevStatus)
		{
			SW_CfgArr[i].SW_DebounceCounter++;
		}
		else
		{
			SW_CfgArr[i].SW_DebounceCounter = 0;
		}


		if(SW_CfgArr[i].SW_DebounceCounter == SWITCH_DEBOUNCE_COUNTER)
		{
			SW_CfgArr[i].FinalStatus = SW_CfgArr[i].CurrStatus;
			SW_CfgArr[i].SW_DebounceCounter = 0;
		}

		SW_CfgArr[i].PrevStatus = SW_CfgArr[i].CurrStatus;
	}
}
