#ifndef LISTE_H
#define LISTE_H

typedef struct point{
    int x, y;
}point;

typedef struct cellule{
    point p;
    struct cellule *pred, *succ;
}cellule;

cellule *NouvelCel(point p);

void InsererCellule(int pl, cellule *cel, cellule **liste);

void SupprimerCellule(int pl, cellule **liste);

void afficher(cellule *liste);

#endif
