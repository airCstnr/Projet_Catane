
// de.h
#ifndef DEF_DE
#define DEF_DE

// liste chainée des dés enregistrés
typedef struct De {
	int val;
	struct De * next;
} de_t;

int saisirJet();

void ajouterJet(de_t** de, int stats[12]);

void listerCoups(de_t* de);

void supprimerCoup(de_t** de, int stats[12]);


void supprimerListe(de_t** de, int stats[12]);




#endif
