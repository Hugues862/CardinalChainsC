#include "test.h"


void drawRect(int x, int y, Color color){

    DrawRectangle(margin + (sqrSide * x), margin + (sqrSide * y), sqrSide, sqrSide, color);

}

void drawLevel(Cell arr[11][11], int width, int height, int* prevX, int* prevY){

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

            drawRect(x, y, sqrColor);

            if (arr[y][x].value != -1){
                char str[2];
                sprintf(str, "%d", arr[y][x].value);
                DrawText(str, margin + (sqrSide * x) + 15, margin + (sqrSide * y) + 15, 14.5, BLACK);
            }

        }
    }

    int hoverX, hoverY;
    hoverOn(&hoverX, &hoverY);

    // if (arr[hoverY][hoverX].value == 0 && !arr[hoverX][hoverY].correct){
        
    //     DrawText("haha", 15, 15, 14.5, BLACK);

    // }

    // if (IsMouseButtonPressed(0)){
    //     DrawText("lmao", 15, 15, 14.5, BLACK);
    // }


    hoverClick(arr, hoverX, hoverY, width, height, prevX, prevY);

    EndDrawing();

}