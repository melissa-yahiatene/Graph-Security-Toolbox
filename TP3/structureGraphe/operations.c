#include<stdio.h>
#include<stdlib.h>
#include "operations.h"


//creer un sommet et l'initialiser
sommet *nouvSommet(char carac){
    static int compteur=0;
    compteur++;

    sommet *s = (sommet*)malloc(sizeof(sommet));
    if(s==NULL){
        printf("Probleme d'allocation memeoire !");
        exit(1);
    }

    (s->val)=carac;
    (s->num)=compteur;
    (s->listeVoisins) = NULL;

    return s;
}

//creer un graphe
graph *creerGraph(int n){
    graph *g = (graph*)malloc(sizeof(graph));
    if(g==NULL){
        printf("Probleme d'allocation memeoire !");
        exit(1);
    }

    g->nbSommets=n;

    g->sommets = (sommet*)malloc(n*sizeof(sommet));

    return g;
}

//ajouter une arete entre deux sommets donnés
void ajouterArete(graph *g, int s1, int s2){

    if(s1>(g->nbSommets) || s1<1){
        printf("Le sommet %d n'appartient pas au graphe !\n", s1);
    }
    else if(s2>(g->nbSommets) || s2<1){
        printf("Le sommet %d n'appartient pas au graphe !\n", s2);
    }
    else{
        // Ajouter s2 dans la liste des voisins de s1
        voisin *v1 = (voisin*)malloc(sizeof(voisin));
        v1->num = s2;
        v1->suiv  = g->sommets[s1].listeVoisins;
        g->sommets[s1].listeVoisins = v1;

        // Ajouter s1 dans la liste des voisins de s2
        voisin *v2 = (voisin*)malloc(sizeof(voisin));
        v2->num = s1;
        v2->suiv  = g->sommets[s2].listeVoisins;
        g->sommets[s2].listeVoisins = v2;
    }
}

// Afficher le graphe
void afficherGraph(graph *g) {
    for (int i = 1; i <=g->nbSommets; i++) {
        printf("Sommet %c (%d) : ", g->sommets[i].val, g->sommets[i].num);
        voisin *v = g->sommets[i].listeVoisins;
        while (v != NULL) {
            printf("%c (%d) ", g->sommets[v->num].val, v->num);
            v = v->suiv;
        }
        printf("\n");
    }
}

// Libérer la mémoire
void libererGraph(graph *g) {
    for (int i = 1; i <= g->nbSommets; i++) {
        voisin *v = g->sommets[i].listeVoisins;
        while (v != NULL) {
            voisin *tmp = v;
            v = v->suiv;
            free(tmp);
        }
    }
    free(g->sommets);
    free(g);
}
