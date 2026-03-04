#include<stdio.h>
#include<stdlib.h>
#include <string.h>
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

//charger un graphe à partir de la saisie clavier
graph *chargerGraph(){
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

    return g;
}

char** chargerCles(const char *nomFichier){
    FILE *f = fopen(nomFichier, "r");
    if (!f) {
        printf("Erreur ouverture fichier\n");
        exit(1);
    }

    //Lecture de la première ligne : les cles
    char ligne[1000];
    fgets(ligne, sizeof(ligne), f);

    //Compter les noms
    int count = 0;
    char *token = strtok(ligne, " \n");
    char **cles = NULL;

    while(token != NULL) {
        cles = realloc(cles, (count + 1) * sizeof(char*));
        cles[count] = malloc(strlen(token) + 1);
        strcpy(cles[count], token);
        count++;
        token = strtok(NULL, " \n");
    }
    return cles;
}

//charger un graphe à partir d'un fichier
graph *chargerGraphFich(const char *nomFichier, char ***cles){
    int n;
    graph *g;
    *cles = chargerCles(nomFichier);
    
    FILE *f = NULL;
    if(nomFichier != NULL)
    {
        f = fopen(nomFichier, "r");

        // Si le fichier n'existe pas
        if(!f){
            printf("Fichier introuvable !\n");
        }
        else{
            char ligne[1000];
            //Lire et ignorer la première ligne (les clés)
            fgets(ligne, sizeof(ligne), f);

            //Lire le nombre de sommets
            fscanf(f, "%d", &n);
            g = creerGraph(n);
        
            //Remplissage de la matrice
            for (int i = 0; i < (g->nbSommets); i++){
                for(int j = 0; j< (g->nbSommets); j++)
                    fscanf(f, "%d", &(g->adjacence[i][j]));
            }

            fclose(f);
        }
    }
    return g;
}



//ajouter une arete entre deux sommets donnés
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
void welshPowell(graph *g, char **cles){

    sommet *degresTries = trierDegre(g);

    int couleur[g->nbSommets];

    for(int i=0; i<(g->nbSommets); i++){
        couleur[i]=-1;
    }

    int couleur_courante =0;
    couleur[degresTries[0].num]=couleur_courante;
    printf("\nOrdre de marquage :\n1er  sommet colore: %s\tCouleur: %d\n", cles[degresTries[0].num], couleur_courante); //ordre de marquage
    fflush(stdout);
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
        printf("%deme sommet colore: %s\tCouleur: %d\n",(i+1), cles[sommet], couleur_courante); //ordre de marquage
        fflush(stdout);
    }

    printf("\nLe graphe a ete colore avec <%d> couleurs\n", (couleur_courante+1));
    fflush(stdout);
    for(int i=0; i<(g->nbSommets); i++){
        printf("Sommet: %-12s Couleur: %d\n", cles[i], couleur[i]);
        fflush(stdout);
    }
}

//liberer l'espace alloué aux clés
void libererCles(char **cles, int n) {
    for (int i = 0; i < n; i++) {
        free(cles[i]);
    }
    free(cles);
}

//liberer l'espace alloué pour le graphe 
void libererGraph(graph *g){
    for(int i=0; i<(g->nbSommets); i++){
        free(g->adjacence[i]);
    }

    free(g->adjacence);
    free(g);
}