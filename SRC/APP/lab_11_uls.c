/*
 * lab_11_icu.c
 *
 *  Created on: Jul 27, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../utils/Std_Types.h"
#include "../utils/Bit_Math.h"

#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/TIMER1/TIMER1.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"

#include "../EHAL/LCD/LCD.h"
#include "../EHAL/ULS/ULS.h"
#include "../Scheduler/Scheduler.h"
#include <stdlib.h>
#include <util/delay.h>
void lab_11_uls(void)
{
	uint8 buff[8];
	PORT_init();
	ULS_init();
	while(1)
	{
		itoa(ULS_getDistance(), buff , 10);
		LCD_writeCmd(0x01);
		LCD_writeString("Distance in cm",1,0);
		LCD_writeString(buff,0,0);
		_delay_ms(500);

	}


}
