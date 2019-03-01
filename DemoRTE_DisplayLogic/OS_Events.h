#ifndef OS_EVENTS_h
#define OS_EVENTS_h

#include <stdint.h>
#define EventMaskType uint8_t

#define Rte_Timer_Logic_Execute 1
#define Rte_Ev_Display_RandomNumber_DataReceived 2
#define Rte_Ev_Display_DisplayText_DataReceived 4
#define EVENT_3 8
#define EVENT_4 16
#define EVENT_5 32
#define EVENT_6 64
#define EVENT_7 128

#define setEvent(tosetEV) (eventFlag=eventFlag|(tosetEV))
#define clearEvent(toclearEV) eventFlag=eventFlag&(~(toclearEV))
#define waitEvent(waitEV) while(!(eventFlag&(waitEV)))
#define getEvent(out) ((*out) = eventFlag);

extern EventMaskType eventFlag;

#endif
