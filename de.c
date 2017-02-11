
/* Dés */

#include <stdio.h>
#include <stdlib.h>

#include "de.h"
#include "stats.h"


// ----------------------------------
int saisirJet()
{
	int i, err = 0, c;
	do
	{
		printf(">> ");
		err = scanf("%i", &i);
		while ((c=getchar()) != '\n');
		fflush(stdin);
	} while (err == 0 || i > 12 || i < 2);
	return i;
}



// ----------------------------------
void ajouterJet(de_t** de, int stats[12])
{
	int val;
	printf("Saisir valeur : \n");
	val = saisirJet();
	de_t* nouveau = (de_t*) malloc(sizeof(de_t));
	nouveau->next = *de;
	nouveau->val = val;
	*de = nouveau;
	stats[val-1]++;
	return;
} 



// ----------------------------------
void listerCoups(de_t* de)
{
	if (de==NULL)
		return;
	printf("%i\n", de->val);
	listerCoups(de->next);
	return;
}

// ----------------------------------
void supprimerCoup(de_t** de, int stats[12])
{
	de_t* tmp = *de;
	if (*de!=NULL)
	{
		stats[(*de)->val -1]--;
		*de = (*de)->next;
	}
	free(tmp);
	return;
}


// ----------------------------------
void supprimerListe(de_t** de, int stats[12])
{
	while (*de != NULL)
	{
		supprimerCoup(de, stats[12]);
	}
	return;

}
























