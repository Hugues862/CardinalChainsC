/*******************************************************************************************
*
*   raylib [core] example - Basic 3d example
*
*   Welcome to raylib!
*
*   To compile example, just press F5.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2020 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>

typedef struct gameCell
{
    // int position[2];
    int value; // Value of the cell (Number appearing on it)
    int color; // Value of the color (0 -> Red, 1 -> Blue, ect)
    // int path; // Value of path (0 -> start, 1 -> nextCorrect)
    bool selected; // Change color when true
    bool correct;
    
} Cell;

Cell createNewCell(int value, int color){

    Cell newCell;

    newCell.value = value;
    newCell.color = color;
    // newCell.path = path;
    newCell.selected = false; // IDEE DE GUIGUI (DON'T FORGET TO DO)
    newCell.correct = false;

    return newCell;

}

int** randomArray(){

    int array[3][3] = {{0, 1, 2},
                       {1, 1, -1},
                       {1, 1, -1}};

    return array;
}

int valueToColor(int value){

    int color = (value - (value % 10)) / 10;
    return color;

}

int valueToNum(int value){

    int num = value % 10;
    return num;

}

void baseArray(int level, int** &arr){

    switch(level){

        case 1:
            arr = {{0, 1, 2},
                                {1, 1, -1},
                                {1, 1, -1}};
            break;

        case 2:
            int array2[3][3] = {{2, 2, 3},
                                  {1, 0, 3},
                                  {1, 1, -1}};
            break;
        
        case 3:
            int array3[4][4] = {{2, 2, 1, 0},
                               {2, 2, 2, 12},
                               {3, 5, 11, 11},
                               {4, 4, 11, 10}};
            break;

        case 4:
            int array4[4][4] = {{1, 1, 11, 11},
                               {2, 0, 10, 12},
                               {2, 2, 12, 12},
                               {3, 3, 13, 13}};
            break;

        default:
            arr = randomArray();
    }

}

Cell** level(int level){

    int** base = malloc (11 * sizeof(int*));
    for (int i = 0; i < 11; i++){
        base[i] = malloc(11 * sizeof(int));
    }

    baseLevel(level, &base);

    int widthSize = sizeof(base[0]) / sizeof(int);
    int heightSize = sizeof(base) / widthSize;
    

    Cell** lvl = malloc(heightSize * widthSize * sizeof(Cell));
    for (int i = 0; i < heightSize; i++){
        lvl[i] = malloc(widthSize * sizeof(Cell));
    }

    for (int y = 0; y < heightSize; y++){
        for (int x = 0; x < widthSize; x++){
            lvl[y][x] = createNewCell(valueToNum(base[y][x]), valueToColor(base[y][x]));
        }
    }

    return lvl;
}

char* getText(int valueCode){

    char str[2];
    sprintf(str, "%d", valueCode);

    return *str;
}

Color getColor(int colorCode){

    switch(colorCode){
        case 0:
            return RED;
        case 1:
            return GREEN;
        case 2:
            return BLUE;
    }

}

void drawLevel(Cell** arr){

    int sqrWidth = 50, sqrHeight = 50;
    int sizeWidth = sizeof(arr[0]) / sizeof(Cell);
    int sizeHeight = sizeof(arr) / sizeWidth;
    
    Color selectColor = {150, 255, 30, 0.5};
    Color sqrColor;
    
    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int y = 0; y < sizeHeight; y++){
        for (int x = 0; x < sizeWidth; x++){

            if (!arr[y][x].correct){
                sqrColor = getColor(arr[y][x].color);
            }
            else{
                sqrColor = YELLOW;
            }

            DrawRectangle(100 + (sqrWidth * x), 100 + (sqrHeight * y), sqrWidth, sqrHeight, sqrColor);

            if (arr[y][x].selected){
                DrawRectangle(100 + (sqrWidth * x), 100 + (sqrHeight * y), sqrWidth, sqrHeight, selectColor);
            }

            // (originX, originY, lenX, lenY, Color)
            DrawText(getText(arr[y][x].value), 100 + (sqrWidth * x) + 15, 100 + (sqrHeight * y) + 15, 14.5, BLACK);

        }
    }

    EndDrawing();

}


int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    Cell** arr = level(1);

    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Draw
        //----------------------------------------------------------------------------------
        
        drawLevel(arr);
        
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}