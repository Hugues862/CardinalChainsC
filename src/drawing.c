#include "test.h"


void drawRect(int x, int y, Color color){

    DrawRectangle(margin + (sqrSide * x), margin + (sqrSide * y), sqrSide, sqrSide, color);

}

void drawMenu(int* level, int* menuState){


    
}

void drawLevel(Cell arr[11][11], int width, int height, int* prevX, int* prevY, int* gameState){

    Color sqrColor;
    
    BeginDrawing();

    ClearBackground(RAYWHITE);
    
    // time_t t;
    // srand((unsigned) time(&t) + rand());

    for (int y = levelHeight; y < levelHeight + height; y++){
        for (int x = levelWidth; x < levelWidth + width; x++){

            if (arr[y][x].value == -1){
                // sqrColor = (Color)getColor((int)rand() % 3);
                sqrColor = RAYWHITE;
            }
            else if (arr[y][x].correct == true){
                sqrColor = YELLOW;
            }
            else if (arr[y][x].selected == true){
                sqrColor = BLUE;
            }
            else{
                sqrColor = getColor(arr[y][x].color);
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

    hoverClick(arr, hoverX, hoverY, width, height, prevX, prevY, gameState);

    EndDrawing();

}

void drawNextScreen(int* menuState){



}