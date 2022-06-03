
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

#define screenWidth 550 * 1.5
#define screenHeight 550 * 1.5
#define sqrSide 50 * 1.5 //
#define margin 0 * 1.5 //

// #pragma region Cells & Level handling

Cell createNewCell(int value, int color);

// int valueToColor(int value);
// int valueToNum(int value);
Color getColor(int colorCode);

void setLevel(Cell arr[11][11], int level);
void getLevelSize(int level, int* width, int* height);
// void randomArray(int arr[11][11]);
// void baseArray(int level, int arr[11][11]); // work in progress do not touch
// void getBase(int level, int base[11][11], int* width, int* height);
// void genLevel(Cell** arr, int base[11][11], int width, int height);
void checkWin(Cell** arr, int color, int width, int height);

// #pragma endregion

// #pragma region Mouse

void hoverOn(int* x, int* y);
bool isHover(int x, int y);
void hoverClick(Cell* arr[11][11], int x, int y, int width, int height, int* prevX, int* prevY);
bool conditions(Cell arr[11][11], int currX, int currY, int nextX, int nextY);

// #pragma endregion

// #pragma region Drawing Handling

void drawLevel(Cell arr[11][11], int width, int height, int* prevX, int* prevY);
void drawRect(int x, int y, Color color);

// #pragma endregion

void game(int level);