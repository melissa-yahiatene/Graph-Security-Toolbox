#ifndef ARBRE_H
#define ARBRE_H

//Representation d'un noeud d'un arbre
typedef struct noeud{
    char val;
    int num;
    struct noeud *fils_gauche;
    struct noeud *fils_droit;
}noeud;

//creer un noeud et l'initialiser
noeud *nouvNoeud(char carac);

//rechercher un noeud dans un arbre
noeud *rechercheNoeud(noeud *n, int num_noeud);

//Insertion d'un noeud comme fils gauche
void insererFG(noeud *newNoeud, noeud *arbre, int num_pere);

//Insertion d'un noeud comme fils droit
void insererFD(noeud *newNoeud, noeud *arbre, int num_pere);

//Parcours Prefixe d'un arbre
void parcoursPrefixe(noeud *racine);

//fonctions utilitaires :
//sauvegarder les numeros des noeuds créés
void ajoutNumero(int n, int tab[n], int num);

//verifier si un numero a deja été attribué
int existeNum(int n, int tab[n], int num);

#endif

