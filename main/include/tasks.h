#ifndef _ESPTERM_TASKS_
#define _ESPTERM_TASKS_

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define LV_PROC_STACK_SIZE (2 * 1024)
#define UART_PROC_STACK_SIZE (2 * 1024)

void lv_proc_task(void *arg);
void uart_proc_task(void *arg);

#endif // _ESPTERM_TASKS_
