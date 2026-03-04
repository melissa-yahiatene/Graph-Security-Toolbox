README.txt
==========

Programme : Arbre binaire 

Description :
Ce programme implémente une structure d'arbre binaire en langage C.
Chaque noeud contient :
- un caractère (val),
- un numéro unique (num),
- un pointeur vers son fils gauche,
- un pointeur vers son fils droit.

Fonctionnalités :
- Création d'un noeud avec un caractère et attribution automatique d'un numéro.
- Insertion d'un noeud comme fils gauche ou fils droit d'un noeud existant.
- Recherche d'un noeud par son numéro.
- Trois parcours de l'arbre :
  - Parcours préfixe (racine → gauche → droite),
  - Parcours infixe (gauche → racine → droite),
  - Parcours suffixe (gauche → droite → racine).
- Fonctions utilitaires pour gérer les numéros des noeuds.

Fichiers :
- operations.h  : définition de la structure `noeud` et des prototypes.
- operations.c  : implémentation des fonctions (création, insertion, recherche, parcours, utilitaires).
- mainArbre.c   : programme principal qui crée un arbre et affiche les différents parcours.

Compilation :
Utiliser gcc :
    gcc mainArbre.c operations.c -o mainArbre.exe

Exécution :
    ./mainArbre

Utilisation :
Le programme crée automatiquement un arbre avec les noeuds suivants :
- Racine : 'B'
- Fils gauche : 'A'
- Fils droit : 'O'
- Autres noeuds insérés : 'R', 'V'

Ensuite, il affiche :
- Le parcours préfixe,
- Le parcours infixe,
- Le parcours suffixe.

Exemple de sortie :
-----------------------------------------------
Parcours prefixe de l'arbre :
B   R   A   O   V

===============================================
Parcours infixe de l'arbre :
R   B   A   O   V

===============================================
Parcours suffixe de l'arbre :
R   A   V   O   B
-----------------------------------------------

Auteur :
Melissa YAHIATENE
