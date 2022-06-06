
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

        #pragma region Level 1
        case 1:
            arr[5][5] = createNewCell(1, 0);
            arr[5][4] = createNewCell(1, 0);
            arr[6][4] = createNewCell(1, 0);
            arr[6][5] = createNewCell(1, 0);
            arr[4][5] = createNewCell(1, 0);
            arr[4][4] = createNewCell(0, 0);
            arr[4][6] = createNewCell(2, 0);
            break;
        #pragma endregion

        #pragma region Level 2
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
        #pragma endregion

        #pragma region Level 3
        case 3:
            arr[5][4] = createNewCell(0, 0);
            arr[6][4] = createNewCell(1, 0);
            arr[6][5] = createNewCell(2, 0);
            arr[6][6] = createNewCell(3, 0);

            arr[5][6] = createNewCell(0, 1);
            arr[4][6] = createNewCell(1, 1);
            arr[4][5] = createNewCell(2, 1);
            arr[4][4] = createNewCell(3, 1);
            break;
        #pragma endregion

        #pragma region Level 4
        case 4:
            arr[3][3] = createNewCell(0, 0);
            arr[3][4] = createNewCell(1, 0);
            arr[3][5] = createNewCell(1, 0);
            arr[3][6] = createNewCell(2, 0);
            arr[3][7] = createNewCell(2, 0);

            arr[4][3] = createNewCell(0, 1);
            arr[4][4] = createNewCell(1, 1);
            arr[4][5] = createNewCell(1, 1);
            arr[4][6] = createNewCell(2, 1);
            arr[4][7] = createNewCell(2, 1);

            arr[5][3] = createNewCell(0, 2);
            arr[5][4] = createNewCell(1, 2);
            arr[5][5] = createNewCell(1, 2);
            arr[5][6] = createNewCell(2, 2);
            arr[5][7] = createNewCell(2, 2);

            arr[6][3] = createNewCell(0, 3);
            arr[6][4] = createNewCell(1, 3);
            arr[6][5] = createNewCell(1, 3);
            arr[6][6] = createNewCell(2, 3);
            arr[6][7] = createNewCell(2, 3);

            arr[7][3] = createNewCell(0, 4);
            arr[7][4] = createNewCell(1, 4);
            arr[7][5] = createNewCell(1, 4);
            arr[7][6] = createNewCell(2, 4);
            arr[7][7] = createNewCell(2, 4);

            break;
        #pragma endregion

        #pragma region Level 5
        case 5:

            arr[3][3] = createNewCell(0, 0);
            arr[3][4] = createNewCell(1, 0);
            arr[3][5] = createNewCell(1, 0);
            arr[3][6] = createNewCell(1, 0);
            arr[3][7] = createNewCell(1, 0);
            arr[4][6] = createNewCell(2, 0);
            arr[4][7] = createNewCell(2, 0);

            arr[4][5] = createNewCell(0, 1);
            arr[4][4] = createNewCell(3, 1);
            arr[4][3] = createNewCell(4, 1);
            arr[5][3] = createNewCell(2, 1);
            arr[5][4] = createNewCell(3, 1);
            arr[5][5] = createNewCell(1, 1);
            arr[6][5] = createNewCell(1, 1);
            arr[6][4] = createNewCell(1, 1);
            arr[6][3] = createNewCell(1, 1);

            arr[5][7] = createNewCell(0, 2);
            arr[5][6] = createNewCell(1, 2);
            arr[6][6] = createNewCell(1, 2);
            arr[6][7] = createNewCell(1, 2);
            arr[7][7] = createNewCell(2, 2);
            arr[7][6] = createNewCell(2, 2);
            arr[7][5] = createNewCell(3, 2);
            arr[7][4] = createNewCell(4, 2);
            arr[7][3] = createNewCell(4, 2);
            break;

        #pragma endregion

        #pragma region Level 6
        case 6:
            arr[2][4] = createNewCell(0, 0);
            arr[2][5] = createNewCell(1, 0);
            arr[2][6] = createNewCell(1, 0);

            arr[3][3] = createNewCell(1, 3);
            arr[3][4] = createNewCell(1, 0);
            arr[3][5] = createNewCell(1, 0);
            arr[3][6] = createNewCell(1, 0);
            arr[3][7] = createNewCell(1, 0);
            
            arr[4][3] = createNewCell(1, 3);
            arr[4][4] = createNewCell(0, 5);
            arr[4][5] = createNewCell(1, 5);
            arr[4][6] = createNewCell(1, 5);
            arr[4][7] = createNewCell(1, 0);

            arr[5][3] = createNewCell(1, 3);
            arr[5][4] = createNewCell(0, 3);
            arr[5][5] = createNewCell(3, 0);
            arr[5][6] = createNewCell(2, 0);
            arr[5][7] = createNewCell(2, 0);

            arr[6][3] = createNewCell(3, 0);
            arr[6][4] = createNewCell(3, 0);
            arr[6][5] = createNewCell(3, 0);
            arr[6][6] = createNewCell(2, 0);
            arr[6][7] = createNewCell(2, 0);

            arr[7][3] = createNewCell(3, 0);
            arr[7][4] = createNewCell(3, 0);
            arr[7][6] = createNewCell(2, 0);
            arr[7][7] = createNewCell(2, 0);
            break;
        #pragma endregion
           
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

        case 3:
            *width = 3;
            *height = 3;

        case 4:
            *width = 5;
            *height = 5;

        case 5:
            *width = 5;
            *height = 5;

        case 6:
            *width = 5;
            *height = 6;
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
        case 3:
            return MAROON;
        case 4:
            return ORANGE;
        case 5:
            return GRAY;
    }

    return RAYWHITE;
}
