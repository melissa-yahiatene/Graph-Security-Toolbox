README.txt
==========

Programme : Coloration de Graphe (Algorithme de Welsh-Powell)

Description :
Ce programme implémente en langage C l'algorithme de Welsh-Powell pour colorer les sommets d'un graphe. L'objectif est d'attribuer des couleurs aux sommets de manière à ce que deux sommets adjacents n'aient jamais la même couleur, tout en minimisant le nombre total de couleurs utilisées.

Fonctionnalités :
- Création d'un graphe avec un nombre de sommets donné.
- Chargement d'un graphe :
  - soit par saisie clavier,
  - soit depuis un fichier texte (exemple : Carte.txt).
- Calcul du degré de chaque sommet.
- Tri des sommets par degré décroissant.
- Coloration du graphe avec l'algorithme de Welsh-Powell.
- Affichage de l'ordre de marquage et des couleurs attribuées.
- Libération de la mémoire allouée (graphe et clés).

Fichiers :
- coloration.h   : définitions des structures et prototypes des fonctions.
- coloration.c   : implémentation des fonctions (création, chargement calcul des degrés, tri, coloration, libération).
- mainGraph.c    : programme principal qui charge un graphe et lance la coloration.
- Carte.txt      : fichier exemple contenant les clés (noms des sommets), le nombre de sommets et la matrice d'adjacence.

Format du fichier Carte.txt :
-----------------------------------------------
FRANCE ESPAGNE PORTUGAL ANDORRE ITALIE AUTRICHE SUISSE ALLEMAGNE LUXEMBOURG BELGIQUE PAYS-BAS 
11
0 1 0 1 1 0 1 1 1 1 0
1 0 1 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0 0
1 1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 0 1 1 0 0 0
1 0 0 0 1 1 0 1 0 0 0
1 0 0 0 0 1 1 0 1 1 1
1 0 0 0 0 0 0 1 0 1 0
1 0 0 0 0 0 0 1 1 0 1
0 0 0 0 0 0 0 1 0 1 0
-----------------------------------------------
- Première ligne : noms des sommets (séparés par des espaces).
- Deuxième ligne : nombre de sommets.
- Les lignes suivantes : matrice d'adjacence (0 = pas d'arête, 1 = arête).

Compilation :
Utiliser gcc :
    gcc mainGraph.c coloration.c -o mainGraph.exe

Exécution :
    ./mainGraph.exe

Exemple de sortie :
-----------------------------------------------
===================================================
Coloration du graphe:

Ordre de marquage :
1er  sommet colore: FRANCE      Couleur: 0
2eme sommet colore: ALLEMAGNE   Couleur: 1
3eme sommet colore: SUISSE      Couleur: 2
4eme sommet colore: BELGIQUE    Couleur: 2
5eme sommet colore: AUTRICHE    Couleur: 2
6eme sommet colore: ITALIE      Couleur: 2
7eme sommet colore: LUXEMBOURG  Couleur: 3
8eme sommet colore: ESPAGNE     Couleur: 3
9eme sommet colore: PAYS-BAS    Couleur: 3
10eme sommet colore: ANDORRE    Couleur: 3
11eme sommet colore: PORTUGAL   Couleur: 3

Le graphe a ete colore avec <4> couleurs
Sommet: FRANCE       Couleur: 0
Sommet: ESPAGNE      Couleur: 1
Sommet: PORTUGAL     Couleur: 0
Sommet: ANDORRE      Couleur: 2
Sommet: ITALIE       Couleur: 1
Sommet: AUTRICHE     Couleur: 0
Sommet: SUISSE       Couleur: 2
Sommet: ALLEMAGNE    Couleur: 1
Sommet: LUXEMBOURG   Couleur: 3
Sommet: BELGIQUE     Couleur: 2
Sommet: PAYS-BAS     Couleur: 0
-----------------------------------------------

Auteur :
Melissa YAHIATENE
