#ifndef RTE_DISPLAY_h
#define RTE_DISPLAY_h

#include "Rte_Type.h"
#include "../OS_Events.h"

/*********************************************************************
 * Rte global variables
 *********************************************************************/
extern displayLineString Rte_Logic_DisplayText;
extern int Rte_Logic_RandomNumber;

/*********************************************************************
 * Rte communication functions
 *********************************************************************/
extern void Rte_Read_Display_DisplayText(displayLineString* data);

/*********************************************************************
 * Rte_Read Receivers
 *********************************************************************/
#define Rte_Read_RandomNumber(data) (*(data) = Rte_Logic_RandomNumber)
#define Rte_Read_DisplayText Rte_Read_Display_DisplayText

#endif
