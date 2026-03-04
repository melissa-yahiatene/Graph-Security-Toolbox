#include<stdio.h>
#include<stdlib.h>
#include "coloration.h"

//creer un graphe caracterisé par son nombre de sommets et sa matrice d'adjacence
graph *creerGraph(int n){
    graph *g = (graph*)malloc(sizeof(graph));
    if(g==NULL){
        printf("Problème d'allocation memeoire !");
        exit(1);
    }

    g->nbSommets =n;

    (g->adjacence) = calloc(n, sizeof(int*));
    if((g->adjacence)==NULL){
        printf("Probleme d'allocation memeoire !");
        exit(1);
    }
    for(int i=0; i<n; i++){
        g->adjacence[i] = calloc(n, sizeof(int));
        if((g->adjacence[i])==NULL){
            printf("Probleme d'allocation memeoire !");
            exit(1);
        }
    }

    return g;
}

//ajouter une arete entre deux somment donnés
void ajouterArete(graph *g, int s1, int s2){
    g->adjacence[s1][s2]=1;
    g->adjacence[s2][s1]=1;
}

//calculer les degrés de chaque sommet
sommet* calculerDegre(graph *g){
    sommet *tab = (sommet*)calloc(g->nbSommets, sizeof(sommet));
    if(tab==NULL){
        printf("Probleme d'allocation memeoire !");
        exit(1);
    }
    int deg;

    for(int i=0; i<g->nbSommets; i++){
        deg=0;
        for(int j=0; j<g->nbSommets; j++){
            deg += (g->adjacence[i][j]); //somme de la ligne = degre d'un sommet    
        }
        tab[i].num=i;
        tab[i].degre=deg;
    }

    return tab;
}
//fonction utilitaire pour "qsort" (pour comparer deux elements)
int compareDesc(const void *a, const void *b) {
    const sommet *sa = (const sommet*)a;
    const sommet *sb = (const sommet*)b;
    return (sb->degre) - (sa->degre);
}

//tri decroissant des degrés
sommet* trierDegre(graph *g){
    sommet *tab = calculerDegre(g);
    if(tab==NULL){
        printf("Probleme calcul degre !");
        exit(1);
    }

    qsort(tab, (g->nbSommets), sizeof(sommet), compareDesc);

    return tab;
}

//implementation de l'algorithme Welsh Powell pour la coloration de graphe
void welshPowell(graph *g){
    sommet *degresTries = trierDegre(g);

    int couleur[g->nbSommets];

    for(int i=0; i<(g->nbSommets); i++){
        couleur[i]=-1;
    }

    int couleur_courante =0;
    couleur[degresTries[0].num]=couleur_courante;
    int adjacentNonColore; //variable booléenne
    int sommet;

    for(int i=1; i<(g->nbSommets); i++){
        sommet = degresTries[i].num;

        if(couleur[sommet]==-1){ //si le sommet et non déjà coloré
            int couleurAttribuee=-1;
            //on teste toutes les couleurs
            for(int c=0; c<=couleur_courante && couleurAttribuee==-1; c++){
                adjacentNonColore=1; 
                for(int j=0; j<(g->nbSommets) && (adjacentNonColore==1); j++){
                    if(g->adjacence[sommet][j]==1 && couleur[j]==c){ //on verifie si le sommet a un voisin déjà coloré avec la couleur actuelle ( si oui, on ne va pas lui attribuer cette couleur)
                    adjacentNonColore=0;
                    }  
                }

                if(adjacentNonColore){
                    couleur[sommet]=c; 
                    couleurAttribuee=c;
                }
            }
            if(couleurAttribuee==-1){
                couleur[sommet] = ++couleur_courante; //on lui attribue une nouvelle couleur 
            }    
        }
    }

    printf("Le graphe a ete colore avec <%d> couleurs\n", (couleur_courante+1));
    for(int i=0; i<(g->nbSommets); i++){
        printf("Sommet %d: Couleur: %d\n", i, couleur[i]);
    }
}

//liberer l'espace alloué pour le graphe 
void libererGraph(graph *g){
    for(int i=0; i<(g->nbSommets); i++){
        free(g->adjacence[i]);
    }

    free(g->adjacence);
    free(g);
}