/*
 * lab_03_KP.c
 *
 *  Created on: Jun 22, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <avr/delay.h>
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../EHAL/SevSeg/SevSegments.h"
#include "../EHAL/KP/KP.h"
void lab_03_KP(void)
{
	uint8 PressedButton,DisNum = 88;
	PORT_init();
	while(1)
	{
		PressedButton = KP_getPressedButton();
		if(PressedButton != 255)
		{
			DisNum = PressedButton;
		}
		SevSeg_2_di();
		SevSeg_DisplayNum(DisNum % 10 );
		SevSeg_1_en();
		_delay_ms(5);

		SevSeg_1_di();
		SevSeg_DisplayNum(DisNum / 10 );
		SevSeg_2_en();
		_delay_ms(5);

	}

}
