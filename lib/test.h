
#include "raylib.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

// #pragma region Cells & Level handling

Cell createNewCell(int value, int color);

// int valueToColor(int value);
// int valueToNum(int value);
Color getColor(int colorCode);

void setLevel(Cell arr[11][11], int level);
// void randomArray(int arr[11][11]);
// void baseArray(int level, int arr[11][11]); // work in progress do not touch
// void getBase(int level, int base[11][11], int* width, int* height);
// void genLevel(Cell** arr, int base[11][11], int width, int height);
bool conditions(Cell** arr, int currX, int currY, int nextX, int nextY);
void checkWin(Cell** arr, int color, int width, int height);

// #pragma endregion

// #pragma region Mouse

void hoverOn(int* x, int* y, int size, int margin);
bool isHover(int x, int y, int size, int margin);

// #pragma endregion

// #pragma region Drawing Handling

void drawLevel(Cell arr[11][11]);
void drawRect(int x, int y, int side, int margin, Color color);

// #pragma endregion

void game(int level);