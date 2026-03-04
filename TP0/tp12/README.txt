README.txt
==========

Programme : Arbre binaire

Description :
Ce programme implémente la structure et les opérations de base sur un arbre binaire.
Chaque noeud contient :
- un caractère (val),
- un numéro unique (num),
- un pointeur vers son fils gauche,
- un pointeur vers son fils droit.

Fonctionnalités :
- Création d'un noeud avec un caractère et attribution automatique d'un numéro.
- Insertion d'un noeud comme fils gauche ou fils droit d'un noeud existant.
- Recherche d'un noeud par son numéro.
- Parcours préfixe (racine → gauche → droite).
- Gestion d'un tableau des numéros pour vérifier l'existence des noeuds.

Fichiers :
- operations.h : définition de la structure `noeud` et des prototypes.
- operations.c : implémentation des fonctions (création, insertion, recherche, parcours, utilitaires).
- mainArbre.c : programme principal qui permet de créer un arbre et de tester les fonctions.

Compilation :
Utiliser gcc :
    gcc mainArbre.c operations.c -o mainArbre.exe

Exécution :
    ./mainArbre

Utilisation :
1. Le programme demande le caractère de la racine.
2. Ensuite, l'utilisateur peut insérer des noeuds :
   - saisir le caractère du nouveau noeud,
   - indiquer le numéro du père (doit exister),
   - choisir gauche ou droite.
3. Le programme affiche le parcours préfixe de l'arbre construit.
4. L'utilisateur peut rechercher un noeud par son numéro et voir son caractère.

Exemple :
-----------------------------------------------
Creation d'un arbre :
Caractere de la racine ? A

Insersion de noeuds :
Caractere du nouveau noeud a inserer ? B
Numero de son pere ? 1
Inserer A gauche OU A droite ? (1:GAUCHE | 2:DROITE) : 1

Caractere du nouveau noeud a inserer ? C
Numero de son pere ? 1
Inserer A gauche OU A droite ? (1:GAUCHE | 2:DROITE) : 2

Parcours prefixe de l'arbre :
A   B   C

Recherche d'un noeud :
Quel est le numero du noeud que vous recherchez ? 2
< B >
-----------------------------------------------

Auteur :
Melissa YAHIATENE
