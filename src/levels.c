
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
            arr[5][4] = createNewCell(2, 0);
            arr[4][4] = createNewCell(2, 0);
            break;
    }

}

/*
// void randomArray(int arr[11][11]){

//     int newArr[11][11] = {{0, 1, 2, -1, -1, -1, -1, -1, -1, -1, -1},
//                             {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                             {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                             {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                             {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                             {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                             {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                             {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                             {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                             {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                             {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3}};
            
//     for(int i = 0; i < 11; i++){
//         for (int j = 0; j < 11; j++){
//             arr[i][j] = newArr[i][j];
//         }
//     }
           
// }

// int valueToColor(int value){

//     int color = floor(value / 10);
//     return color;

// }

// int valueToNum(int value){

//     int num = value % 10;
//     return num;

// }

// void baseArray(int level, int arr[11][11]){

//     switch(level){

//         case 1:
//             int newArr1[11][11] = {
//                 {0, 1, 2, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3}
//                 };
            
//             for(int i = 0; i < 11; i++){
//                 for (int j = 0; j < 11; j++){
//                     arr[i][j] = newArr1[i][j];
//                 }
//             }
//             // memcpy(arr, newArr1, sizeof(newArr1));
//             break;

//         case 2:
//             int newArr2[11][11] = {
//                 {2, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {1, 0, 3, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {1, 1, 3, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//                 {3, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3}
//                 };

//             for(int i = 0; i < 11; i++){
//                 for (int j = 0; j < 11; j++){
//                     arr[i][j] = newArr2[i][j];
//                 }
//             }
//             // memcpy(arr, newArr2, sizeof(newArr2));
//             break;


//         default:
//             randomArray(arr);
//     }

// }

// void getBase(int level, int base[11][11], int* width, int* height){
    
//     baseArray(level, base);

//     *width = base[10][0];
//     *height = base[10][10];
// }

// void genLevel(Cell** arr, int base[11][11], int width, int height){

//     for (int y = 0; y < height; y++){
//         for (int x = 0; x < width; x++){
//             arr[y][x] = createNewCell(1, 0);
//             // arr[y][x] = newCell;
//             // printf("%d\n", arr[y][x].value);
//         }
//     }

// }
*/

Color getColor(int colorCode){

    switch(colorCode){
        case 0:
            return RED;
        case 1:
            return GREEN;
        case 2:
            return BLUE;
    }

    return WHITE;
}

bool conditions(Cell** arr, int currX, int currY, int nextX, int nextY){

    // Checks if hovered cell is same color, same value or +1 from previous cell

    if (arr[currY][currX].color == arr[nextY][nextX].color){

        if (arr[currY][currX].value == arr[nextY][nextX].value || arr[currY][currX].value + 1 == arr[nextY][nextX].value){
            return true;
        }
    }

    return false;

}

void checkWin(Cell** arr, int color, int width, int height){

    // Will check if every cell of X color is selected, if yes turn Correct into True

    bool change = true;

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){

            if (arr[y][x].color == color){
                if (arr[y][x].selected == false){
                    change = false;
                }
            }

        }
    }

    if (change){
        for (int y = 0; y < height; y++){
            for (int x = 0; x < width; x++){

                if (arr[y][x].color == color){
                    arr[y][x].correct = true;
                }

            }
        }
    }
}
