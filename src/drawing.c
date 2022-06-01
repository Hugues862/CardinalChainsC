#include "test.h"


void drawLevel(Cell** arr){

    int sqrSide = 50;
    int sizeWidth = sizeof(arr[0]) / sizeof(Cell);
    int sizeHeight = sizeof(arr) / sizeWidth;
    int margin = 100; // Problem with hover (negative values)
    
    Color selectColor = {150, 255, 30, 0.5};
    Color sqrColor;
    
    BeginDrawing();

    ClearBackground(RAYWHITE);

    for (int y = 0; y < sizeHeight; y++){
        for (int x = 0; x < sizeWidth; x++){

            if (!arr[y][x].correct){
                sqrColor = getColor(arr[y][x].color);
            }
            else{
                sqrColor = YELLOW;
            }

            drawRect(x, y, sqrSide, margin, sqrColor);

            if ((arr[y][x].value == 0 && isHover(x, y, sqrSide, margin)) || (!arr[y][x].correct)) { // Can only click & hover on first cell
                drawRect(x, y, sqrSide, margin, selectColor);
                
                int prev[2] = {x, y};

                while(IsMouseButtonDown(1)){ // Click & Hold to select

                    int* pos = hoverOn(sqrSide, margin);
                    if (conditions(prev, pos)){
                        arr[pos[1]][pos[0]].selected = true;
                        drawRect(pos[0], pos[1], sqrSide, margin, selectColor);
                        memcpy(prev, pos, sizeof(pos));
                    }
                }

                if (IsMouseButtonReleased(1)){

                    checkWin(arr[y][x].color);

                }
            }



            // (originX, originY, lenX, lenY, Color)
            DrawText(getText(arr[y][x].value), margin + (sqrSide * x) + 15, margin + (sqrSide * y) + 15, 14.5, BLACK);

        }
    }

    EndDrawing();

}

void drawRect(int x, int y, int side, int margin, Color color){

    DrawRectangle(margin + (side * x), margin + (side * y), side, side, color);

}
