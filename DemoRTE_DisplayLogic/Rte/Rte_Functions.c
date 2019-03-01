#include <string.h>
#include "Rte_Type.h"
#include <stdio.h>
#include "../OS_Events.h"

/*********************************************************************
 * Rte global variables
 *********************************************************************/
int Rte_Logic_RandomNumber; 
displayLineString Rte_Logic_DisplayText;

/*********************************************************************
 * Rte_Read functions
 *********************************************************************/
void Rte_Read_Display_DisplayText(displayLineString* data) {
	memcpy(data, Rte_Logic_DisplayText, sizeof(displayLineString));
}

/*********************************************************************
 * Rte_Write functions
 *********************************************************************/
void Rte_Write_Logic_DisplayText(const displayLineString data) {
	memcpy(Rte_Logic_DisplayText, data, sizeof(displayLineString));
	setEvent(Rte_Ev_Display_DisplayText_DataReceived);
}

/*********************************************************************
 * Runnables
 *********************************************************************/
extern void initLogic();
extern void LogicDo();
extern void DisplayPrint();

/*********************************************************************
 * Rte Tasks
 *********************************************************************/
void* LogicTask(void* arg) { // TODO: Naming convention. Can a Application have several Tasks?
	initLogic();

	while (1) {
		waitEvent(Rte_Timer_Logic_Execute); // TODO: Alarm naming convention

		EventMaskType event;
		getEvent(&event);
		clearEvent(Rte_Timer_Logic_Execute); // Difference: OSEK uses different event vectors for every task

		if (event & (Rte_Timer_Logic_Execute)) {
			LogicDo();
		}
	}
}

void* DisplayTask(void* arg) {
	while (1) {
		waitEvent(Rte_Ev_Display_RandomNumber_DataReceived | Rte_Ev_Display_DisplayText_DataReceived);

		EventMaskType event;
		getEvent(&event);
		clearEvent(Rte_Ev_Display_RandomNumber_DataReceived | Rte_Ev_Display_DisplayText_DataReceived); // Difference: OSEK uses different event vectors for every task

		if(event & (Rte_Ev_Display_RandomNumber_DataReceived | Rte_Ev_Display_DisplayText_DataReceived)) {
			DisplayPrint();
		}
	}
}

