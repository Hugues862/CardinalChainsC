/*******************************************************************************************
*
*   raylib [core] example - Basic 3d example
*
*   Welcome to raylib!
*
*   To compile example, just press F5.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2020 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "test.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    // Initialization
    // --------------------------------------------------------------------------------------
    
    int windowState = 1;
    int level = 1;

    // int base[11][11];
    // int arrWidth = 0, arrHeight = 0;

    // getBase(1, base, &arrWidth, &arrHeight);
    
    // genLevel(arr, base, arrWidth, arrHeight);

    InitWindow(screenWidth + (2 * margin), screenHeight + (2 * margin), "raylib");
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        switch (windowState){

            case 0: // Menu
                menu(&level, &windowState);
                break;

            case 1: // Draw Level
                game(&level, &windowState);
                break;
            
            // case 2:
            //     nextMenu(&windowState);
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------


    return 0;
}