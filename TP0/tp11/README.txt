README.txt
==========

Programme : Représentation des formes polygonales par des liste doublement chainées

Description :
Ce programme implémente une liste doublement chaînée en langage C.
Chaque cellule contient un point (x, y) et des pointeurs vers la cellule précédente et suivante. Le programme permet :
- d'insérer une cellule à une position donnée,
- de supprimer une cellule à une position donnée,
- d'afficher la liste des points représentant la forme polygonale 

Fichiers :
- liste.h : définition des structures et des prototypes.
- liste.c : implémentation des fonctions (NouvelCel, InsererCellule, SupprimerCellule, afficher).
- main.c  : programme principal qui utilise la liste.

Compilation :
Utiliser gcc :
    gcc maListe.c liste.c -o maListe.exe

Exécution :
    ./maListe.exe

Utilisation :
Au lancement, le programme demande à l'utilisateur :
- d'entrer les coordonnées des points (x, y),
- de choisir l'emplacement d'insertion,
- de décider s'il veut ajouter d'autres points,
- puis d'afficher la liste.
Ensuite, l'utilisateur peut supprimer des cellules
en indiquant leur position.

Exemple :

Insertion des points :
Inserer les coordonnees X et Y du Point(1) dans cet ordre: 1 2
A quel emplacement voulez-vous inserer cette cellule ? 1 

Voulez vous inserer un autre point ? O: NON | 1: OUI 1
Inserer les coordonnees X et Y du Point(2) dans cet ordre: 3 4
A quel emplacement voulez-vous inserer cette cellule ? 2

Voulez vous inserer un autre point ? O: NON | 1: OUI 1
Inserer les coordonnees X et Y du Point(3) dans cet ordre: 5 6
A quel emplacement voulez-vous inserer cette cellule ? 3

Voulez vous inserer un autre point ? O: NON | 1: OUI 1
Inserer les coordonnees X et Y du Point(4) dans cet ordre: 7 8
A quel emplacement voulez-vous inserer cette cellule ? 4

Voulez vous inserer un autre point ? O: NON | 1: OUI 0
(1,2)
(3,4)
(5,6)
(7,8)

Quel est l'emplacement de la cellule que vous souhaitez supprimer ? 4

Voulez vous supprimer un autre point ? O: NON | 1: OUI 1

Quel est l'emplacement de la cellule que vous souhaitez supprimer ? 1

Voulez vous supprimer un autre point ? O: NON | 1: OUI 0
(3,4)
(5,6)

Auteur :
Melissa YAHIATENE
