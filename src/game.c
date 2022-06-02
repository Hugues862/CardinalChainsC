#include "test.h"

void game(int level){

    const int sqrSide = 50;
    const int margin = 0;
    const Color selectColor = {150, 255, 30, 0.5};

    int levelWidth, levelHeight;
    getLevelSize(level, &levelWidth, &levelHeight);

    bool gameState = true;
    Cell arr[11][11];

    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            arr[i][j] = createNewCell(-1, -1);
        }
    }

    int x, y;

    setLevel(arr, level);
    while(game){
        
        hoverOn(&x, &y, sqrSide, margin);
        drawLevel(arr, x, y, sqrSide, margin, selectColor, levelWidth, levelHeight);
        

    }


}