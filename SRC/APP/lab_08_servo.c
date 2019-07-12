/*
 * lab_08_servo.c
 *
 *  Created on: Jul 12, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "../EHAL/Servo/Servo.h"
#include "../MCAL/PORT_DRIVER/PORT.h"

void lab_08_servo(void)
{
	PORT_init();
	SERVO_init();
	SERVO_setAngle(0);
	while(1)
	{



	}

}
