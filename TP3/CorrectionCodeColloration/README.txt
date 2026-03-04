README.txt
==========

Programme : Coloration de Graphe (Algorithme de Welsh-Powell)

Description :
Ce programme implémente en langage C l'algorithme de Welsh-Powell pour colorer les sommets d'un graphe. L'objectif est d'attribuer des couleurs aux sommets
de manière à ce que deux sommets adjacents n'aient jamais la même couleur,
tout en minimisant le nombre total de couleurs utilisées.
(Correction du code ChatGPT)

Fonctionnalités :
- Définition d'une structure Graph avec matrice d'adjacence.
- Ajout d'arêtes entre sommets.
- Calcul du degré de chaque sommet.
- Tri des sommets par degré décroissant.
- Coloration du graphe avec l'algorithme de Welsh-Powell.
- Affichage du nombre de couleurs utilisées et de la couleur attribuée à chaque sommet.

Fichiers :
- fonctions.h        : définitions de la structure `Graph` et des prototypes.
- fonctions.c        : implémentation des fonctions (ajout d'arêtes, Welsh-Powell).
- mainColoration.c   : programme principal qui crée un graphe exemple et lance la coloration.

Compilation :
Utiliser gcc :
    gcc mainColoration.c fonctions.c -o mainColoration.exe

Exécution :
    ./mainColoration.exe

Exemple :
-----------------------------------------------
Graph colored using 3 colors.
Vertex 0: Color 0
Vertex 1: Color 1
Vertex 2: Color 2
Vertex 3: Color 0
Vertex 4: Color 1
-----------------------------------------------

Auteur :
Melissa YAHIATENE
