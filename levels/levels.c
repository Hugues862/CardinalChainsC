
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
        
        case 3:
            int array[4][4][3] = {{{2, 0, 5}, {2, 0, 4}, {1, 0, 1}, {0, 0, 0}},
                                  {{2, 0, 6}, {2, 0, 3}, {2, 0, 2}, {2, 1, 4}},
                                  {{3, 0, 7}, {5, 0, 10}, {1, 1, 2}, {1, 1, 3}},
                                  {{4, 0, 8}, {4, 0, 9}, {1, 1, 1}, {0, 1, 0}}};
            return array;

        case 4:
            int array[4][4][3] = {{{1, 0, 2}, {1, 0, 1}, {1, 1, 1}, {1, 1, 2}},
                                  {{2, 0, 3}, {0, 0, 0}, {0, 1, 0}, {2, 1, 3}},
                                  {{2, 0, 4}, {2, 0, 5}, {2, 1, 5}, {2, 1, 4}},
                                  {{3, 0, 7}, {3, 0, 6}, {3, 1, 6}, {3, 1, 7}}};
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