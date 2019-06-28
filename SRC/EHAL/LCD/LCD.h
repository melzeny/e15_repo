/*
 * LCD.h
 *
 *  Created on: Jun 28, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_EHAL_LCD_LCD_H_
#define E15_REPO_SRC_EHAL_LCD_LCD_H_

#include "../../utils/STD_Types.h"

void LCD_init(void);
void LCD_writeCharData(uint8 u8Data);
void LCD_writeCmd(uint8 u8Cmd);
void LCD_writeString(uint8* str,uint8 row,uint8 col);
void LCD_goToPos(uint8 row,uint8 col);
void LCD_storeCustomChr(uint8* Ptr2CustomChr,uint8 CGRAM_index);
void LCD_DisplayCustomChr(uint8 CGRAM_index,uint8 row,uint8 col);

#endif /* E15_REPO_SRC_EHAL_LCD_LCD_H_ */
