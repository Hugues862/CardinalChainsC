#include "test.h"


void drawRect(int x, int y, int side, int margin, Color color){

    DrawRectangle(margin + (side * x), margin + (side * y), side, side, color);

}

void drawLevel(Cell** arr, int arrWidth, int arrHeight){

    int sqrSide = 50;
    
    int margin = 100; // Problem with hover (negative values)
    
    Color selectColor = {150, 255, 30, 0.5};
    Color sqrColor;
    
    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int y = 0; y < arrHeight; y++){
        for (int x = 0; x < arrWidth; x++){

            if (arr[y][x].correct == false){
                sqrColor = getColor(arr[y][x].color);
            }
            else{
                sqrColor = YELLOW;
            }

            drawRect(x, y, sqrSide, margin, sqrColor);
            // (originX, originY, lenX, lenY, Color)

            if ((arr[y][x].value == 0 && isHover(x, y, sqrSide, margin)) || (!arr[y][x].correct)) { // Can only click & hover on first cell
                drawRect(x, y, sqrSide, margin, selectColor);
                
                int prevX = x, prevY = y;

                while(IsMouseButtonDown(1)){ // Click & Hold to select

                    int posX = 0, posY = 0;
                    hoverOn(&posX, &posY, sqrSide, margin);

                    if (conditions(prevX, prevY, posX, posY)){
                        arr[posY][posX].selected = true;
                        drawRect(posX, posY, sqrSide, margin, selectColor);
                        
                        prevX = posX;
                        prevY = posY;
                    }
                }

                if (IsMouseButtonReleased(1)){

                    checkWin(arr[y][x].color);

                }
            }

            char str[2];
            sprintf(str, "%d", arr[y][x].value);
            DrawText(str, margin + (sqrSide * x) + 15, margin + (sqrSide * y) + 15, 14.5, BLACK);

        }
    }

    EndDrawing();

}