#include<stdio.h>
#include<stdlib.h>
#include "liste.h"

int main() {
    cellule *liste = NULL, *cel = NULL;

    point *p;
    int pl;

    int rep=1;
    int i=1;

    printf("Insertion des points :\n");
    do{
        p = (point*) malloc(sizeof(point));
        if(p==NULL){
            printf("Probleme d'allocation memeoire !");
            exit(1);
        }
        printf("Inserer les coordonnees X et Y du Point(%d) dans cet ordre: ",i);
        scanf("%d %d",&p->x,&p->y);
        fflush(stdin);

        cel = NouvelCel(*p);
        printf("A quel emplacement voulez-vous inserer cette cellule ? ");
        scanf("%d",&pl);
        fflush(stdin);

        InsererCellule(pl,cel,&liste);

        printf("\nVoulez vous inserer un autre point ? O: NON | 1: OUI ");
        scanf("%d",&rep);
        fflush(stdin);
        i++;
    }while(rep==1);

    afficher(liste);
    do {
        printf("\nQuel est l'emplacement de la cellule que vous souhaitez supprimer ? ");
        scanf("%d",&pl);
        SupprimerCellule(pl-1,&liste);

        printf("\nVoulez vous supprimer un autre point ? O: NON | 1: OUI ");
        scanf("%d",&rep);
        fflush(stdin);
        i++;
    }while(rep==1);

    afficher(liste);

    free(p);
    free(liste);
    free(cel);

    return 0;
}