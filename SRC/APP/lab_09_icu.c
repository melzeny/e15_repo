/*
 * lab_09_icu.c
 *
 *  Created on: Jul 20, 2019
 *      Author: Muhammad.Elzeiny
 */
#include <util/delay.h>

#include "../utils/Interrupts.h"
#include "../utils/STD_Types.h"

#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/TIMER1/TIMER1.h"
#include "../MCAL/TIMER2/TIMER2.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"

#include "../EHAL/LCD/LCD.h"
#include <stdlib.h>

void lab_09_icu(void)
{
	uint32 Freq=0;
	uint8 DutyCycle=0;
	uint8 Buffer[16];
	PORT_init();
	LCD_init();
	TIMER1_init();
	TIMER2_init();
	TIMER1_enInterrupt(TIMER1_INT_ICR);
	GI_EN();


	while(1)
	{
		LCD_writeCmd(0x01);
		LCD_writeString("Freq=         Hz",0,0);
		LCD_writeString("DutyCycle=    %",1,0);

		TIMER1_readPwm(&Freq,&DutyCycle);

		ltoa(Freq,Buffer,10);
		LCD_writeString(Buffer,0,6);

		itoa(DutyCycle,Buffer,10);
		LCD_writeString(Buffer,1,11);

		_delay_ms(500);

	}


}
