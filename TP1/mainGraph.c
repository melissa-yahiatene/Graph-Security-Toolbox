#include<stdio.h>
#include<stdlib.h>
#include "coloration.h"

int main(){
    int n;
    int s1, s2, rep;
    graph *g;

    printf("Nombre de sommets du graphe ? : ");
    fflush(stdout);
    scanf("%d", &n);

    g = creerGraph(n);

    printf("Ajouter les aretes :\n");
    fflush(stdout);

    do{

        do{
            printf("Les sommets a relier avec une arete ? (s1 s2) : ");
            fflush(stdout);
            scanf("%d %d", &s1, &s2);
        }while(s1<0 || s1>=n || s2<0 || s2>=n);

        ajouterArete(g, s1, s2);
        printf("\nVoulez-vous ajouter une autre arete ? (1:OUI | 2:NON) : ");
        fflush(stdout);
        scanf("%d", &rep);
    }while(rep==1);

    printf("\n================================================\n");
    printf("Coloration du graphe:\n");
    fflush(stdout);

    welshPowell(g);

    libererGraph(g);

}

