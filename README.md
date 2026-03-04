# 🛡️ Graph-Security-Toolbox : Algorithmique Bas Niveau & Analyse de Graphes

Bienvenue dans la **Graph-Security-Toolbox**. Ce dépôt regroupe une suite d'outils développés en **Langage C**, illustrant une progression vers la maîtrise des structures de données dynamiques et l'optimisation algorithmique.

---

## 🛠️ Expertise Technique & Évolution des TPs

Ce projet démontre une capacité à gérer manuellement la mémoire et à concevoir des architectures logicielles robustes, compétences fondamentales pour l'analyse de vulnérabilités et la sécurité système.

### 🔹 TP0 & TP2 : Arbres Binaires & Structures Dynamiques
Initialement focalisé sur la création simple, le module a évolué vers un outil d'analyse complet.
* **Structures** : Implémentation de listes doublement chaînées et d'arbres binaires.
* **Évolution (V2)** : Passage d'une création manuelle à une automatisation des tests.
* **Algorithmes** : Intégration des trois types de parcours fondamentaux :
    * **Préfixe** (Analyse de structure)
    * **Infixe** (Tri et lecture logique)
    * **Suffixe** (Libération mémoire et calcul de dépendances)
* **Focus Cyber** : Gestion rigoureuse des pointeurs pour éviter les fuites mémoire (Memory Leaks).



### 🔹 TP1 & TP2 : Coloration de Graphes (Welsh-Powell)
Ce module traite de la théorie des graphes appliquée à l'optimisation de ressources.
* **Welsh-Powell** : Algorithme de coloration gloutonne basé sur le tri décroissant des degrés des sommets.
* **Évolution Majeure (V2)** : 
    * **Persistance** : Chargement automatique de topologies complexes via fichiers externes (`Carte.txt`).
    * **Abstraction** : Gestion de noms réels (clés) via des pointeurs triples (`char ***`), permettant de passer de sommets abstraits à des entités identifiables (ex: pays, routeurs).
    * **Traçabilité** : Affichage de l'ordre de marquage pour l'audit algorithmique.



---

## 🔒 Applications en Cybersécurité

Pourquoi ces outils sont-ils pertinents pour un profil Cyber ?

1. **Analyse de Topologie Réseau** : La coloration de graphe est utilisée pour l'**allocation de fréquences sans interférence** et la segmentation de réseaux (VLANs) pour limiter la propagation de malwares.
2. **Parsing & Analyse de Protocoles** : Les parcours d'arbres (Infixe/Suffixe) sont à la base de l'analyse syntaxique des fichiers malveillants ou du décodage de protocoles réseau propriétaires.
3. **Sécurisation du Code (Secure Coding)** : 
    * Validation des entrées lors de la lecture du fichier `Carte.txt`.
    * Utilisation de `calloc` et vérification systématique des retours de `malloc` pour prévenir les **Denial of Service (DoS)** par crash mémoire.



---

## 🚀 Installation & Utilisation

### Prérequis
* Compilateur GCC
* Environnement Linux, macOS ou MinGW pour Windows.

### Compilation
Pour compiler le module de coloration :
```bash
gcc mainGraph.c coloration.c -o GraphColoring
```

### Exécution
Le programme chargera automatiquement le fichier de topologie Carte.txt :
```bash
./GraphColoring
```
---

> Détails dans le README de chaque TP.
