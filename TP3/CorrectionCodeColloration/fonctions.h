#ifndef COLORATION_H
#define COLORATION_H

#define MAX_VERTICES 100

struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void addEdge(struct Graph* graph, int u, int v);

void welshPowell(struct Graph* graph);

#endif
