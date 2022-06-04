
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

void hoverClick(Cell arr[11][11], int x, int y, int width, int height, int* prevX, int* prevY){

    char xPos[20], yPos[20];
    sprintf(xPos, "Value of x : %d", x);
    sprintf(yPos, "Value of y : %d", y);
    DrawText(xPos, 15 + 15, 15 * 3, 14.5, BLACK);
    DrawText(yPos, 15 + 15, 15 * 4, 14.5, BLACK);

    if (conditions(arr, *prevX, *prevY, x, y) && arr[y][x].correct == false && IsMouseButtonDown(0)) {
        // Can only click & hover on first, neigbours, close value and same color cells
        
        arr[y][x].selected = true;

        bool select = true;
        *prevX = x;
        *prevY = y;
        DrawText("pog", 15, 15, 14.5, BLACK);


        // while(select){
        //     if (IsMouseButtonPressed(0)){ // Click & select 

        //         DrawText("haha", 15, 15, 14.5, BLACK);
        //         int posX = 0, posY = 0;
        //         hoverOn(&posX, &posY, sqrSide, margin);

        //         if (!(posX == prevX && posY == prevY) && conditions(arr, prevX, prevY, posX, posY)){
                    
        //             arr[posY][posX].selected = true;
        //             drawRect(posX, posY, sqrSide, margin, selectColor);
                    
        //             prevX = posX;
        //             prevY = posY;
        //         }
        //     }

        //     if (IsMouseButtonPressed(1)){

        //         DrawText("lmao", 15, 15, 14.5, BLACK);
        //         checkWin(arr, arr[y][x].color, width, height);
        //         select = false;

        //     }
        // }
    }
    
}

bool conditions(Cell arr[11][11], int currX, int currY, int nextX, int nextY){


    // Checks if hovered cell is same color, same value or +1 from previous cell
    if (currX == -1 && currY == -1 && arr[nextY][nextX].value == 0){

        return true;

    }

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