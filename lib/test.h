
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

#pragma region GLOBAL VARIABLES

#define screenMultiplier 1.2

#define screenWidth (550 * screenMultiplier) // DO NOT CHANGE OR NOT CENTERED
#define screenHeight (550 * screenMultiplier) // DO NOT CHANGE OR NOT CENTERED
#define realScreenWidth (screenWidth +(margin*2) )
#define realScreenHeight (screenHeight +(margin*2) )

#define levelWidth (floor((11 - width) / 2))
#define levelHeight (floor((11 - height) / 2))

#define sqrSide (50 * screenMultiplier) // DO NOT CHANGE OR NOT CENTERED
#define margin (100 * screenMultiplier)

#define MAXLEVEL 6

#pragma endregion

#pragma region Game & Menu Handling

void menu(int* level, int* windowState);
void game(int* level, int* windowState);
void nextMenu(int* windowState);

#pragma endregion

#pragma region Cells & Level handling

Cell createNewCell(int value, int color);
Color getColor(int colorCode);

void setLevel(Cell arr[11][11], int level);
void getLevelSize(int level, int* width, int* height);

#pragma endregion

#pragma region Mouse & Click

void plusButton(int* level);
void minusButton(int* level);
void playButton(int* level, int* menuState);
void hoverOn(int* x, int* y);
bool isHover(int x, int y);
void hoverClick(Cell arr[11][11], int x, int y, int width, int height, int* prevX, int* prevY, int* gameState);

#pragma endregion

#pragma region Check & conditions

bool conditions(Cell arr[11][11], int currX, int currY, int nextX, int nextY);
void checkWinColor(Cell arr[11][11], int color, int width, int height);
void checkWin(Cell arr[11][11], int width, int height, int* gameState);

#pragma endregion

#pragma region Drawing 

void drawLevel(Cell arr[11][11], int width, int height, int* prevX, int* prevY, int* gameState);
void drawRect(int x, int y, Color color);
void drawMenu(int* level, int* menuState);

#pragma endregion

