/*
 * scheduler.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Administrator
 */

//#ifndef INC_SCHEDULER_H_
//#define INC_SCHEDULER_H_
//
//#include <stdint.h>
//#define SCH_MAX_TASKS 40
//void SCH_Init(void);
//void SCH_Add_Task(void (*pFuntion)(), uint32_t DELAY, uint32_t PERIOD);
//void SCH_Update(void);
//void SCH_Dispatch_Tasks(void);
//void SCH_Delete_Tasks();
////
//#endif /* INC_SCHEDULER_H_ */
/*
 * scheduler.h
 *
 *  Created on: Oct 30, 2024
 *      Author: Administrator
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>
#define SCH_MAX_TASKS 40
typedef struct{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;

	uint32_t TaskID;
}sTasks;

void SCH_Init(void);
void SCH_Add_Task(void (*pFuntion)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint8_t SCH_Delete_Tasks(uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */
