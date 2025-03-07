<h1 align="center">
Get Next Line
</h1> 
<p align="center">
<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
</p>



- [Description](#description)
- [Structure du projet](#structure-du-projet)
  - [Fichiers .c](#fichiers-c)
  - [.h (En-tête)](#h-en-tête)
- [La fonction](#la-fonction)
- [Utilisation de get next line](#utilisation-de-get-next-line)
  - [Pre-requis](#pre-requis)
  - [Compilation et execution](#compilation-et-execution)
  - [Utilisation](#utilisation)
- [Test](#test)


## Description

le but de ce projet est de développer une fonction qui renvoie une ligne
lue depuis un descripteur de fichier.

## Structure du projet
### Fichiers .c

La fonction get next line.

### .h (En-tête)

Inclure `#include "get_next_line.h"` dans tous les fichiers.c afin d’avoir accès aux fonctions incluse partout.

## La fonction
La fonction attent le file descriptor d'un fichier lu dans le main et passer en argument à la compilation.

## Utilisation de get next line

### Pre-requis

* **compilateur `gcc`**

### Compilation et execution
**Compilation**
```shell
cc -Wall -Wextra -Werror -D BUFFER_SIZE=<number> <files>.c
```
_exemple :_
```shell
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

**Exécution**
```shell
./a.out file_test/<chose file>
```

### Utilisation

- utiliser la fonctions get next line dans son projet :  
  incluez le fichier dossier de la fonction 
  puis inclure dand dans le fichier d'en-tête
```C
#include "get_next_line/get_next_line.h"
```


## Test
La francinette
- [ xicodomingues/francinette ](https://github.com/xicodomingues/francinette/)
