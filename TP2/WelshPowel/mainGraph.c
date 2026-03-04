#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "coloration.h"

int main(){

    char **cles;
    graph *g = chargerGraphFich("Carte.txt", &cles);

    printf("\n===================================================\n");
    fflush(stdout);

    printf("Coloration du graphe:\n");
    fflush(stdout);

    welshPowell(g, cles);

    libererCles(cles, g->nbSommets);
    libererGraph(g);

}

