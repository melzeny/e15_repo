/*
 * BcdSevSegments.c
 *
 *  Created on: Jun 21, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../MCAL/PORT_DRIVER/PORT.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../config/BcdSevSegments_cfg.h"
void BcdSevSeg_Init(void)
{
	PORT_init();

}
void BcdSevSeg_DisplayNum(uint8 num)
{
	if(num <= 0x0F)
	{
		Dio_WriteChannel(BcdSevSeg_PIN_A, GET_BIT(num,0));
		Dio_WriteChannel(BcdSevSeg_PIN_B, GET_BIT(num,1));
		Dio_WriteChannel(BcdSevSeg_PIN_C, GET_BIT(num,2));
		Dio_WriteChannel(BcdSevSeg_PIN_D, GET_BIT(num,3));
	}
	else
	{

	}
}

void BcdSevSeg_1_en(void)
{
	Dio_WriteChannel(BcdSevSeg_PIN_EN1,STD_high);
}
void BcdSevSeg_1_di(void)
{

	Dio_WriteChannel(BcdSevSeg_PIN_EN1,STD_low);
}
void BcdSevSeg_2_en(void)
{
	Dio_WriteChannel(BcdSevSeg_PIN_EN2,STD_high);
}
void BcdSevSeg_2_di(void)
{

	Dio_WriteChannel(BcdSevSeg_PIN_EN2,STD_low);
}
