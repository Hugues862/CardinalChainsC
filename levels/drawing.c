#include "cell.h"

void drawLevel(Cell** arr){

    int sqrWidth = 50, sqrHeight = 50;
    int sizeHeight = sizeof(arr) / sizeof(arr[0]);
    int sizeWidth = sizeof(arr[0]) / sizeof(Cell);
    
    BeginDrawing();
    ClearBackground(RAYWHITE);

    for (int y = 0; y < sizeHeight; y++){
        for (int x = 0; x < sizeWidth; x++){

            DrawRectangle(100 + (sqrWidth * x), 100 + (sqrHeight * y), sqrWidth * x, sqrHeight * y, getColor(arr[y][x].color));

        }
    }

    EndDrawing();

}