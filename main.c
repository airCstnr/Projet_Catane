
/* Main */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "de.h"
#include "stats.h"
#include "interface.h"

#define STOP 1

// ----------------------------------
int main(/*int argc, char const *argv[]*/)
{
	bool stop;
	de_t* de = NULL;
	int stats[12] = {0};

	lecture(&de, stats);

	// titre
	titre();

	// menu
	while (stop != STOP)
		stop = menu(&de, stats);

	ecriture(&de, stats);

	return EXIT_SUCCESS;
}
