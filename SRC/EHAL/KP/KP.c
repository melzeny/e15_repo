/*
 * KP.c
 *
 *  Created on: Jun 22, 2019
 *      Author: OMAR.Zayed_ Isaac.Ibrahim
 */
#include "../../MCAL/DIO/DIO.h"
#include "../../config/KP_cfg.h"
#include "KP.h"

static uint8 PressedButton=KP_RELEASED;
static const uint8 KP_MapArr[16] = {
		KP_BUTON_0,KP_BUTON_1,KP_BUTON_2,KP_BUTON_3,
		KP_BUTON_4,KP_BUTON_5,KP_BUTON_6,KP_BUTON_7,
		KP_BUTON_8,KP_BUTON_9,KP_BUTON_10,KP_BUTON_11,
		KP_BUTON_12,KP_BUTON_13,KP_BUTON_14,KP_BUTON_15};

static void CheckCol(uint8 ActivatedRow)
{
	if(Dio_ReadChannel(KP_PIN_C0) == KP_ACTIVATE_TYPE)
	{
		PressedButton = ActivatedRow * 4;
	}
	else if(Dio_ReadChannel(KP_PIN_C1) == KP_ACTIVATE_TYPE)
	{
		PressedButton = (ActivatedRow * 4) + 1;
	}
	else if(Dio_ReadChannel(KP_PIN_C2) == KP_ACTIVATE_TYPE)
	{
		PressedButton = (ActivatedRow * 4) + 2;
	}
	else if(Dio_ReadChannel(KP_PIN_C3) == KP_ACTIVATE_TYPE)
	{
		PressedButton = (ActivatedRow * 4) + 3;
	}
	else
	{

	}
}
uint8 KP_getPressedButton(void)
{
	PressedButton =KP_RELEASED;
	/*activate row 0*/
	Dio_WriteChannel(KP_PIN_R0,KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R1,!KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R2,!KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R3,!KP_ACTIVATE_TYPE);
	CheckCol(0);

	/*activate row 1*/
	Dio_WriteChannel(KP_PIN_R0,!KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R1,KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R2,!KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R3,!KP_ACTIVATE_TYPE);
	CheckCol(1);

	/*activate row 2*/
	Dio_WriteChannel(KP_PIN_R0,!KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R1,!KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R2,KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R3,!KP_ACTIVATE_TYPE);
	CheckCol(2);

	/*activate row 3*/
	Dio_WriteChannel(KP_PIN_R0,!KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R1,!KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R2,!KP_ACTIVATE_TYPE);
	Dio_WriteChannel(KP_PIN_R3,KP_ACTIVATE_TYPE);
	CheckCol(3);

	return ( ( PressedButton==KP_RELEASED ) ? KP_RELEASED : KP_MapArr[PressedButton] );

}
