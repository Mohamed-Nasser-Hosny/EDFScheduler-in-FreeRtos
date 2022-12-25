/*
 * EDFScheduler.c
 *
 * Created: 12/25/2022 6:59:33 AM
 * Author : Mohamed Nasser
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"

TaskHandle_t task1_Handle = NULL;
void Task1(void *p);

int main(void)
{
	xTaskCreate(Task1, "mytask1", 90,(void *) 0, 1, &task1_Handle);
	vTaskStartScheduler();
    /* Replace with your application code */
    while (1) 
    {
    }
}


void Task1(void *p){
	
	DDRA |= (1<<1);
	
	for(;;){
		
		PORTA ^= (1<<1);
		vTaskDelay(100);
			
		
	}
	
	
	
}