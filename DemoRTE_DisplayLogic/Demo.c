/*********************************************************************
 * This program generates random stuff within the "Logic" application
 * and sends it through a hard coded RTE to a Display application
 * 
 * LogicDo is executed every second through a simulated alarm received
 * by LogicTask. Writing a variable sets a DataReceived event in 
 * DisplayTask which calls Display.
 *********************************************************************/
/*********************************************************************
 * This is a code example for a simple Sender/Receiver communication.
 * Example cases are:
 *  - how to locally handle primitive datatypes -> int, float, ..
 *  - hot to locally handle array datatypes -> string, int[], ..
 *  - Broadcast is possible
 *  - set DataReceived-Events
 * 
 * File structure is similar to the real AUTOSAR RTE. It's possible
 * to add e. g. Bluetooth communication by only changing RTE files.
 * This means without touching any application source code.
 * 
 * Every application has its own Rte_ header with applicationspecific 
 * #defines to use for the developer. Simple assignments will be done 
 * in the defines (e. g. primitives). More complex communications 
 * happen through functions within the Rte_Functions.c-source file.
 * 
 * Every port will generate a DataReceived event. Runnables can be 
 * mapped to triggers (e. g. events). When an event is received
 * the mapped runnables will be executed.
 * 
 * Variables shall only have a single Sender, therefore its naming is
 * connected to the Sender. There can be several Receivers reading.
 * 
 * Custom datatypes can be specified in Rte_Type.h and don't have a
 * naming convention yet. 
 *
 * Receiver: Rte_Read_<port>
 * Sender:   Rte_Write_<port>
 * Read function:  Rte_Read_<application>_<port>
 * Write function: Rte_Write_<application>_<port>
 * Variable: Rte_<application>_<port>
 * Implicite DataReceived event: Rte_Ev_<application>_<port>_DataReceived
 * 
 *********************************************************************/
#include <stdio.h>
#include <pthread.h>
#include "OS_Events.h"

extern void* LogicTask(void*);
extern void* DisplayTask(void*);

extern void* AlarmSimulator(void*);

int main() {
	pthread_t pth[3];
	
	pthread_create(&pth[0], NULL, LogicTask, NULL);
	pthread_create(&pth[1], NULL, DisplayTask, NULL);
	pthread_create(&pth[2], NULL, AlarmSimulator, NULL);

	pthread_join(pth[0], NULL);
	pthread_join(pth[1], NULL);
	pthread_join(pth[2], NULL);

	return 0;
}

