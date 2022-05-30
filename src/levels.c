
#include "test.h"

Cell createNewCell(int value, int color){

    Cell newCell;

    newCell.value = value;
    newCell.color = color;
    // newCell.path = path;
    // newCell.hover = false;
    newCell.selected = false; // IDEE DE GUIGUI (DON'T FORGET TO DO)
    newCell.correct = false;

    return newCell;

}

int** randomArray(){

    int array[3][3] = {{0, 1, 2},
                       {1, 1, -1},
                       {1, 1, -1}};

    return array;
}

int valueToColor(int value){

    int color = (value - (value % 10)) / 10;
    return color;

}

int valueToNum(int value){

    int num = value % 10;
    return num;

}

void baseArray(int level, int** arr){

    switch(level){

        case 1:
            arr = {{0, 1, 2},
                  {1, 1, -1},
                  {1, 1, -1}};
            break;

        case 2:
            int array2[3][3] = {{2, 2, 3},
                                  {1, 0, 3},
                                  {1, 1, -1}};
            break;
        
        case 3:
            int array3[4][4] = {{2, 2, 1, 0},
                               {2, 2, 2, 12},
                               {3, 5, 11, 11},
                               {4, 4, 11, 10}};
            break;

        case 4:
            int array4[4][4] = {{1, 1, 11, 11},
                               {2, 0, 10, 12},
                               {2, 2, 12, 12},
                               {3, 3, 13, 13}};
            break;

        default:
            arr = randomArray();
    }

}

Cell** level(int level){

    int** base = malloc (11 * sizeof(int*));
    for (int i = 0; i < 11; i++){
        base[i] = malloc(11 * sizeof(int));
    }

    baseLevel(level, &base);

    int widthSize = sizeof(base[0]) / sizeof(int);
    int heightSize = sizeof(base) / widthSize;
    

    Cell** lvl = malloc(heightSize * widthSize * sizeof(Cell));
    for (int i = 0; i < heightSize; i++){
        lvl[i] = malloc(widthSize * sizeof(Cell));
    }

    for (int y = 0; y < heightSize; y++){
        for (int x = 0; x < widthSize; x++){
            lvl[y][x] = createNewCell(valueToNum(base[y][x]), valueToColor(base[y][x]));
        }
    }

    return lvl;
}

char* getText(int valueCode){

    char str[2];
    sprintf(str, "%d", valueCode);

    return *str;
}

Color getColor(int colorCode){

    switch(colorCode){
        case 0:
            return RED;
        case 1:
            return GREEN;
        case 2:
            return BLUE;
    }

}

bool conditions(int* curr, int* next){

    // Will check if the 
    return true;

}

void checkWin(int color){

    // Will check if every cell of X color is selected, if yes turn Correct into True

}