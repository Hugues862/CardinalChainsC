
#include "test.h"

/**
 * @brief Arrête une boucle while et permet à la fenêtre de se fermée
 * 
 * @param windowState Condition pour la boucle while
 * @param change Nouvelle valeur de windowState pour arrêter la boucle 
 */
void escQuit(int* windowState, int newValue){

    if (WindowShouldClose()) *windowState = newValue;

}
// ? ---------------------------------
// ? ------------ Menu ---------------
// ? ---------------------------------
#pragma region

/**
 * @brief Incrémente la valeur de level lors du click sur +
 * 
 * @param level Adresse de la variable level
 */
void plusButton(int* level){
    int mouseX, mouseY;
    mouseX = GetMouseX();
    mouseY = GetMouseY();

    // ? Si la souris est sur le Bouton +
    if (mouseX>realScreenWidth*0.5+200 && mouseX<realScreenWidth*0.5+200+realScreenWidth*0.15 && mouseY>realScreenHeight*0.6 && mouseY<realScreenHeight*0.6+realScreenHeight*0.1){
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){

            if (*level < MAXLEVEL) *level = *level + 1; 
            
            else *level = 0; 
        }
    }
}

/**
 * @brief Désincrémente la valeur de level lors du click sur -
 * 
 * @param level Adresse de la variable level
 */
void minusButton(int* level){
    
    int mouseX, mouseY;
    mouseX = GetMouseX();
    mouseY = GetMouseY();

    // ? Si la souris est sur le Bouton -
    if (mouseX>realScreenWidth*0.5-200-realScreenWidth*0.15 && mouseX<realScreenWidth*0.5-200 && mouseY>realScreenHeight*0.6 && mouseY<realScreenHeight*0.6+realScreenHeight*0.1){
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){

            if (*level > 1) *level = *level - 1;

            else *level = MAXLEVEL; 
        }
    }
}

/**
 * @brief Change l'état de la fenêtre du mode Menu au mode Jeu
 * 
 * @param menuState Adresse de l'état de la fenêtre
 */
void playButton(int* menuState){
    int mouseX, mouseY;
    mouseX = GetMouseX();
    mouseY = GetMouseY();

    if (mouseX>realScreenWidth*0.5-100 && mouseX<realScreenWidth*0.5-100+200 && mouseY>realScreenHeight*0.8 && mouseY<realScreenHeight*0.8+100){
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) *menuState = 1;
        
    }
}

#pragma endregion

// ? ------------------------------------------
// ? -------- Game Hover & Conditions ---------
// ? ------------------------------------------
#pragma region

/**
 * @brief Récupère la valeur X, Y de la souris dans l'array de cellules
 * 
 * @param x Adresse de x pour assigner la valeur de X dans l'array
 * @param y Adresse de y pour assigner la valeur de Y dans l'array
 */
void hoverOn(int* x, int* y){

    int posX, posY;

    posX = floor((GetMouseX() - margin) / sqrSide);
    posY = floor((GetMouseY() - margin) / sqrSide);

    *x = posX;
    *y = posY;
}

/**
 * @brief Permet de sélectionner les cellules ou de confirmer la sélection de cellules
 * 
 * @param arr Matrice contenant toute les cellules
 * @param x Position X de la souris dans la matrice
 * @param y Position Y de la souris dans la matrice
 * @param width Largeur du Niveau
 * @param height Hauteur du Niveau
 * @param prevX Position X de la dernière cellule sélectionner
 * @param prevY Position Y de la dernière cellule sélectionner
 * @param gameState Adresse de l'état du Jeu
 */
