# Documentation (VSCODE CLICK DROIT > Apercu / Preview)

## Documentation Technique

> Dans l'optique de rester dans le thème du developpement en C, nous avons pris la décision de faire la documentation technique en tant que commentaire / docstring pour chaque fonction.

## Comment parcourir la documentation

> Pour la parcourir on recommande l'installation de l'extension [Better Comments](https://marketplace.visualstudio.com/items?itemName=aaron-bond.better-comments) dans VSCODE.

> Pour voir la structure globale, on peut aller dans le fichier [test.h](lib/test.h) ou l'ont peux voir tout les commentaire ou les docstring en survolant / cmd+click sur la fonction.

## Windows :

Au préalable installer raylib.

-   Se diriger vers [Raylib](https://www.raylib.com) et télécharger la librairie
    Le site vous demandera une donation mais vous pouvez refuser et télécharger l'installer gratuitement
    Vous pouvez cliquer [ici](https://raysan5.itch.io/raylib/download/eyJleHBpcmVzIjoxNjU0NTQ5OTAwLCJpZCI6ODUzMzF9.u4NGmWStc2VGEb5hWKLbq4R7ZnA%3d) pour aller directement au téléchagement.

-   Après le téléchargement, lancer l'installer de raylib et installer raylib
-   Vérifier que raylib s'est bien installer ici C:\raylib\

### Pour Lancer sur VSCode :

-   Vérifier qu'un fichier nommé main autre que main.c et main.exe ne se trouve pas dans le workspace
-   Appuyer sur F5 lorsque main.c est ouvert

## MACOS :

Avant toutes choses merci d'installer Raylib

> `brew install raylib`

Ensuite on peux soit essayer cmd+F5 qui devrait executer de manière automatique, ou le faire avec le terminal avec les commandes suivantes.

> `make osx`

> `./main`
