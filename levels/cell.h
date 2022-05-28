#include <stdbool.h>
#include "raylib.h"

typedef struct gameCell
{
    // int position[2];
    int value; // Value of the cell (Number appearing on it)
    int color; // Value of the color (0 -> Red, 1 -> Blue, ect)
    int path; // Value of path (0 -> start, 1 -> nextCorrect)
    bool selected; // Change color when true
    
} Cell;

#pragma region Cells & Level handling

Cell createNewCell(int value, int color, int path);
int*** randomArray();
int*** baseArray(short level);
Cell** level(short level);
Color getColor(int colorCode);

#pragma endregion

void drawLevel(Cell** arr);

#pragma region Drawing Handling