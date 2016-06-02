/*
 * cliMenu.c
 *
 *  Created on: Jun 2, 2016
 *      Author: TBiberdorf
 */

#include "fsl_debug_console.h"

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "dac/dacOperation.h"
#include "cliMenu.h"

static void cliMenuInit()
{

}

static void displayMenu()
{
	DbgConsole_Printf("option 1 - DAC 1.0V\r\n");
	DbgConsole_Printf("option 2 - DAC 1.5V\r\n");
	DbgConsole_Printf("option 3 - DAC 2.0V\r\n");
	DbgConsole_Printf("option 4 - DAC 2.5V\r\n");
	DbgConsole_Printf("option 5 - DAC 3.0V\r\n");
}

void cliMenutask(void *pvParameters)
{
	int32_t menu;
	BaseType_t queueStatus;
	DbgConsole_Printf("cliMenuTask started\r\n\n\n");
	cliMenuInit();

	for(;;)
	{
		menu = DbgConsole_Getchar();
		displayMenu();
		switch(menu-'0')
		{
		case 1:
			DbgConsole_Printf("option 1 selected \r\n");
			if(xDacQueue)
			{
				queueStatus = xQueueSend(xDacQueue,&menu,(TickType_t)10);
				assert(queueStatus);
			}
			break;
		case 2:
			DbgConsole_Printf("option 2 selected \r\n");
			queueStatus = xQueueSend(xDacQueue,&menu,(TickType_t)10);
			assert(queueStatus);
			break;
		case 3:
			DbgConsole_Printf("option 3 selected \r\n");
			queueStatus = xQueueSend(xDacQueue,&menu,(TickType_t)10);
			assert(queueStatus);
			break;
		case '?'+'0':
			displayMenu();
			break;
		default:
			DbgConsole_Printf("unknown selected \r\n");
		}
		//		vTaskDelay( (TickType_t)(500 / portTICK_PERIOD_MS) );
	}
}
