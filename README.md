# Simple Network Scanner

![Static Badge](https://img.shields.io/badge/Télécom-Projet_scolaire-purple)
![Static Badge](https://img.shields.io/badge/Langage-C-blue)
![Static Badge](https://img.shields.io/badge/Langage-Makefile-green)
[![Static Badge](https://img.shields.io/badge/Référence-Nmap-purple)](https://nmap.org/docs.html)

**Note**: This readme is also available in [english](https://github.com/cos-imo/SimpleNetworkScanner/blob/main/README-EN.md) version

## Sommaire
1. Sommaire
2. Présentation
3. Installation
4. Organisation du dépôt et informations complémentaires

## Présentation
Projet développé dans le cadre de ma scolarité à [Télécom Nancy](https://telecomnancy.univ-lorraine.fr) (2ème année - 2ème semestre)  
Extrait du sujet:

> En partant du couple client-serveur TCP, développer un scanner réseau simple configurable à distance via un gestionnaire

La présente application, inspirée de [Nmap](https://nmap.org/docs.html) est constituée d'un executable C.

**Membres du groupe** :
- OUAKRIM Yannis
- UNGARO Cosimo

## Installation

## Installation
##### Téléchargement
###### Par SSH
```
git clone git@github.com:cos-imo/SimpleNetworkScanner.git
```
###### Par HTTP
```
git clone https://github.com/cos-imo/SimpleNetworkScanner.git
```

##### Compilation
Depuis la racine du projet (dossier `src`), lancer make:
```
make
```


##### Lancement
Depuis la racine du projet (dossier `src`) exécuter le programme main_output se trouvant dans build:
```
./build/main_output [OPTIONS]
```

## Organisation du dépôt et informations complémentaires

