#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include "Rte/Rte_Logic.h"

// Application code
void initLogic() {
	srand(time(NULL));
}

int executions = 0;
void LogicDo() {
	/*******************
	 * Int Datatype
	 *******************/
	int rnd = rand()%INT_MAX;
	Rte_Write_RandomNumber(rnd);


	/*******************
	 * Array Datatype
	 *******************/
	displayLineString content;

	/* Send random string */
	for(int i=0; i < sizeof(displayLineString) -1; ++i) {
		content[i] = '0' + rand()%72; // starting on '0', ending on '}'
	}
	content[sizeof(displayLineString)-1] = 0; // terminating zero

	/* Send times of execution */
	// snprintf(content, 16, "%d", executions); 
	//executions++;

	/* Send "Hello!" */
	// strncpy(content, "Hello!", 16); 

	Rte_Write_DisplayText(content);
}



