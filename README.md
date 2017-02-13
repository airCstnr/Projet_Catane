# Projet Catane

Ce projet personnel est un programme pour saisir les résultats d'un ensemble de jets de deux dés lors d'une partie du jeu Les Colons de Catane (https://fr.wikipedia.org/wiki/Les_Colons_de_Catane)

## Fonctionnement

Compilation de l'exécutable via la commande make.
Exécution via la commande ./prog.

### Titre/Menu

Le menu propose 5 possibilités:
+ ajouter un jet de dés
+ lister les jets de dés (dans l'ordre inverse de l'ajout)
+ supprimer le dernier jet ajouté
+ afficher un histogramme des fréquences de sortie des valeurs
+ quitter (0)

### Structures des données

Les informations conservées sont:
+ les jets de dés dans une liste chaînée (ajout et suppression en temps constant)
+ les fréquences de sortie dans un tableau (taille fixe, modification en temps constant)


### Améliorations possibles

Les différentes possibilités à ajouter sont:
+ obtenir des statistiques plus avancées (moyenne, espérance, variance, ecart type...)
+ pouvoir utiliser 1, 2, 3, 4 ou plus de dés
+ enregistrer les résultats dans un fichier
+ lire les résultats déja enregistrés dans un fichier


## Auteur

Raphaël Castanier, IUT d'informatique de Grenoble
