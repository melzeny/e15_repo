/*
 * SevSeg.c
 *
 *  Created on: Jun 22, 2019
 *      Author: Nancy Sayed
 */

#define SevSeg_COMMMON_CATHOD		STD_low
#define SevSeg_COMMMON_ANOD			STD_high

#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"

#include "../../MCAL/PORT_DRIVER/PORT.h"
#include "../../MCAL/DIO/DIO.h"

#include "../../config/SevSegments_cfg.h"
#include "SevSegments.h"

const uint8 NumMap[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void SevSeg_Init(void)
{
	PORT_init();
}
void SevSeg_DisplayNum(uint8 num)
{
	Dio_WriteChannel(SevSeg_PIN_a, (SevSeg_COMMMON_TYPE ^ (GET_BIT(NumMap[num],0))) );
	Dio_WriteChannel(SevSeg_PIN_b, (SevSeg_COMMMON_TYPE ^ (GET_BIT(NumMap[num],1))) );
	Dio_WriteChannel(SevSeg_PIN_c, (SevSeg_COMMMON_TYPE ^ (GET_BIT(NumMap[num],2))) );
	Dio_WriteChannel(SevSeg_PIN_d, (SevSeg_COMMMON_TYPE ^ (GET_BIT(NumMap[num],3))) );
	Dio_WriteChannel(SevSeg_PIN_e, (SevSeg_COMMMON_TYPE ^ (GET_BIT(NumMap[num],4))) );
	Dio_WriteChannel(SevSeg_PIN_f, (SevSeg_COMMMON_TYPE ^ (GET_BIT(NumMap[num],5))) );
	Dio_WriteChannel(SevSeg_PIN_g, (SevSeg_COMMMON_TYPE ^ (GET_BIT(NumMap[num],6))) );
}
void SevSeg_1_en(void)
{
	Dio_WriteChannel(SevSeg_PIN_EN1,SevSeg_COMMMON_TYPE);
}
void SevSeg_1_di(void)
{
	Dio_WriteChannel(SevSeg_PIN_EN1,!SevSeg_COMMMON_TYPE);
}
void SevSeg_2_en(void)
{
	Dio_WriteChannel(SevSeg_PIN_EN2,SevSeg_COMMMON_TYPE);
}
void SevSeg_2_di(void)
{
	Dio_WriteChannel(SevSeg_PIN_EN2,!SevSeg_COMMMON_TYPE);
}
