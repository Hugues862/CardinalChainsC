#include "test.h"

void game(int level){

    int levelWidth, levelHeight;
    getLevelSize(level, &levelWidth, &levelHeight);

    bool gameState = true;
    Cell arr[11][11];
    int prevX = -1, prevY = -1;

    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            arr[i][j] = createNewCell(-1, -1);
        }
    }

    setLevel(arr, level);
    
    while(gameState == true){
        
        drawLevel(arr, levelWidth, levelHeight, &prevX, &prevY);
        
    }

}