/*
 * lab_01_BcdSevSeg.c
 *
 *  Created on: Jun 21, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <avr/delay.h>
#include "../EHAL/BcdSevSegments/BcdSevSegments.h"
void lab_01_BcdSevSeg(void)
{
	BcdSevSeg_Init();
	uint8 counter  =0,i;
	while(1)
	{
		counter++;
		for(i=0;i<50;i++)
		{
			BcdSevSeg_2_di();
			BcdSevSeg_DisplayNum(counter % 10 );
			BcdSevSeg_1_en();

			_delay_ms(10);

			BcdSevSeg_1_di();
			BcdSevSeg_DisplayNum(counter / 10 );
			BcdSevSeg_2_en();

			_delay_ms(10);
		}

	}

}
