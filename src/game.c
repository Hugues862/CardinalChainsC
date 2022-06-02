#include "test.h"

void game(int level){

    bool gameState = true;
    Cell arr[11][11];

    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            arr[i][j] = createNewCell(-1, -1);
        }
    }

    setLevel(arr, level);
    drawLevel(arr);


}