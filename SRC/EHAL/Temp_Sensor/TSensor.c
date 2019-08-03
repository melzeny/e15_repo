/*
 * TSensor.c
 *
 *  Created on: Jul 26, 2019
 *      Author: Kirolos.Vector
 */
#include "../../utils/STD_Types.h"
#include "../../utils/Bit_Math.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../config/TSensor_cfg.h"

void TSensor_init(void)
{
	ADC_init(TSensor_CONNECTED_PIN);

}
sint16 TSensor_readTemperature(void)
{
	sint16 Temp=0;
	uint32 Voltage_mv = ADC_getVoltage_m(TSensor_CONNECTED_PIN);

	/*
	 * apply First Degree Linear equation
	 *
	 * x-x1   x2-x1
	 * ---- = ----
	 * y-y1   y2-y1
	 */
	/*implement equation to get temperature with given voltage_mv*/
	Temp = ( (TSensor_MAX_Degree-TSensor_MIN_Degree) * Voltage_mv / TSensor_MAX_VOLTAGE ) - TSensor_MIN_Degree;
	return Temp;
}
