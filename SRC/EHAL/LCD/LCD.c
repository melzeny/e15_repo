/*
 * LCD.c
 *
 *  Created on: Jun 28, 2019
 *      Author: Muhammad.Elzeiny
 */

#define LCD_MODE_4_PIN		0
#define LCD_MODE_8_PIN		1

#include <util/delay.h>
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../config/LCD_cfg.h"

#include "../../MCAL/DIO/DIO.h"
#include "LCD_types.h"
#include "LCD.h"

void LCD_init(void)
{


}
void LCD_writeCharData(uint8 u8Data)
{
	/* write data to data register */
	Dio_WriteChannel(LCD_PIN_RS,STD_high);

	/*enter write mode*/
	Dio_WriteChannel(LCD_PIN_RW,STD_low);

	/* apply output data on Bus*/
#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN

	Dio_WriteChannel(LCD_PIN_D0,GET_BIT(u8Data,0));
	Dio_WriteChannel(LCD_PIN_D1,GET_BIT(u8Data,1));
	Dio_WriteChannel(LCD_PIN_D2,GET_BIT(u8Data,2));
	Dio_WriteChannel(LCD_PIN_D3,GET_BIT(u8Data,3));
	Dio_WriteChannel(LCD_PIN_D4,GET_BIT(u8Data,4));
	Dio_WriteChannel(LCD_PIN_D5,GET_BIT(u8Data,5));
	Dio_WriteChannel(LCD_PIN_D6,GET_BIT(u8Data,6));
	Dio_WriteChannel(LCD_PIN_D7,GET_BIT(u8Data,7));

#elif LCD_MODE_SELECTOR == LCD_MODE_4_PIN

	Dio_WriteChannel(LCD_PIN_D4,GET_BIT(u8Data,4));
	Dio_WriteChannel(LCD_PIN_D5,GET_BIT(u8Data,5));
	Dio_WriteChannel(LCD_PIN_D6,GET_BIT(u8Data,6));
	Dio_WriteChannel(LCD_PIN_D7,GET_BIT(u8Data,7));

	/*enable latch*/
	Dio_WriteChannel(LCD_PIN_E,STD_high);
	_delay_us(0.450);
	Dio_WriteChannel(LCD_PIN_E,STD_low);

	Dio_WriteChannel(LCD_PIN_D4,GET_BIT(u8Data,0));
	Dio_WriteChannel(LCD_PIN_D5,GET_BIT(u8Data,1));
	Dio_WriteChannel(LCD_PIN_D6,GET_BIT(u8Data,2));
	Dio_WriteChannel(LCD_PIN_D7,GET_BIT(u8Data,3));

#else
#error LCD_MODE_SELECTOR configuration parameter error
#endif

	/*Enable Latch*/
	Dio_WriteChannel(LCD_PIN_E,STD_high);
	_delay_us(0.450);
	Dio_WriteChannel(LCD_PIN_E,STD_low);
}
void LCD_writeCmd(uint8 u8Cmd)
{


}
void LCD_writeString(uint8* str,uint8 row,uint8 col)
{


}
