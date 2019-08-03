/*
 * lab_10_ADC.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Moustafa
 */

#include "../MCAL/ADC/ADC.h"
#include "../MCAL/ADC/ADC_hw.h"
#include "../MCAL/ADC/ADC_types.h"
#include "../EHAL/LCD/LCD.h"
#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../MCAL/GLOBAL_INTERRUPT/GI.h"
#include <avr/delay.h>


void lab_10_ADC(void)
{
	uint16 Value;
	uint8 counter=5;
	uint8 Str[counter];
	ADC_init(ADC_A1);
	PORT_init();
	LCD_init();
	Value=ADC_ReadChannel(ADC_A1);
	while(1)
	{
		LCD_writeCmd(0x01);
		Value=ADC_ReadChannel(ADC_A1);

		itoa(Value,Str,10);

		LCD_writeString(Str,0,0);
		Value=ADC_getVoltage_m(ADC_A1);

		itoa(Value,Str,10);

		LCD_writeString(Str,1,0);

		_delay_ms(500);
	}

}
