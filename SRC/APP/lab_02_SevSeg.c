/*
 * lab_01_BcdSevSeg.c
 *
 *  Created on: Jun 21, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <avr/delay.h>
#include "../EHAL/SevSeg/SevSegments.h"
void lab_02_SevSeg(void)
{
	uint8 counter  =0,i;
	SevSeg_Init();
	while(1)
	{
		counter++;
		for(i=0;i<50;i++)
		{
			SevSeg_2_di();
			SevSeg_DisplayNum(counter % 10 );
			SevSeg_1_en();

			_delay_ms(10);

			SevSeg_1_di();
			SevSeg_DisplayNum(counter / 10 );
			SevSeg_2_en();

			_delay_ms(10);
		}

	}

}
