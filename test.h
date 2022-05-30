#include <stdbool.h>
#include "raylib.h"

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

int valueToColor(int value);
int valueToNum(int value);
char* getText(int valueCode);
Color getColor(int colorCode);

int** randomArray();
void baseArray(int level, int** arr); // work in progress do not touch
Cell** level(int level);
bool condition(int* curr, int* next);
void checkWin(int color);


// #pragma endregion


// #pragma region Drawing Handling

void drawLevel(Cell** arr);
void drawRect(int x, int y, int side, int margin, Color color);

// #pragma endregion