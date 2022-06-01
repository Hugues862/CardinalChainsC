
#include "test.h"

int* hoverOn(int size, int margin){

    int posX, posY;

    posX = ((GetMouseX() - margin) - ((GetMouseX() - margin) % size)) / size;
    posY = ((GetMouseY() - margin) - ((GetMouseY() - margin) % size)) / size;

    int* pos[2] = {posX, posY};
    return pos;
}

bool isHover(int x, int y, int size, int margin){

    int pos[2] = {x, y};
    int* mousePos = hoverOn(size, margin);

    return pos == mousePos;

}
