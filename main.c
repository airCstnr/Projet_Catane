
/* Main */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "de.h"
#include "stats.h"

#define STOP 1

#define DEBLINE printf("\n--- DEB LINE --- %s --- %i ---\n", __FILE__, __LINE__)

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

// ----------------------------------
int main(/*int argc, char const *argv[]*/)
{
	bool stop;
	de_t* de = NULL;
	int stats[12] = {0};
	int val, err;

	FILE* f = fopen("jets.txt", "r+");
	if (f==NULL)
	{
		printf("E: ouverture du fichier jets.txt");
		return -1;
	}

	// ajout de le contenu de f dans la liste des jets
	while (true)
	{
		err = fread(&val, sizeof(int), 1, f);
		if (!err)
			break;
		de_t* nouveau = (de_t*) malloc(sizeof(de_t));
		nouveau->next = de;
		nouveau->val = val;
		de = nouveau;
		stats[val-1]++;
	}
	
	// titre
	titre();

	// menu
	while (stop != STOP)
		stop = menu(&de, stats);


	// ajout de la liste des jets dans f
	while (true)
	{
		val = supprimerCoup(&de, stats);
		if (val == 0)
			break;
		fwrite(&val, sizeof(int), 1, f);
	}

	supprimerListe(&de, stats);

	return 0;
}