void hoverClick(Cell arr[11][11], int x, int y, int width, int height, int* prevX, int* prevY, int* gameState){

    /* // ? DEBUG -------
    char xPos[20], yPos[20], selectState[25];
    sprintf(xPos, "Value of x : %d", x);
    sprintf(yPos, "Value of y : %d", y);
    sprintf(selectState, "Value of select : %d", (int)arr[y][x].selected);
    DrawText(xPos, 15 + 15, 15 * 3, 14.5, BLACK);
    DrawText(yPos, 15 + 15, 15 * 4, 14.5, BLACK);
    DrawText(selectState, 15 + 15, 15 * 5, 14.5, BLACK);
    */ // ? -----

    DrawText("LMB : Use to Select", 15, 25 * 2, 20, BLACK);
    DrawText("RMB : Use to Confirm", 15, 25 * 3, 20, BLACK);
    
    // ? Permet le CLICK GAUCHE seulement sur les cellules voisines, non sélectionnées,
    // ? non correctes, de même couleur et de valeurs égale ou +1
    if (conditions(arr, *prevX, *prevY, x, y) && arr[y][x].correct == false && IsMouseButtonPressed(0)) {
        
        arr[y][x].selected = true;

        // * Update la dernière cellule sélectionnée
        *prevX = x;
        *prevY = y;

    }
    
    // ? CLICK DROIT
    if (IsMouseButtonDown(1)){

        // * Vérifie les conditions de Win par couleur puis globale
        checkWinColor(arr, arr[*prevY][*prevX].color, width, height);
        checkWin(arr, width, height, gameState);

        // * Remet la cellule précédente à zéro
        *prevX = -1;
        *prevY = -1;

    }   
}

/**
 * @brief Vérifié si les cellules adjacentes sont de meme couleurs ou de meme valeur
 * 
 * @param arr 
 * @param currX 
 * @param currY 
 * @param nextX 
 * @param nextY 
 * @return true 
 * @return false 
 */
bool conditions(Cell arr[11][11], int currX, int currY, int nextX, int nextY) {

    // * SI la cellule précédente n'existe pas, et que la cellule cliqué est égale à 0
    if (currX == -1 && currY == -1 && arr[nextY][nextX].value == 0) { return true; }

    // * Sinon Si la cellule cliqué est adjacente à la cellule précédente
    else if ((abs(currX - nextX) == 1 && currY == nextY) || (abs(currY - nextY) == 1 && currX == nextX)){

        // * Même couleur et non sélectionnée
        if (arr[currY][currX].color == arr[nextY][nextX].color && arr[nextY][nextX].selected == false){

            // * Même valeur ou +1
            if (arr[currY][currX].value == arr[nextY][nextX].value || arr[currY][currX].value + 1 == arr[nextY][nextX].value){
                return true;
            }
        }
    }

    // DrawText("TEST FAILED", 15 + 15, 15 + 15, 14.5, BLACK); // ? DEBUG

    return false;
}

/**
 * @brief Vérifie toutes les cellules de la meme couleur et vérifie si elle sont toutes sélectionnées, et les valides.
 * 
 * @param arr 
 * @param color 
 * @param width 
 * @param height 
 */
void checkWinColor(Cell arr[11][11], int color, int width, int height){

    // Will check if every cell of X color is selected, if yes turn Correct into True

    bool change = true;

    for (int y = levelHeight; y < levelHeight + height; y++){
        for (int x = levelWidth; x < levelWidth + width; x++){

            if (arr[y][x].color == color){
                if (arr[y][x].selected == false) change = false;
            
                arr[y][x].selected = false;

            }
        }
    }

    if (change == true){
        for (int y = levelHeight; y < levelHeight + height; y++){
            for (int x = levelWidth; x < levelWidth + width; x++){

                if (arr[y][x].color == color) arr[y][x].correct = true;
                
            }
        }
    }
}

/**
 * @brief Vérifie si toutes les cellules sont sélectionnées et validée, si oui, le jeu est gagné
 * 
 * @param arr 
 * @param width 
 * @param height 
 * @param gameState 
 */
void checkWin(Cell arr[11][11], int width, int height, int* gameState){

    bool win = true;

    for (int y = levelHeight; y < levelHeight + height; y++){
        for (int x = levelWidth; x < levelWidth + width; x++){

            if (arr[y][x].correct == false && arr[y][x].value != -1) win = false;
            
            if (win == false) break;
            
        }
    }

    if (win == true) *gameState = 1;
    
}

#pragma endregion