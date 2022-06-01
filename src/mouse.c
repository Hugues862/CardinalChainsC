
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