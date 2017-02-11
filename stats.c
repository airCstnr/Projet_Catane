
/* Stats */


#include <stdio.h>
#include <stdlib.h>

#include "stats.h"

// ----------------------------------
float moyenne(int stats[12])
{
	int sum = 0, nb = 0;
	for (int i = 1; i < 12; ++i)
	{
		sum += stats[i] * i;
		nb += stats[i];
	}
	return (float) sum/nb;

}

// ----------------------------------
void afficherLigne(int val, int longueur)
{
	printf("%i\t", val);
	for (int i = 0; i < longueur; ++i)
	{
		printf("*");
	}
	printf("\n");
}

// ----------------------------------
void afficherHisto(int stats[12])
{
	printf("Histogramme : \n");
	for (int i = 2; i < 13; ++i)
	{
		afficherLigne(i, stats[i-1]);
	}
}