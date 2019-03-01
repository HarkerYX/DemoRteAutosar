#include <unistd.h>
#include "OS_Events.h"

EventMaskType eventFlag=0;

// Simulation of an OSEK alarm. Basically just a thread that sets an event after some time
void* AlarmSimulator(void* arg) {
	while (1) {
		usleep(1000000);
		setEvent(Rte_Timer_Logic_Execute);
	}
}
