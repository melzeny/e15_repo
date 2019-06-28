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
#if(LCD_MODE_SELECTOR == LCD_MODE_8_PIN)
	/*
	 * init LCD in 8 pin mode
	 * 0x38 0b00111000 ==> 0b001<DataLength><NumofRow><Font5*7>--
	 * */
	LCD_writeCmd(0x38);
#elif (LCD_MODE_SELECTOR == LCD_MODE_4_PIN)
	/*
	 * init LCD in 4 pin mode
	 * 0x33
	 * 0x32
	 * 0x28 ==> 0b001<DataLength_4><NumofRow_2><Font5*7>--
	 * */
	LCD_writeCmd(0x33);
	LCD_writeCmd(0x32);
	LCD_writeCmd(0x28);
#endif
	/*
	 * 0x0E 0b00001110 ==> 0b00001<DisplayOn><CursorOn><Blink>
	 * 0x01 0b00000001 ==> 0b0000000<ClearDisplay>
	 */
	LCD_writeCmd(0x0E);
	LCD_writeCmd(LCD_CMD_CLEAR_SCREEN);
	_delay_ms(3);
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
	/* write data to data register */
	Dio_WriteChannel(LCD_PIN_RS,STD_low);

	/*enter write mode*/
	Dio_WriteChannel(LCD_PIN_RW,STD_low);

	/* apply output data on Bus*/
#if LCD_MODE_SELECTOR == LCD_MODE_8_PIN

	Dio_WriteChannel(LCD_PIN_D0,GET_BIT(u8Cmd,0));
	Dio_WriteChannel(LCD_PIN_D1,GET_BIT(u8Cmd,1));
	Dio_WriteChannel(LCD_PIN_D2,GET_BIT(u8Cmd,2));
	Dio_WriteChannel(LCD_PIN_D3,GET_BIT(u8Cmd,3));
	Dio_WriteChannel(LCD_PIN_D4,GET_BIT(u8Cmd,4));
	Dio_WriteChannel(LCD_PIN_D5,GET_BIT(u8Cmd,5));
	Dio_WriteChannel(LCD_PIN_D6,GET_BIT(u8Cmd,6));
	Dio_WriteChannel(LCD_PIN_D7,GET_BIT(u8Cmd,7));

#elif LCD_MODE_SELECTOR == LCD_MODE_4_PIN

	Dio_WriteChannel(LCD_PIN_D4,GET_BIT(u8Cmd,4));
	Dio_WriteChannel(LCD_PIN_D5,GET_BIT(u8Cmd,5));
	Dio_WriteChannel(LCD_PIN_D6,GET_BIT(u8Cmd,6));
	Dio_WriteChannel(LCD_PIN_D7,GET_BIT(u8Cmd,7));

	/*enable latch*/
	Dio_WriteChannel(LCD_PIN_E,STD_high);
	_delay_us(0.450);
	Dio_WriteChannel(LCD_PIN_E,STD_low);

	Dio_WriteChannel(LCD_PIN_D4,GET_BIT(u8Cmd,0));
	Dio_WriteChannel(LCD_PIN_D5,GET_BIT(u8Cmd,1));
	Dio_WriteChannel(LCD_PIN_D6,GET_BIT(u8Cmd,2));
	Dio_WriteChannel(LCD_PIN_D7,GET_BIT(u8Cmd,3));

#else
#error LCD_MODE_SELECTOR configuration parameter error
#endif

	/*Enable Latch*/
	Dio_WriteChannel(LCD_PIN_E,STD_high);
	_delay_us(0.450);
	Dio_WriteChannel(LCD_PIN_E,STD_low);

	_delay_us(100);

}
void LCD_writeString(uint8* str,uint8 row,uint8 col)
{
	uint8 i =0;
	LCD_goToPos(row,col);
	while(str[i]!='\0' && i<LCD_MAX_NUMBER_OF_CHR)
	{
		LCD_writeCharData(str[i]);
		i++;
	}
}

void LCD_goToPos(uint8 row,uint8 col)
{
	/* LCD_writeCmd(0x80 | ((row<<6) | col) ) */
	LCD_writeCmd(0x80 | ((row*0x40) + col) );
}
