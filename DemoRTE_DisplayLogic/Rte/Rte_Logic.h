#ifndef RTE_LOGIC_h
#define RTE_LOGIC_h

#include "Rte_Type.h"
#include "../OS_Events.h"

/*********************************************************************
 * Rte global variables
 *********************************************************************/
extern int Rte_Logic_RandomNumber; 
extern displayLineString Rte_Logic_DisplayText;

/*********************************************************************
 * Rte communication functions
 *********************************************************************/
extern void Rte_Write_Logic_DisplayText(displayLineString data);

/*********************************************************************
 * Rte_Write Senders
 *********************************************************************/
#define Rte_Write_RandomNumber(data) (Rte_Logic_RandomNumber = (data), setEvent(Rte_Ev_Display_RandomNumber_DataReceived))
#define Rte_Write_DisplayText Rte_Write_Logic_DisplayText

#endif
