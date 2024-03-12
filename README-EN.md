# Simple Network Scanner

![Static Badge](https://img.shields.io/badge/Télécom-Projet_scolaire-purple)
![Static Badge](https://img.shields.io/badge/Langage-C-blue)
![Static Badge](https://img.shields.io/badge/Langage-Makefile-green)
[![Static Badge](https://img.shields.io/badge/Référence-Nmap-purple)](https://nmap.org/docs.html)

**Note**: This readme is also available in [french](https://github.com/cos-imo/SimpleNetworkScanner/blob/main/README.md) version

## Summary
1. Summary
2. Presentation
3. Installation
4. Repository's layout and additionnal information

## Présentation
This project was developed during my scholaship in [TELECOM Nancy](https://telecomnancy.univ-lorraine.fr) (2nd year - 2nd semester) 
Subject's exercpt:

> Using the [...] TCP server-client model, code in C a simple network scanner that can be remotely configured using a manager  

The current application, inspired by [Nmap](https://nmap.org/docs.html) is a C executable.

**Group Members** :
- OUAKRIM Yannis
- UNGARO Cosimo

## Installation

## Installation
##### Download
###### Using SSH
```
git clone git@github.com:cos-imo/SimpleNetworkScanner.git
```
###### Using HTTP
```
git clone https://github.com/cos-imo/SimpleNetworkScanner.git
```

##### Building
From the project's root (folder `src`), simply use `make`:
```
make
```


##### Launching
From the project's root (folder `src`), run the main_output executable in `build`:
```
./build/main_output [OPTIONS]
```

## Repository's layout and additionnal information
