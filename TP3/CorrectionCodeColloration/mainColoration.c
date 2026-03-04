#include<stdio.h>
#include<stdlib.h>
#include "fonctions.h"

int main() {
    struct Graph graph;
    graph.vertices = 5;

    // Initialiser la matrice à 0
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            graph.adjMatrix[i][j] = 0;
        }
    }

    // Ajouter les arêtes
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 0, 3);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    // Appliquer Welsh-Powell
    welshPowell(&graph);

    return 0;
}
