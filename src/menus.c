#include "test.h"

/**
 * @brief Fonction menu qui affiche le menu,
 * menuState = 0 -> menu,
 * menuState = 1 -> début du jeu,
 * menuState = 2 -> quitter
 * 
 * @param level 
 * @param windowState 
 */
void menu(int* level, int* windowState) {

    int menuState = 0;

    while(menuState == 0){ // * Draws the Menu 

        drawMenu(level, &menuState);
        escQuit(&menuState, 2);

    }

    if (menuState == 1) *windowState = 1; // * Start Game

    if (menuState == 2) *windowState = 2; // * Quit Window

}
/**
 * @brief Fonction générale qui va calculé les tailles des cellules, Affiche les cellules, vérifie si la touche ESC est enfoncé et vérifie si le jeu est terminé.
 * 
 * @param level 
 * @param windowState 
 */
void game(int* level, int* windowState){
    int baseWidth, baseHeight;
    getLevelSize(*level, &baseWidth, &baseHeight);

    int gameState = 0;
    Cell arr[11][11];
    int prevX = -1, prevY = -1;

    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            arr[i][j] = createNewCell(-1, -1);
        }
    }

    setLevel(arr, *level);
    
    while(gameState == 0){
        
        drawLevel(arr, baseWidth, baseHeight, &prevX, &prevY, &gameState);
        escQuit(&gameState, 2);
        
    }

    if (gameState == 1){

        if (*level == MAXLEVEL) *windowState = 0;
        
        *level = (*level + 1) % MAXLEVEL;
    }

    if (gameState == 2) *windowState = 2;

}