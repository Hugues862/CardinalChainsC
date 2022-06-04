
#include "raylib.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

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

#pragma region GLOBAL VARIABLES

#define screenWidth (550 * 1.5)
#define screenHeight (550 * 1.5)

#define levelWidth (floor((11 - width) / 2))
#define levelHeight (floor((11 - height) / 2))

#define sqrSide (50 * 1.5)
#define margin (0 * 1.5)

#pragma endregion

#pragma region Game & Menu Handling

void game(int* level, int* windowState);

#pragma endregion

#pragma region Cells & Level handling

Cell createNewCell(int value, int color);
Color getColor(int colorCode);

void setLevel(Cell arr[11][11], int level);
void getLevelSize(int level, int* width, int* height);

#pragma endregion

#pragma region Mouse & Click

void hoverOn(int* x, int* y);
bool isHover(int x, int y);
void hoverClick(Cell arr[11][11], int x, int y, int width, int height, int* prevX, int* prevY, bool* gameState);

#pragma endregion

#pragma region Check & conditions

bool conditions(Cell arr[11][11], int currX, int currY, int nextX, int nextY);
void checkWinColor(Cell arr[11][11], int color, int width, int height);
void checkWin(Cell arr[11][11], int width, int height, bool* gameState);

#pragma endregion

#pragma region Drawing 

void drawLevel(Cell arr[11][11], int width, int height, int* prevX, int* prevY, bool* gameState);
void drawRect(int x, int y, Color color);

#pragma endregion
