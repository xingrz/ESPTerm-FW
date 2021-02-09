#ifndef _ESPTERM_TASKS_
#define _ESPTERM_TASKS_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define GUI_PROC_STACK_SIZE (16 * 1024)

void gui_proc_task(void *arg);

#endif // _ESPTERM_TASKS_
