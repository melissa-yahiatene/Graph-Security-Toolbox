#include<stdio.h>
#include<stdlib.h>
#include "fonctions.h"


int graph[MAX_VERTICES][MAX_VERTICES];

void addEdge(struct Graph* graph, int u, int v) {
    //Ajout d'un controle sur les indices des sommets à relier
    if(u < 0 || u >= graph->vertices || v < 0 || v >= graph->vertices){
        printf("Erreur: Indices sommets hors bornes !\n");
    }
    else{
        graph->adjMatrix[u][v] = 1;
        graph->adjMatrix[v][u] = 1;
    }
}

void welshPowell(struct Graph* graph) {
    int i, j;
    int degree[MAX_VERTICES];
    int current_color;

    // Calculer le degré de chaque sommet
    for (i = 0; i < graph->vertices; i++) {
        degree[i] = 0;
        for (j = 0; j < graph->vertices; j++) {
            if (graph->adjMatrix[i][j] == 1) {
                degree[i]++;
            }
        }
    }

    int sorted_vertices[MAX_VERTICES];

    // Initialiser les sommets dans l'ordre décroissant des degrés
    for (i = 0; i < graph->vertices; i++) {
        sorted_vertices[i] = i;
    }

    // Tri décroissant des sommets selon leur degré (bubble sort)
    for (i = 0; i < graph->vertices - 1; i++) {
        for (j = 0; j < graph->vertices - i - 1; j++) {
            if (degree[sorted_vertices[j]] < degree[sorted_vertices[j + 1]]) {
                int temp = sorted_vertices[j];
                sorted_vertices[j] = sorted_vertices[j + 1];
                sorted_vertices[j + 1] = temp;
            }
        }
    }

    //initialiser le tableau des couleurs à -1 ( int color[MAX_VERTICES]={-1} n'initialise que la premiere couleur (color[0] à -1) )
    int color[MAX_VERTICES];
    for (i = 0; i < MAX_VERTICES; i++) {
        color[i] = -1;
    }

    current_color = 0;
    color[sorted_vertices[0]] = current_color;

    // Assigner les couleurs aux sommets restants

    
    for (i = 1; i < graph->vertices; ++i) {
        int vertex = sorted_vertices[i];
        if (color[vertex] == -1) {
            int couleurAttribuee=-1;
            //on teste toutes les couleurs
            for(int c=0; c<=current_color && couleurAttribuee==-1; c++){
                int uncolored_adjacent = 1;
                for (j = 0; j < graph->vertices; j++) {
                    if (graph->adjMatrix[vertex][j] == 1 && color[j] == c) {
                        uncolored_adjacent = 0;
                        break;
                    }
                }
                if(uncolored_adjacent){
                    color[vertex]=c; 
                    couleurAttribuee=c;
                }
            }
            if(couleurAttribuee==-1){
                color[vertex] = ++current_color; //on lui attribue une nouvelle couleur 
            }
            
        }
    }

    int num_colors = current_color + 1;

    printf("Graph colored using %d colors.\n", num_colors);
    for (i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}


