
#include "cell.h"

Cell createNewCell(int value, int color, int path){

    Cell newCell;

    newCell.value = value;
    newCell.color = color;
    newCell.path = path;
    newCell.selected = false; // IDEE DE GUIGUI (DON'T FORGET TO DO)

    return newCell;

}

int*** randomArray(){

    int array[2][3][3] = {{{0, 0, 0}, {1, 0, 3}, {2, 0, 4}},
                           {{1, 0, 1}, {1, 0, 2}, {-1, -1, -1}}};

    return array;
}

int*** baseArray(short level){

    switch(level){

        case 1:
            int array[2][3][3] = {{{0, 0, 0}, {1, 0, 3}, {2, 0, 4}},
                           {{1, 0, 1}, {1, 0, 2}, {-1, -1, -1}}};
            return array;

        case 2:
            int array[3][3][3] = {{{2, 0, 4}, {2, 0, 5}, {3, 0, 6}},
                                  {{1, 0, 3}, {0, 0, 0}, {3, 0, 7}},
                                  {{1, 0, 2}, {1, 0, 1}, {-1, -1, -1}}};
            return array;
    
    }

    

}

Cell** level(short level){

    int*** base = baseArray(level);
    int heightSize = sizeof(base) / sizeof(base[0]);
    int widthSize = sizeof(base[0]) / sizeof(sizeof(base[0][0]));

    Cell** lvl = malloc(heightSize * sizeof(Cell*));
    for (int i = 0; i < heightSize; i++){
        lvl[i] = malloc(widthSize * sizeof(Cell));
    }

    for (int y = 0; y < heightSize; y++){
        for (int x = 0; x < widthSize; x++){
            lvl[y][x] = createNewCell(base[y][x][0], base[y][x][1], base[y][x][2]);
        }
    }

    return lvl;
}