#include<stdio.h>
#include<stdlib.h>
#include "operations.h"

#define NB 40 

int main(){
    char carac;
    int rep1, rep2, num;
    noeud *racine;
    noeud *n;

    int tabNum[NB];

    printf("\n===============================================\n");
    printf("Creation d'un arbre :\n");
    fflush(stdout);

    printf("Caractere de la racine ? ");
    fflush(stdout);
    scanf("%c", &carac);
    fflush(stdin);

    racine = nouvNoeud(carac);
    ajoutNumero(NB, tabNum, racine->num); //sauvegarde des numeros des noeuds créés

    printf("\nInsersion de noeuds : \n");
    fflush(stdout);

    do{
        printf("Caractere du nouveau noeud a inserer ? ");
        fflush(stdout);
        scanf("%c", &carac);
        fflush(stdin);

        //repeter la demande de saisie du numero du pere du noeud à inserer tant que le numero est faux (aucun noeud ne possède ce numero)
        do{
            printf("Numero de son pere ? (inserer un numero d'un noeud existant !) : ");
            fflush(stdout);
            scanf("%d", &num);
            fflush(stdin);
        }while(existeNum(NB, tabNum, num)==0);
        
        do{
            printf("Inserer A gauche OU A droite ? (1:GAUCHE  |  2:DROITE) : ");
            fflush(stdout);
            scanf("%d", &rep2);
            
            n = nouvNoeud(carac); //creation du noeud 

            if(rep2==1){ //inserer à gauche
                insererFG(n, racine, num);
                ajoutNumero(NB, tabNum, n->num);
            }
            else if(rep2==2){ //inserer à droite
                insererFD(n, racine, num);
                ajoutNumero(NB, tabNum, n->num);
            }

        }while(rep2!=1 && rep2!=2);


        printf("\nVoulez-vous inserer un autre noeud ? ( 1:OUI | 2:NON) : ");
        fflush(stdout);
        scanf("%d", &rep1);
        fflush(stdin);

    }while(rep1==1);

    printf("\n===============================================\n");
    //parcours prefixe de l'arbre créé : 
    printf("Parcours prefixe de l'arbre :\n");
    parcoursPrefixe(racine);

    //rechercher un noeud avec son numero
    printf("\n===============================================\n");
    printf("recherche d'un noeuds :\nQuel est le numero du noeud que vous recherchez ? ");
    fflush(stdout);
    scanf("%d", &num);
    fflush(stdin);
    if(existeNum(NB, tabNum, num)==0){
        printf("Aucun noeud correspondant au numero saisi !\n");
        fflush(stdout);
    }
    else{
        n = rechercheNoeud(racine, num);
        printf("< %c >", n->val);
    }

    free(racine);
    free(n);

    return(EXIT_SUCCESS);
}