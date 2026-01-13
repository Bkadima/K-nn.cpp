
***Nearest Neighbors (k-NN) From Scratch in C++***

 Présentation du Projet
Ce projet consiste en une réimplémentation complète de l'algorithme des k-plus proches voisins (k-NN) en C++ pur. Dans une démarche d'apprentissage autodidacte orientée vers le Machine Learning et la programmation système, j'ai choisi de ne dépendre d'aucune bibliothèque externe.
L'objectif est de démontrer ma capacité à traduire des concepts mathématiques théoriques en code informatique performant et optimisé.
 **Objectifs Pédagogiques**
 
• Compréhension algorithmique : Maîtriser la logique interne du k-NN (normalisation, calcul de distances, vote majoritaire).

• Gestion de la mémoire : Utilisation de pointeurs et de structures de données dynamiques (listes chaînées) pour une gestion fine des ressources.

• Abstraction mathématique : Codage manuel de fonctions fondamentales (méthode de Newton pour la racine carrée, calculs de distances vectorielles).

• Modularité : Structuration du code en plusieurs fichiers (.h, .cpp) pour respecter les bonnes pratiques de développement logiciel.

**Points Forts de l'Implémentation**

• Multi-métriques de distance : Support des distances Euclidienne, Manhattan et Cosinus, permettant d'adapter le modèle à différents types de jeux de données.

• Normalisation Min-Max : Intégration d'un module de mise à l'échelle automatique des données pour éviter les biais de dimensionnalité.

• Zéro dépendance : Réimplémentation des outils mathématiques (racine carrée, valeurs absolues) pour une indépendance totale.

• Nettoyage mémoire rigoureux : Gestion systématique de la libération de la mémoire pour prévenir les fuites (Memory Leaks) dans les structures dynamiques.

**Structure du Projet**

• math.cpp / math.h : Bibliothèque mathématique interne (Newton, distances).

• knn.cpp / knn.h : Cœur de l'algorithme (classification, normalisation, tri des voisins).

• main.cpp : Orchestrateur gérant la saisie utilisateur et le cycle de vie du programme.

 **Vision de Professionnalisation**
 
Ce travail s'inscrit dans un cursus personnel de réimplémentation des standards du Machine Learning. Après avoir réalisé une régression linéaire en 1D et nD, ce module k-NN consolide mes bases en développement C++ et en mathématiques appliquées. Mon but est de comprendre non seulement comment utiliser les outils de l'IA, mais surtout pourquoi ils fonctionnent, afin de pouvoir optimiser des systèmes complexes à l'avenir.
