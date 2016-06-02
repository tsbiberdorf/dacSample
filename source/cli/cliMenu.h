/*
 * cliMenu.h
 *
 *  Created on: Jun 2, 2016
 *      Author: TBiberdorf
 */

#ifndef SOURCE_CLI_CLIMENU_H_
#define SOURCE_CLI_CLIMENU_H_

#define cliMenuTaskName() ("CLI Menu")
#define cliMenuTaskStackSize() (256)
#define cliMenuTaskPriority() (tskIDLE_PRIORITY + 1)

void cliMenutask(void *pvParameters);



#endif /* SOURCE_CLI_CLIMENU_H_ */
