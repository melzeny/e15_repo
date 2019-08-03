/*
 * TSensor.h
 *
 *  Created on: Jul 26, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_REPO_SRC_EHAL_TEMP_SENSOR_TSENSOR_H_
#define E15_REPO_SRC_EHAL_TEMP_SENSOR_TSENSOR_H_

#include "../../utils/STD_Types.h"

void TSensor_init(void);
sint16 TSensor_readTemprature(void);
#endif /* E15_REPO_SRC_EHAL_TEMP_SENSOR_TSENSOR_H_ */
