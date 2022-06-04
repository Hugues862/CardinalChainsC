#include "test.h"

void game(int* level, int* windowState){

    int baseWidth, baseHeight;
    getLevelSize(*level, &baseWidth, &baseHeight);

    bool gameState = true;
    Cell arr[11][11];
    int prevX = -1, prevY = -1;

    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            arr[i][j] = createNewCell(-1, -1);
        }
    }

    setLevel(arr, *level);
    
    while(gameState == true){
        
        drawLevel(arr, baseWidth, baseHeight, &prevX, &prevY, &gameState);
        
    }

    *level = *level + 1;

}