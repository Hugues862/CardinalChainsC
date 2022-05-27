#include <stdbool.h>

typedef struct gameCell
{
    // int position[2];
    int value; // Value of the cell (Number appearing on it)
    int color; // Value of the color (0 -> Red, 1 -> Blue, ect)
    int path; // Value of path (0 -> start, 1 -> nextCorrect)
    bool selected; // Change color when true
    
} Cell;

/* Cell** createArray(short** size){

    Cell** arr;
    

} */