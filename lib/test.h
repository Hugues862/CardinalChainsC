
// ! Attention pour la documentation technique, il est 
// ! recommandé d'utiliser l'extension Better Comments
// ? L'extension :
// Id: aaron-bond.better-comments
// Description: Improve your code commenting by annotating with alert, informational, TODOs, and more!
// Version: 3.0.0
// Publisher: Aaron Bond
// VS Marketplace Link: https://marketplace.visualstudio.com/items?itemName=aaron-bond.better-comments


#include "raylib.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// * Game Cell Structure Definition
typedef struct gameCell

{
    int value; // Valeur de la cellule
    int color; // Valeur de la couleur (0 -> Red, 1 -> Blue, ect)
    bool selected; // 
    bool correct;
    
} Cell;

// ? ----------------------------------------
// ? ---------- VARIABLES GLOBALES -----------
// ? ----------------------------------------
#pragma region 

// ! VALEUR AFIN DE SCALE LA FENÊTRE
#define screenMultiplier 1.2 // 

// ! POUR CELLULES ET FENÊTRE MODULABLE ET CENTRÉE
#define screenWidth (550 * screenMultiplier) 
#define screenHeight (550 * screenMultiplier) 
#define realScreenWidth (screenWidth +(margin*2) )
#define realScreenHeight (screenHeight +(margin*2) )

#define sqrSide (50 * screenMultiplier)
#define margin (100 * screenMultiplier)

#define levelWidth (floor((11 - width) / 2))
#define levelHeight (floor((11 - height) / 2))
// ! ----

// ! NOMBRE DE NIVEAUX 
#define NumberOfLevel 6 // Incrémenter en cas d'ajout de niveaux
#define MAXLEVEL (NumberOfLevel - 1) // ? DO NOT TOUCH
// ! ----

#pragma endregion ------------------------------------------------

// ? ----------------------------------------
// ? --------- Game & Menu Handling ---------
// ? ----------------------------------------
#pragma region 

void menu(int* level, int* windowState);
void game(int* level, int* windowState);

#pragma endregion

// ? ----------------------------------------
// ? -------- Cells & Level handling --------
// ? ----------------------------------------
#pragma region 

Cell createNewCell(int value, int color);
Color getColor(int colorCode);

void setLevel(Cell arr[11][11], int level);
void getLevelSize(int level, int* width, int* height);

#pragma endregion ------------------------------------------------

// ? ----------------------------------------
// ? -------- Mouse & Click -----------------
// ? ----------------------------------------
#pragma region 

void escQuit(int* windowState, int newValue);
void plusButton(int* level);
void minusButton(int* level);
void playButton(int* menuState);
void hoverOn(int* x, int* y);
void hoverClick(Cell arr[11][11], int x, int y, int width, int height, int* prevX, int* prevY, int* gameState);

#pragma endregion ------------------------------------------------


// ? ----------------------------------------
// ? -------- Check & conditions ------------
// ? ----------------------------------------
#pragma region 

bool conditions(Cell arr[11][11], int currX, int currY, int nextX, int nextY);
void checkWinColor(Cell arr[11][11], int color, int width, int height);
void checkWin(Cell arr[11][11], int width, int height, int* gameState);

#pragma endregion ------------------------------------------------


// ? ----------------------------------------
// ? ------------- Drawing ------------------
// ? ----------------------------------------
#pragma region

void drawLevel(Cell arr[11][11], int width, int height, int* prevX, int* prevY, int* gameState);
void drawRect(int x, int y, Color color);
void drawMenu(int* level, int* menuState);

#pragma endregion ------------------------------------------------

