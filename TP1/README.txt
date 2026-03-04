README.txt
==========

Programme : Coloration de Graphe (Algorithme de Welsh-Powell)

Description :
Ce programme implémente en langage C l'algorithme de Welsh-Powell pour colorer les sommets d'un graphe. L'objectif est d'attribuer des couleurs aux sommets
de manière à ce que deux sommets adjacents n'aient jamais la même couleur, tout en minimisant le nombre total de couleurs utilisées.

Fonctionnalités :
- Création d'un graphe avec un nombre de sommets donné.
- Ajout interactif d'arêtes entre sommets.
- Calcul du degré de chaque sommet.
- Tri des sommets par degré décroissant.
- Coloration du graphe avec l'algorithme de Welsh-Powell.
- Affichage du nombre de couleurs utilisées et de la couleur attribuée à chaque sommet.
- Libération de la mémoire allouée.

Fichiers :
- coloration.h : définitions des structures et prototypes des fonctions.
- coloration.c : implémentation des fonctions (création, ajout d'arêtes, calcul des degrés, tri, coloration, libération).
- mainGraph.c  : programme principal qui permet de créer un graphe interactif et de lancer la coloration.

Compilation :
Utiliser gcc :
    gcc mainGraph.c coloration.c -o mainGraph.exe

Exécution :
    ./mainGraph.exe

Utilisation :
1. Le programme demande le nombre de sommets du graphe.
2. L'utilisateur ajoute les arêtes en saisissant les indices des sommets à relier.
   - Les indices doivent être compris entre 0 et n-1.
   - L'utilisateur peut ajouter autant d'arêtes qu'il le souhaite.
3. Le programme applique l'algorithme de Welsh-Powell et affiche :
   - le nombre de couleurs utilisées,
   - la couleur attribuée à chaque sommet.

Exemple :
-----------------------------------------------
Nombre de sommets du graphe ? : 5
Ajouter les aretes :
Les sommets a relier avec une arete ? (s1 s2) : 0 1
Voulez-vous ajouter une autre arete ? (1:OUI | 2:NON) : 1
Les sommets a relier avec une arete ? (s1 s2) : 1 2
Voulez-vous ajouter une autre arete ? (1:OUI | 2:NON) : 2

================================================
Coloration du graphe:
Le graphe a ete colore avec <3> couleurs
Sommet 0: Couleur: 0
Sommet 1: Couleur: 1
Sommet 2: Couleur: 2
Sommet 3: Couleur: 0
Sommet 4: Couleur: 1
-----------------------------------------------

Auteur :
Melissa YAHIATENE
