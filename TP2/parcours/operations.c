#include<stdio.h>
#include<stdlib.h>
#include "operations.h"

//creer un noeud et l'initialiser
noeud *nouvNoeud(char carac){
    static int compteur=0;
    compteur++;

    noeud *n = (noeud*)malloc(sizeof(noeud));
    if(n==NULL){
        printf("Probleme d'allocation memeoire !");
        exit(1);
    }

    (n->val) = carac;
    (n->num)=compteur;
    (n->fils_gauche)=NULL;
    (n->fils_droit)=NULL;

    return n;
}

//rechercher un noeud dans un arbre 
noeud *rechercheNoeud(noeud *n, int num_noeud){
    noeud *tmpNoeud;
    noeud *result;

    if(n==NULL){
        result = NULL;
    }
    else if((n->num)==num_noeud){
        result = n;
    }else{
        tmpNoeud = rechercheNoeud((n->fils_gauche), num_noeud);

        if(tmpNoeud!=NULL){
            result = tmpNoeud;
        }
        else{
            result = rechercheNoeud((n->fils_droit), num_noeud);
        }
    }
    return result;
}

//Insertion d'un noeud comme fils gauche
void insererFG(noeud *newNoeud, noeud *arbre, int num_pere){
    noeud *pere =rechercheNoeud(arbre, num_pere);
    if(pere==NULL){
        printf("Probleme d'allocation memeoire !");
        exit(1);
    }
    noeud *tmpNoeud;

    if((pere->fils_gauche)==NULL){
        (pere->fils_gauche)=newNoeud;
    }
    else{
        tmpNoeud = (pere->fils_gauche);
        (pere->fils_gauche) = newNoeud;
        (newNoeud->fils_gauche) = tmpNoeud;
    }
}

//Insertion d'un noeud comme fils droit
void insererFD(noeud *newNoeud, noeud *arbre, int num_pere){
    noeud *pere = rechercheNoeud(arbre, num_pere);
    if(pere==NULL){
        printf("Probleme d'allocation memeoire !");
        exit(1);
    }
    noeud *tmpNoeud;

    if((pere->fils_droit)==NULL){
        pere->fils_droit = newNoeud;
    }
    else{
        tmpNoeud = (pere->fils_droit);
        (pere->fils_droit) = newNoeud;
        (newNoeud->fils_droit) = tmpNoeud;
    }
}

//parcours Prefixe d'un arbre
void parcoursPrefixe(noeud *racine){
    if(racine==NULL) return;

    printf("%c\t", (racine->val));
    fflush(stdout);
    parcoursPrefixe((racine->fils_gauche));
    parcoursPrefixe((racine->fils_droit));
}

//Parcours Infixe d'un arbre
void parcoursInfixe(noeud *racine){
    if(racine==NULL) return;

    parcoursInfixe((racine->fils_gauche));
    printf("%c\t", (racine->val));
    fflush(stdout);
    parcoursInfixe((racine->fils_droit));
}

//Parcours Suffixe d'un arbre
void parcoursSuffixe(noeud *racine){
    if(racine==NULL) return;

    parcoursSuffixe((racine->fils_gauche));
    parcoursSuffixe((racine->fils_droit));
    printf("%c\t", (racine->val));
    fflush(stdout);
}

//fonctions utilitaires :
//sauvegarder les numeros des noeuds créés
void ajoutNumero(int n, int tab[n], int num){
    static int indice = 0;
    tab[indice]=num;
    indice++;
}

//verifier si un numero a deja été attribué
int existeNum(int n, int tab[n], int num){
    int existe = 0;
    for(int i=0; i<n && existe==0; i++){
        if(tab[i]==num){
            existe = 1;
        }
    }
    return existe;
}




