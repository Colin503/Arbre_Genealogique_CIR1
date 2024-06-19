# Arbre Généalogique

## Description

Ce projet implémente un programme en C qui réalise l'arbre généalogique d'une personne. Le programme à executer est contenu dans le fichier `main.c`.

## Prérequis

Avant de pouvoir exécuter le programme, assurez-vous d'avoir les outils suivants installés sur votre machine :

- Un compilateur C (comme GCC)
- Un terminal ou une ligne de commande

## Bibliothèques requises

Le programme utilise les bibliothèques standard suivantes en C :

- `stdlib.h` : Pour la gestion de la mémoire et les conversions.
- `stdio.h` : Pour les opérations d'entrée et de sortie.
- `string.h` : Pour la manipulation de chaînes de caractères.
- `math.h` : Pour les fonctions mathématiques (si nécessaire).

Assurez-vous que ces bibliothèques sont disponibles dans votre environnement de développement.

## Fichiers requis

Les fichiers nécessaires pour exécuter ce programme sont :

- `main.c` : Le fichier source principal contenant le programme.
- `style.css` : La feuille de style pour le fichier HTML généré.
- un ficher csv avec une liste de personne : id,idpere,idmere,nom,prenom,date de naissance,ville contenue dans le dossier resources
- `person.h`
- `person.c`
- `population.h`
- `population.c`
- `filemanager.c`
- `filemanager.h`
- `advanced.h`
- `advanced.c`
- `htmlexport.h`
- `htmlexport.c`
- `menu.c`
- `menu.h`

## Installation

Suivez ces étapes pour configurer et exécuter le programme :

1. **Cloner le dépôt** (si nécessaire) :
   ```sh
   git clone <URL_du_dépôt>
   cd <nom_du_dépôt>
   ```

2. **Compiler le programme** :
   Dans le terminal, naviguez jusqu'au répertoire contenant `main.c` et compilez-le en utilisant la commande suivante :
   ```sh
   gcc main.c -o arbre_genealogique
   ```
   Sur C-Lion, déplacer tous les fichiers dans un projet en respectant l'arborescence ci-dessus.
3. **Exécuter le programme** :
   Une fois la compilation terminée, exécutez le programme en utilisant la commande suivante :
   - **Sur Linux et macOS** :
     ```sh
     ./arbre_genealogique
     ```
   - **Sur Windows** :
     ```sh
     arbre_genealogique.exe
     ```

## Utilisation

Après avoir lancé le programme, un menu avec 4 options s'affiche. Vous pouvez choisir parmi les options suivantes :

1. **Obtenir la fratrie d'une personne**
2. **Obtenir l'arbre généalogique d'une personne**
3. **Obtenir l'ancêtre le plus lointain d'une personne**

Pour utiliser n'importe laquelle de ces options, vous devez entrer l'ID d'une personne.

Le résultat sera affiché dans la console et également écrit dans un fichier HTML. Pour que le fichier HTML soit correctement stylisé, le fichier `style.css` est requis.

## Auteurs

- [Colin](https://github.com/Colin503)
- [Manech](https://github.com/Mvnech)

## Répertoire

- [Arbre_Genealogique_CIR1]([https://github.com/Colin503](https://github.com/Colin503/Arbre_Genealogique_CIR1))
