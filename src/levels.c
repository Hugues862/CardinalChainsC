
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

void randomArray(int*** arr){

    int newArr1[11][11] = {{0, 1, 2, -1, -1, -1, -1, -1, -1, -1, -1},
                                {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3}};
            
    for(int i = 0; i < 11; i++){
        for (int j = 0; j < 11; j++){
            *arr[i][j] = newArr1[i][j];
        }
    } 
}

int valueToColor(int value){

    int color = (value - (value % 10)) / 10;
    return color;

}

int valueToNum(int value){

    int num = value % 10;
    return num;

}

void baseArray(int level, int*** arr){

    switch(level){

        case 1:
            int newArr1[11][11] = {{0, 1, 2, -1, -1, -1, -1, -1, -1, -1, -1},
                                {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3}};
            
            for(int i = 0; i < 11; i++){
                for (int j = 0; j < 11; j++){
                    *arr[i][j] = newArr1[i][j];
                }
            }
            // memcpy(arr, newArr1, sizeof(newArr1));
            break;

        case 2:
            int newArr2[11][11] = {{2, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1},
                                   {1, 0, 3, -1, -1, -1, -1, -1, -1, -1, -1},
                                   {1, 1, 3, -1, -1, -1, -1, -1, -1, -1, -1},
                                   {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                   {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                   {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                   {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                   {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                   {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                   {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                                   {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3}};

            for(int i = 0; i < 11; i++){
                for (int j = 0; j < 11; j++){
                    *arr[i][j] = newArr2[i][j];
                }
            }
            // memcpy(arr, newArr2, sizeof(newArr2));
            break;


        default:
            randomArray(arr);
    }
}

int* level(int level, Cell*** arr){

    int** base;

    base = (int**)malloc(11 * sizeof(int*));

    for (int i = 0; i < 11; i++) {
        base[i] = (int*)malloc(11 * sizeof(int));
    }

    baseArray(level, &base);

    int width = base[11][0], height = base[11][11];
    
    int* size = malloc(2 * sizeof(int));
    size[0] = width;
    size[1] = height;

    *arr = (Cell**)malloc(height * sizeof(Cell*));
    
    for (int i = 0; i < height; i++){
        *arr[i] = (Cell*)malloc(width * sizeof(Cell));
    }

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            *arr[y][x] = createNewCell(valueToNum(base[y][x]), valueToColor(base[y][x]));
        }
    }

    for (int i = 0; i < 11; i++) {
        free(base[i]);
    }
    free(base);

    return size;
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
