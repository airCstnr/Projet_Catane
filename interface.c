

/* Interface */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stats.h"
#include "de.h"
#include "interface.h"



// ----------------------------------
void titre()
{
	printf("\n ================================");
	printf("\n|         Projet Catane          |");
	printf("\n ================================\n");
	printf("Menu :\n");
	printf("1\tAjouter un jet de dés\n");
	printf("2\tLister les coups\n");
	printf("3\tSupprimer le dernier coup\n");
	printf("4\tVoir les stats\n");
	printf("0\tQuitter\n");
}

// ----------------------------------
int saisirEntier()
{
	int i, err = 0, c;
	do
	{
		printf(">> ");
		err = scanf("%i", &i);
		while ((c=getchar()) != '\n');
		fflush(stdin);
	} while (err == 0 || i > 4 || i < 0);
	return i;
}

// ----------------------------------
bool menu(de_t** de, int stats[12])
{
	
	printf("\nMenu ");

	// saisir
	int m = saisirEntier();

	// switch case
	switch (m)
	{
		case 0:
			printf("Quitter...\n");
			return STOP;
		case 1:
			// ajouter un jet de dés
			printf("Ajout d'un jet de dés...\n");
			ajouterJet(de, stats);
			break;
		case 2:
			// lister les coups
			printf("Liste des coups...\n");
			listerCoups(*de);
			break;
		case 3:
			// supprimer le dernier coup
			printf("Supprimer le dernier coup ajouté...\n");
			supprimerCoup(de, stats);
			break;
		case 4:
			// voir les stats
			printf("Affichage des stats...\n");
			afficherHisto(stats);
			break;
		default:
			break;
	}
	return !STOP;
}


void lecture(de_t** de, int stats[12])
{
	int val, err;
	de_t* last = NULL;

	// ouverture du fichier de sérialisation
	FILE* f = fopen("jets.txt", "r");
	if (!f)
	{
		printf("E: ouverture du fichier jets.txt\n");
	}

	// ajout de le contenu de f dans la liste des jets
	while (true)
	{
		err = fread(&val, sizeof(int), 1, f);
		if (!err)
			break;
		de_t* nouveau = (de_t*) malloc(sizeof(de_t));
		nouveau->next = NULL;
		nouveau->val = val;
		if (last)
		{
			last->next = nouveau;
		}
		else
		{
			*de = nouveau;
		}
		last = nouveau;
		stats[val-1]++;
	}
	
	fclose(f);
}

void ecriture(de_t** de, int stats[12])
{
	int val;

	// ouverture du fichier de sérialisation
	FILE* f = fopen("jets.txt", "w");
	if (!f)
	{
		printf("E: ouverture du fichier jets.txt\n");
	}

	// ajout de la liste des jets dans f
	while (true)
	{
		val = supprimerCoup(de, stats);
		if (!val)
			break;
		fwrite(&val, sizeof(int), 1, f);
	}

	// libération de la liste
	supprimerListe(de, stats);

	fclose(f);

}

