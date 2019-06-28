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
	uint8 mArr[8]={0, 0, 31, 5, 7, 0, 0, 0};
	PORT_init();
	LCD_init();
	LCD_storeCustomChr(mArr,0);
	LCD_DisplayCustomChr(0,0,0);
	while(1)
	{
		;
	}
}
