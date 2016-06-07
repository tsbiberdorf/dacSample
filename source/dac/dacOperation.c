/*
 * dacOperation.c
 *
 *  Created on: Jun 2, 2016
 *      Author: TBiberdorf
 */


#include "fsl_debug_console.h"
#include "board.h"
#include "fsl_dac.h"

#include "SEGGER_RTT.h"
#include "SEGGER_SYSVIEW.h"
#include "SEGGER_SYSVIEW_Config.h"

#include "clock_config.h"
#include "pin_mux.h"
/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "dacOperation.h"

#define DAC_1_0_VOLTS 1241U
#define DAC_1_5_VOLTS 1862U
#define DAC_2_0_VOLTS 2482U
#define DAC_2_5_VOLTS 3103U
#define DAC_3_0_VOLTS 3724U
#define DEMO_DAC_BASEADDR DAC0

#define VREF_BRD 3.300
#define SE_12BIT 4096.0

#define DAC_QUEUE_MSG_SIZE (sizeof(int32_t))
#define DAC_QUEUE_SIZE (10)
QueueHandle_t xDacQueue = NULL;

static void dacInit()
{
    dac_config_t dacConfigStruct;

	DbgConsole_Printf("dacInit\r\n\n\n");

	xDacQueue = xQueueCreate(DAC_QUEUE_SIZE,DAC_QUEUE_MSG_SIZE);

    /* Configure the DAC. */
    /*
     * dacConfigStruct.referenceVoltageSource = kDAC_ReferenceVoltageSourceVref2;
     * dacConfigStruct.enableLowPowerMode = false;
     */
    DAC_GetDefaultConfig(&dacConfigStruct);
    DAC_Init(DEMO_DAC_BASEADDR, &dacConfigStruct);

}


void dactask(void *pvParameters)
{
	BaseType_t queueStatus;
	int32_t dacLevel;

	DbgConsole_Printf("dactask started\r\n\n\n");
	dacInit();

	for(;;)
	{
		queueStatus = xQueueReceive(xDacQueue,&dacLevel,(TickType_t)portMAX_DELAY);
		if(queueStatus == pdTRUE)
		{
			SEGGER_RTT_WriteString(0, "Hello World from SEGGER RTT!\r\n");
			DbgConsole_Printf("dactask %x\r\n",dacLevel);
		}
//		vTaskDelay( (TickType_t)(500 / portTICK_PERIOD_MS) );
	}
}
