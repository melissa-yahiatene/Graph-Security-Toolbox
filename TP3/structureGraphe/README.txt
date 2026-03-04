README.txt
==========

Programme : Graphe avec listes de voisins en C

Description :
Ce programme implémente une structure de graphe en langage C en utilisant une liste de voisins pour chaque sommet. Chaque sommet est identifié par :
- un caractère (val),
- un numéro unique (num),
- une liste chaînée de ses voisins.

Fonctionnalités :
- Création d'un sommet avec un caractère et attribution automatique d'un numéro.
- Création d'un graphe avec un nombre de sommets donné.
- Ajout d'une arête entre deux sommets (mise à jour des listes de voisins).
- Affichage du graphe (liste des voisins de chaque sommet).
- Libération de la mémoire allouée.

Structures :
- `voisin` : représente un voisin d'un sommet (numéro + pointeur vers le suivant).
- `sommet` : représente un sommet (valeur + numéro + liste de voisins).
- `graph`  : représente le graphe (nombre de sommets + liste des sommets).

Fichiers :
- operations.h  : définitions des structures et prototypes des fonctions.
- operations.c  : implémentation des fonctions (création de sommet, création de graphe, ajout d'arêtes).
- graph.c       : programme principal pour tester la création et l'affichage du graphe.

Compilation :
Utiliser gcc :
    gcc graph.c operations.c -o graph.exe

Exécution :
    ./graph.exe

Utilisation :
Dans le programme principal :
1. Création du graphe avec `creerGraph(n)`.
2. Création explicite des sommets avec `nouvSommet('X')` et affectation dans `g->sommets[i]`.
3. Ajout des arêtes avec `ajouterArete(g, s1, s2)`.
4. Affichage du graphe avec `afficherGraph(g)`.
5. Libération de la mémoire avec `libererGraph(g)`.

Exemple d'utilisation :
-----------------------------------------------
Affichage du graphe :
Sommet A (1) : 
Sommet B (2) : D (3) C (2)
Sommet C (3) : D (3) B (1) 
Sommet D (4) : l (4) C (2) B (1)
-----------------------------------------------

Auteur :
Melissa YAHIATENE
