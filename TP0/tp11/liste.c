#include<stdio.h>
#include<stdlib.h>
#include "liste.h"

cellule *NouvelCel(point p) {
    cellule *c=malloc(sizeof(cellule));
    if(c==NULL){
        printf("Probleme d'allocation memeoire !");
        exit(1);
    }
    (c->p) = p;
    (c->pred) = NULL;
    (c->succ) = NULL;
    return c;
}


void InsererCellule(int pl, cellule *cel, cellule **liste) {

    //Si cellule est NULL, Erreur : rien à insérer
    if(cel==NULL) {
        printf("Erreur sur la cellule a inserer ! \n");
        return;
    }

    //Insertion en tete de la liste si pl=0 ( donc insertion à 1) ou La liste est vide ( donc tete = cellule)
    if(pl==0 || *liste == NULL) {
        cel->succ=*liste;
        cel->pred=NULL;
        if(*liste !=NULL)
            (*liste)->pred=cel;

        *liste = cel;
    }
    else {
        cellule *ptr = *liste; //cellule tampon

        //Parcourir la liste
        int i=0;
        while(ptr->succ!=NULL && i<pl-1) {
            ptr=ptr->succ;
            i++;
        }

        //Taille de la liste dépassée (pl dépasse la taille de la queue ) -> insertion à la queue
        if(ptr->succ==NULL) {
            ptr->succ=cel;
            cel->pred=ptr;
            cel->succ=NULL;
        }

        //Insertion au milieu
        else {
            cel->succ=ptr->succ;
            cel->pred=ptr;
            if(ptr->succ != NULL) //( pour vérifier qu'il n'y a pas une segmentation fault (affection à NULL )
                (ptr->succ)->pred=cel;

            ptr->succ=cel;
        }
    }
}

void SupprimerCellule(int pl, cellule **liste) {

    if(pl<0 || *liste == NULL) {
        printf("Erreur : il n'y a rien a supprimer !");
        return;
    }

    cellule *ptr = *liste;
    int i=0;

    //Suppression en tete
    if(pl==0) {
        *liste=ptr->succ;
        if((*liste)!=NULL)
            (*liste)->pred=NULL;
        free(ptr);
    }
    else {
        while(i<pl && ptr!=NULL) {
            ptr=ptr->succ;
            i++;
        }
        if(ptr==NULL) {
            printf("Erreur : Taille liste depassee ! ");
        }
        else {
            if(ptr->pred != NULL) {
                ptr->pred->succ = ptr->succ;
            }
            if(ptr->succ != NULL) {
                ptr->succ->pred = ptr->pred;
            }
            free(ptr);
        }
    }
}

//Fonction affichage de la liste des points
void afficher(cellule *liste) {
    if(liste==NULL)
        printf("Liste vide !");
    else {
        cellule *ptr=liste;

        while(ptr!=NULL) {
            printf("(%d,%d)\n", ptr->p.x,ptr->p.y);
            ptr=ptr->succ;
        }
    }
}