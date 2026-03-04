#include<stdio.h>
#include<stdlib.h>
#include "operations.h"

int main(){
    int n = 4;
    graph *g = creerGraph(n);

    // Création des sommets
    g->sommets[1] = *nouvSommet('A');
    g->sommets[2] = *nouvSommet('B');
    g->sommets[3] = *nouvSommet('C');
    g->sommets[4] = *nouvSommet('D');

    // Ajouter quelques arêtes
    ajouterArete(g, 1, 2); // A-B
    ajouterArete(g, 1, 3); // A-C
    ajouterArete(g, 2, 3); // B-C
    ajouterArete(g, 3, 4); // C-D

    // Afficher le graphe
    printf("Affichage du graphe :\n");
    afficherGraph(g);

    // Libérer la mémoire
    libererGraph(g);

    return 0;
}
