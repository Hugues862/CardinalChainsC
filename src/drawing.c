#include "test.h"


void drawRect(int x, int y, int side, int margin, Color color){

    DrawRectangle(margin + (side * x), margin + (side * y), side, side, color);

}

void drawLevel(Cell arr[11][11], int x, int y, int sqrSide, int margin, Color selectColor, int width, int height){

    Color sqrColor;
    
    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int y = floor((11 - height) / 2); y < floor((11 - height) / 2) + height; y++){
        for (int x = floor((11 - width) / 2); x < floor((11 - width) / 2) + width; x++){

            if (arr[y][x].value == -1){
                sqrColor = WHITE;
            }
            else if (arr[y][x].correct == false){
                sqrColor = getColor(arr[y][x].color);
            }
            else{
                sqrColor = YELLOW;
            }

            drawRect(x, y, sqrSide, margin, sqrColor);

            if (arr[y][x].value != -1){
                char str[2];
                sprintf(str, "%d", arr[y][x].value);
                DrawText(str, margin + (sqrSide * x) + 15, margin + (sqrSide * y) + 15, 14.5, BLACK);
            }

        }
    }

    hoverClick(arr, x, y, width, height, sqrSide, margin, selectColor);

    EndDrawing();

}