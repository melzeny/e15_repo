/*
 * EXTI.c
 *
 *  Created on: Jun 29, 2019
 *      Au
 *      thor: Muhammad.Elzeiny
 */
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "EXTI_Types.h"
#include "../../config/EXTI_cfg.h"
#include "EXTI_hw.h"
#include "EXTI.h"

void EXTI_init(void)
{
#if (EXTI_INT0_EN == ENABLE)
	EXTI_setEdge(EXTI_INT0,EXTI_INT0_EDGE);
	EXTI_enInterrupt(EXTI_INT0);
#endif
#if (EXTI_INT1_EN == ENABLE)
	EXTI_setEdge(EXTI_INT1,EXTI_INT1_EDGE);
	EXTI_enInterrupt(EXTI_INT1);
#endif
#if (EXTI_INT2_EN == ENABLE)
	EXTI_setEdge(EXTI_INT2,EXTI_INT2_EDGE);
	EXTI_enInterrupt(EXTI_INT2);
#endif

}
void EXTI_setEdge(EXTI_IntType IntNum,EXTI_EdgeType Edge)
{
	switch(IntNum)
	{
	case EXTI_INT0:
		if(Edge == EXTI_Edge_Rising)
		{
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if(Edge == EXTI_Edge_Falling)
		{
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if(Edge == EXTI_Edge_OnChange)
		{
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		break;
	case EXTI_INT1:
		if(Edge == EXTI_Edge_Rising)
		{
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if(Edge == EXTI_Edge_Falling)
		{
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if(Edge == EXTI_Edge_OnChange)
		{
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		break;
	case EXTI_INT2:
		if(Edge == EXTI_Edge_Rising)
		{
			SET_BIT(MCUCSR,6);
		}
		else if(Edge == EXTI_Edge_Falling)
		{
			CLR_BIT(MCUCSR,6);
		}
		break;
	}

}
void EXTI_enInterrupt(EXTI_IntType IntNum)
{
	switch(IntNum)
	{
	case EXTI_INT0:
		SET_BIT(GICR,6);
		break;
	case EXTI_INT1:
		SET_BIT(GICR,7);
		break;
	case EXTI_INT2:
		SET_BIT(GICR,5);
		break;
	}
}
void EXTI_diInterrupt(EXTI_IntType IntNum)
{
	switch(IntNum)
	{
	case EXTI_INT0:
		CLR_BIT(GICR,6);
		break;
	case EXTI_INT1:
		CLR_BIT(GICR,7);
		break;
	case EXTI_INT2:
		CLR_BIT(GICR,5);
		break;
	}


}


