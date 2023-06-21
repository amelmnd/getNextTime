<h1 align="center">
Get Next Line
</h1> 
<p align="center">
<img src="https://badge42.vercel.app/api/v2/clj4c286d001608ky7gpcs9h7/project/3078564" />
<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
</p>
<p align="center">
<img src="https://img.shields.io/badge/bonus-ok-5CB95B" />
<img src="https://img.shields.io/badge/42_Nice-000" />
</p>



- [Description](#description)
- [Structure du projet](#structure-du-projet)
  * [Fichiers .c](#fichiers-c)
  * [.h (En-tête)](#h--en-t-te-)
- [La fonction](#les-fonctions)
- [Utilisation de get next line](#utilisation-de-get next line)
  * [Pre-requis](#pre-requis)
  * [Utilisation](#utilisation)
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

### Compilation 
```shell
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
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
