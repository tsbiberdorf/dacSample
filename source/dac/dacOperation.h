/*
 * dacOperation.h
 *
 *  Created on: Jun 2, 2016
 *      Author: TBiberdorf
 */

#ifndef SOURCE_DAC_DACOPERATION_H_
#define SOURCE_DAC_DACOPERATION_H_

#define dacTaskName() ("DAC Menu")
#define dacTaskStackSize() (256)
#define dacTaskPriority() (configMAX_PRIORITIES - 1)

void dactask(void *pvParameters);

extern QueueHandle_t xDacQueue;



#endif /* SOURCE_DAC_DACOPERATION_H_ */
