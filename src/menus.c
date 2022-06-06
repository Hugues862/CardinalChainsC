#include "test.h"

void menu(int* level, int* windowState) {

    int menuState = 0;

    while(menuState == 0){

        drawMenu(level, &menuState);

    }

    if (menuState == 1) {
        *windowState = 1;
    }

}

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
        
    }

    if (gameState == 1){

        if (*level == MAXLEVEL){
            *windowState = 0;
        }

        *level = (*level + 1) % MAXLEVEL + 1;
    }

}