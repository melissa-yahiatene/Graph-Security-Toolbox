#include<stdio.h>
#include<stdlib.h>
#include "operations.h"

#define NB 40 

int main(){

    noeud *racine = nouvNoeud('B');
    noeud *n1 = nouvNoeud('A');
    noeud *n2 = nouvNoeud('O');
    noeud *n3 = nouvNoeud('R');
    noeud *n4 = nouvNoeud('V');

    insererFG(n1, racine, 1);
    insererFD(n2, racine, 1);
    insererFG(n3, racine, 1);
    insererFD(n4, racine, 4);

    printf("\n===============================================\n");
    //parcours prefixe de l'arbre créé : 
    printf("Parcours prefixe de l'arbre :\n");
    parcoursPrefixe(racine);

    printf("\n===============================================\n");
    //parcours infixe de l'arbre créé : 
    printf("Parcours infixe de l'arbre :\n");
    parcoursInfixe(racine);

    printf("\n===============================================\n");
    //parcours suffixe de l'arbre créé : 
    printf("Parcours suffixe de l'arbre :\n");
    parcoursSuffixe(racine);


    free(racine);
    free(n1);
    free(n2);
    free(n3);
    free(n4);

    return(EXIT_SUCCESS);
}