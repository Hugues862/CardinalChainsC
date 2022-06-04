
#include "test.h"

Cell createNewCell(int value, int color){

    Cell newCell;

    newCell.value = value;
    newCell.color = color;
    // newCell.path = path;
    // newCell.hover = false;
    newCell.selected = false;
    newCell.correct = false;

    return newCell;

}

void setLevel(Cell arr[11][11], int level){

    switch(level){

        case 1:
            arr[5][5] = createNewCell(1, 0);
            arr[5][4] = createNewCell(1, 0);
            arr[6][4] = createNewCell(1, 0);
            arr[6][5] = createNewCell(1, 0);
            arr[4][5] = createNewCell(1, 0);
            arr[4][4] = createNewCell(0, 0);
            arr[4][6] = createNewCell(2, 0);
            break;

        case 2:
            arr[5][5] = createNewCell(0, 0);
            arr[5][4] = createNewCell(1, 0);
            arr[6][4] = createNewCell(1, 0);
            arr[6][5] = createNewCell(1, 0);
            arr[6][6] = createNewCell(3, 0);
            arr[5][6] = createNewCell(3, 0);
            arr[4][6] = createNewCell(3, 0);
            arr[4][5] = createNewCell(2, 0);
            arr[4][4] = createNewCell(2, 0);
            break;
    }

}

void getLevelSize(int level, int* width, int* height){

    switch(level){

        case 1:
            *width = 3;
            *height = 3;
            break;
        
        case 2:
            *width = 3;
            *height = 3;
            break;

    }

}

Color getColor(int colorCode){

    switch(colorCode){
        case 0:
            return RED;
        case 1:
            return GREEN;
        case 2:
            return PURPLE;
    }

    return RAYWHITE;
}
