
#include "test.h"

void hoverOn(int* x, int* y, int size, int margin){

    int posX, posY;

    posX = ((GetMouseX() - margin) - ((GetMouseX() - margin) % size)) / size;
    posY = ((GetMouseY() - margin) - ((GetMouseY() - margin) % size)) / size;

    *x = posX;
    *y = posY;
}

bool isHover(int x, int y, int size, int margin){

    int posX = 0, posY = 0;
    hoverOn(&posX, &posY, size, margin);

    return posX == x && posY == y;

}

void hoverClick(Cell arr[11][11], int x, int y, int width, int height, int sqrSide, int margin, Color selectColor){

    if (arr[y][x].value == 0 && isHover(x, y, sqrSide, margin) && !arr[y][x].correct) { // Can only click & hover on first cell
        drawRect(x, y, sqrSide, margin, selectColor);
        printf("test");
        int prevX = x, prevY = y;

        while(IsMouseButtonDown(1)){ // Click & Hold to select

            int posX = 0, posY = 0;
            hoverOn(&posX, &posY, sqrSide, margin);
            
            if (posX == prevX && posY == prevY){
                continue;
            }

            else if (conditions(arr, prevX, prevY, posX, posY)){
                arr[posY][posX].selected = true;
                drawRect(posX, posY, sqrSide, margin, selectColor);
                
                prevX = posX;
                prevY = posY;
            }

            if (IsMouseButtonReleased(1)){

                checkWin(arr, arr[y][x].color, width, height);
                break;

            }
        }
    }
    
}