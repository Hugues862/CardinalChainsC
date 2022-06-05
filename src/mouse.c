
#include "test.h"


void hoverOn(int* x, int* y){

    int posX, posY;

    posX = floor((GetMouseX() - margin) / sqrSide);
    posY = floor((GetMouseY() - margin) / sqrSide);

    *x = posX;
    *y = posY;
}

bool isHover(int x, int y){

    int posX = 0, posY = 0;
    hoverOn(&posX, &posY);

    return posX == x && posY == y;

}

void hoverClick(Cell arr[11][11], int x, int y, int width, int height, int* prevX, int* prevY, int* gameState){

    char xPos[20], yPos[20], selectState[25];
    sprintf(xPos, "Value of x : %d", x);
    sprintf(yPos, "Value of y : %d", y);
    sprintf(selectState, "Value of select : %d", (int)arr[y][x].selected);
    DrawText(xPos, 15 + 15, 15 * 3, 14.5, BLACK);
    DrawText(yPos, 15 + 15, 15 * 4, 14.5, BLACK);
    DrawText(selectState, 15 + 15, 15 * 5, 14.5, BLACK);

    if (conditions(arr, *prevX, *prevY, x, y) && arr[y][x].correct == false && IsMouseButtonPressed(0)) {
        // Can only click & hover on first, neigbours, close value and same color cells
        
        arr[y][x].selected = true;

        *prevX = x;
        *prevY = y;
        DrawText("pog", 15, 15, 14.5, BLACK);

    }

    if (IsMouseButtonDown(1)){

        DrawText("lmao", 15, 15, 14.5, BLACK);
        checkWinColor(arr, arr[*prevY][*prevX].color, width, height);
        checkWin(arr, width, height, gameState);
        *prevX = -1;
        *prevY = -1;

    }   
}

bool conditions(Cell arr[11][11], int currX, int currY, int nextX, int nextY) {

    // Checks if hovered cell is same color, same value or +1 from previous cell
    if (currX == -1 && currY == -1 && arr[nextY][nextX].value == 0) { return true; }

    else if ((abs(currX - nextX) == 1 && currY == nextY) || (abs(currY - nextY) == 1 && currX == nextX)){

        if (arr[currY][currX].color == arr[nextY][nextX].color && arr[nextY][nextX].selected == false){

            if (arr[currY][currX].value == arr[nextY][nextX].value || arr[currY][currX].value + 1 == arr[nextY][nextX].value){
                return true;
            }
        }
    }

    DrawText("TEST FAILED", 15 + 15, 15 + 15, 14.5, BLACK);

    return false;
}

void checkWinColor(Cell arr[11][11], int color, int width, int height){

    // Will check if every cell of X color is selected, if yes turn Correct into True

    bool change = true;

    for (int y = levelHeight; y < levelHeight + height; y++){
        for (int x = levelWidth; x < levelWidth + width; x++){

            if (arr[y][x].color == color){
                if (arr[y][x].selected == false){
                    change = false;
                }

                arr[y][x].selected = false;
                
            }

        }
    }

    if (change == true){
        for (int y = levelHeight; y < levelHeight + height; y++){
            for (int x = levelWidth; x < levelWidth + width; x++){

                if (arr[y][x].color == color){
                    arr[y][x].correct = true;
                }

            }
        }
    }
}

void checkWin(Cell arr[11][11], int width, int height, int* gameState){

    bool win = true;

    for (int y = levelHeight; y < levelHeight + height; y++){
        for (int x = levelWidth; x < levelWidth + width; x++){

            if (arr[y][x].correct == false && arr[y][x].value != -1){
                win = false;
            }

            if (win == false) {
                break;
            }

        }
    }

    if (win == true){

        *gameState = 1;
        
    }

}