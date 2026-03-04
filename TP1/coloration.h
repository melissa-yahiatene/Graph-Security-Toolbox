#ifndef COLORATION_H
#define COLORATION_H

typedef struct graph{
    int nbSommets;
    int **adjacence;
}graph;

typedef struct sommet{
    int num;
    int degre;
}sommet;

//creer un graphe caracterisé par son nombre de sommets et sa matrice d'adjacence
graph *creerGraph(int n);

//ajouter une arete entre deux somment donnés
void ajouterArete(graph *g, int s1, int s2);

//calculer les degrés de chaque sommet
sommet* calculerDegre(graph *g);

//fonction utilitaire pour "qsort" (pour comparer deux elements)
int compareDesc(const void *a, const void *b);

//tri decroissant des degrés
sommet* trierDegre(graph *g);

//implementation de l'algorithme Welsh Powell pour la coloration de graphe
void welshPowell(graph *g);

//liberer l'espace alloué pour le graphe 
void libererGraph(graph *g);

#endif
