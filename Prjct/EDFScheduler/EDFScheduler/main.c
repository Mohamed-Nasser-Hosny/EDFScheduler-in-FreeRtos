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
TaskHandle_t task2_Handle = NULL;
void Task1(void *p);
void Task2(void *p);

int main(void)
{
	xTaskCreate(Task1, "mytask1", 90,(void *) 0, 1, &task1_Handle, 50);
	xTaskCreate(Task2, "mytask2", 90,(void *) 0, 1, &task2_Handle, 25);
	vTaskStartScheduler();
    /* Replace with your application code */
    while (1) 
    {
    }
}


void Task1(void *p){
	
	DDRA |= (1<<1);
	
	for(;;){	
		
		for(int i =0 ;i < 1000; ++i){
			PORTA |= (1<<1);
		}
		PORTA &=~ (1<<1);
		vTaskDelay(100);		
	}
}
void Task2(void *p){
	
	DDRA |= (1<<2);
	
	for(;;){
		PORTA ^= (1<<2);
		for(int i =0 ;i < 1000; ++i){
			PORTA |= (1<<2);
		}
		PORTA &=~ (1<<2);
		vTaskDelay(100);
	}
}

