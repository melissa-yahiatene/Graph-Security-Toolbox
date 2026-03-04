#ifndef GRAPHE_H
#define GRAPHE_H

typedef struct voisin{
    int num;
    struct voisin *suiv;
}voisin;

//representation d'un sommet d'un graphe
typedef struct sommet{
    char val;
    int num;
    voisin *listeVoisins; //la liste des voisins d'un sommet
}sommet;

typedef struct graph{
    int nbSommets; //le nombre de sommets
    sommet *sommets; //liste des sommets du graphes
}graph;

//creer un sommet et l'initialiser
sommet *nouvSommet(char carac);

//creer un graphe
graph *creerGraph(int n);

//ajouter une arete entre deux sommets donnés
void ajouterArete(graph *g, int s1, int s2);

// Afficher le graphe
void afficherGraph(graph *g);

// Libérer la mémoire
void libererGraph(graph *g);


#endif

