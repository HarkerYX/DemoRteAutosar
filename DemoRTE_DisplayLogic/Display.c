#include <stdio.h>
#include "Rte/Rte_Display.h"

void DisplayClear() {
	printf("\r\033[K"); // delete till end of line
}

void DisplayPrint() {
	DisplayClear();

	// Read int
	int rnd;
	Rte_Read_RandomNumber(&rnd);
	printf("%d", rnd);

	// Read arraytype
	displayLineString content;
	Rte_Read_DisplayText(&content);
	printf(" %s", content);

	// Make sure stdout writes now
	fflush(stdout);
}
