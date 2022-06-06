#include "test.h"


void drawRect(int x, int y, Color color){

    DrawRectangle(margin + (sqrSide * x), margin + (sqrSide * y), sqrSide, sqrSide, color);

}

void drawMenu(int* level, int* menuState){
    

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("CardinalChains", (realScreenWidth*0.5)-(MeasureText("CardinalChains", 60)/2), 40, 60, BLACK);

        DrawText("Choose your level", (realScreenWidth*0.5)-(MeasureText("Choose your level", 30)/2), 150, 30, BLACK);


    //Left button
    DrawRectangle(
        realScreenWidth*0.5-200-realScreenWidth*0.15, 
        realScreenHeight*0.6, 
        realScreenWidth*0.15, 
        realScreenHeight*0.1, 
        BLACK);
    DrawText("-", 
        (realScreenWidth*0.5-200-realScreenWidth*0.15)+(realScreenWidth*0.15/2)-(MeasureText("-", 60)/2),
        (realScreenHeight*0.6)+(realScreenHeight*0.1/3)-(MeasureText("-", 60)/2),
        60, RAYWHITE);

    //Right button
    DrawRectangle(
        realScreenWidth*0.5+200, 
        realScreenHeight*0.6, 
        realScreenWidth*0.15, 
        realScreenHeight*0.1, 
        BLACK);
    DrawText("+", 
        (realScreenWidth*0.5+200)+(realScreenWidth*0.15/2)-(MeasureText("+", 60)/2),
        (realScreenHeight*0.6)+(realScreenHeight*0.1/3)-(MeasureText("+", 60)/2),
        60, RAYWHITE);
    
    char selectedLevel[3];
    sprintf(selectedLevel, "%d", *level);
    DrawText(selectedLevel, (realScreenWidth*0.5)-(MeasureText(selectedLevel, 200)/2), realScreenHeight*0.5, 200, BLACK);

    plusButton(level);
    minusButton(level);

    EndDrawing();

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