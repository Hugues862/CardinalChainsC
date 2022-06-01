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
// #include "test.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// /* All .c files and functions in test.h

typedef struct gameCell
{
    // int position[2];
    int value; // Value of the cell (Number appearing on it)
    int color; // Value of the color (0 -> Red, 1 -> Blue, ect)
    // int path; // Value of path (0 -> start, 1 -> nextCorrect)
    // bool hover;
    bool selected; // Change color when true
    bool correct;
    
} Cell;

Cell createNewCell(int value, int color){

    Cell newCell;

    newCell.value = value;
    newCell.color = color;
    // newCell.path = path;
    // newCell.hover = false;
    newCell.selected = false; // IDEE DE GUIGUI (DON'T FORGET TO DO)
    newCell.correct = false;

    return newCell;

}

void randomArray(int*** arr){

    int newArr[11][11] = {{0, 1, 2, -1, -1, -1, -1, -1, -1, -1, -1},
                                {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3}};
            
    for(int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            *arr[i][j] = newArr[i][j];
        }
    }
           
}

int valueToColor(int value){

    int color = (value - (value % 10)) / 10;
    return color;

}

int valueToNum(int value){

    int num = value % 10;
    return num;

}

void baseArray(int level, int*** arr){

    switch(level){

        case 1:
            int newArr1[11][11] = {
                {0, 1, 2, -1, -1, -1, -1, -1, -1, -1, -1},
                {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3}
                };
            
            for(int i = 0; i < 11; i++){
                for (int j = 0; j < 11; j++){
                    *arr[i][j] = newArr1[i][j];
                }
            }
            // memcpy(arr, newArr1, sizeof(newArr1));
            break;

        case 2:
            int newArr2[11][11] = {
                {2, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1},
                {1, 0, 3, -1, -1, -1, -1, -1, -1, -1, -1},
                {1, 1, 3, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3}
                };

            for(int i = 0; i < 11; i++){
                for (int j = 0; j < 11; j++){
                    *arr[i][j] = newArr2[i][j];
                }
            }
            // memcpy(arr, newArr2, sizeof(newArr2));
            break;


        default:
            randomArray(arr);
    }

}

void genLevel(int level, Cell*** arr, int* width, int* height){

    int** base;

    base = (int**)malloc(11 * sizeof(int*));

    for (int i = 0; i < 11; i++) {
        base[i] = (int*)malloc(11 * sizeof(int));
    }

    baseArray(level, &base);

    *width = base[11][0];
    *height = base[11][11];
    
    *arr = (Cell**)malloc(*height * sizeof(Cell*));
    
    for (int i = 0; i < *height; i++){
        *arr[i] = (Cell*)malloc(*width * sizeof(Cell));
    }

    for (int y = 0; y < *height; y++){
        for (int x = 0; x < *width; x++){
            *arr[y][x] = createNewCell(valueToNum(base[y][x]), valueToColor(base[y][x]));
        }
    }

    for (int i = 0; i < 11; i++) {
        free(base[i]);
    }
    free(base);

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

    return WHITE;
}

bool conditions(int currX, int currY, int nextX, int nextY){

    // Will check if the 
    return true;

}

void checkWin(int color){

    // Will check if every cell of X color is selected, if yes turn Correct into True

}


void hoverOn(int* x, int* y, int size, int margin){

    int posX, posY;

    posX = ((GetMouseX() - margin) - ((GetMouseX() - margin) % size)) / size;
    posY = ((GetMouseY() - margin) - ((GetMouseY() - margin) % size)) / size;

    *x = posX;
    *y = posY;
}

bool isHover(int x, int y, int size, int margin){

    int posX = 0, posY = 0;
    hoverOn(&posX, &posY, size, margin);

    return posX == x && posY == y;

}


void drawRect(int x, int y, int side, int margin, Color color){

    DrawRectangle(margin + (side * x), margin + (side * y), side, side, color);

}

void drawLevel(Cell** arr, int sizeWidth, int sizeHeight){

    int sqrSide = 50;
    
    int margin = 100; // Problem with hover (negative values)
    
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

            drawRect(x, y, sqrSide, margin, sqrColor);
            // (originX, originY, lenX, lenY, Color)

            if ((arr[y][x].value == 0 && isHover(x, y, sqrSide, margin)) || (!arr[y][x].correct)) { // Can only click & hover on first cell
                drawRect(x, y, sqrSide, margin, selectColor);
                
                int prevX = x, prevY = y;

                while(IsMouseButtonDown(1)){ // Click & Hold to select

                    int posX = 0, posY = 0;
                    hoverOn(&posX, &posY, sqrSide, margin);

                    if (conditions(prevX, prevY, posX, posY)){
                        arr[posY][posX].selected = true;
                        drawRect(posX, posY, sqrSide, margin, selectColor);
                        
                        prevX = posX;
                        prevY = posY;
                    }
                }

                if (IsMouseButtonReleased(1)){

                    checkWin(arr[y][x].color);

                }
            }

            char str[2];
            sprintf(str, "%d", arr[y][x].value);
            DrawText(str, margin + (sqrSide * x) + 15, margin + (sqrSide * y) + 15, 14.5, BLACK);

        }
    }

    EndDrawing();

}
// */

int main() 
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 1000;

    Cell** arr = NULL;
    
    int arrWidth = 0, arrHeight = 0;
    genLevel(1, &arr, &arrWidth, &arrHeight);

    InitWindow(screenWidth, screenHeight, "raylib");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Draw
        //----------------------------------------------------------------------------------
        
        drawLevel(arr, arrWidth, arrHeight);
        
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    for (int i = 0; i < arrHeight; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}