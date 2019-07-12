/*
 * Servo.c
 *
 *  Created on: Jul 12, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "../../utils/STD_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../config/Servo_cfg.h"
#include "Servo.h"


static uint8 Ton_Steps,Toff_Steps_div_2;

void SERVO_init(void)
{

	TIMER2_init();
	Dio_WriteChannel(SERVO_SIGNAL_PIN,STD_high);
	TIMER2_setCounterSteps(Ton_Steps);

}
void SERVO_setAngle(uint8 Angle)
{
	Ton_Steps =( (Angle * (SERVO_MAX_ANGLE_STEPS-SERVO_MIN_ANGLE_STEPS)) / SERVO_MAX_ANGLE_DEGREE ) +SERVO_MIN_ANGLE_STEPS;
	Toff_Steps_div_2 = SERVO_PWM_SIGNAL_DUARTION_steps_div_2 - (Ton_Steps/2);


}
void ISR(TIMER2_COMP)
{
	static uint8 counter =0;
	counter++;
	if(counter == 1)
	{
		Dio_WriteChannel(SERVO_SIGNAL_PIN,STD_low);
		TIMER2_setCounterSteps(Toff_Steps_div_2);
	}
	else if (counter == 3)
	{
		Dio_WriteChannel(SERVO_SIGNAL_PIN,STD_high);
		TIMER2_setCounterSteps(Ton_Steps);
		counter = 0;
	}

}
