/*
 * lab_04_lcd.c
 *
 *  Created on: Jun 28, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../MCAL/PORT_DRIVER/PORT.h"
#include "../EHAL/LCD/LCD.h"
void lab_04_lcd(void)
{
	PORT_init();
	LCD_init();
	LCD_writeCharData('a');
	while(1)
	{
		;
	}
}
