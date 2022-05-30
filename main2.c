#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int load_level()
{
    FILE* ptr;
    
    //get size of levels
    int width = 0, height = 0;
    char temp;
    ptr = fopen("levels/1.dat", "r");
    
    while(temp != '\n'){
        temp = fgetc(ptr);
        if (isdigit(temp) && width == 0 && height == 0) {
            width = temp-'0';
            continue;
        };
        if (isdigit(temp) && width != 0 && height == 0) {
            height += temp-'0';
            continue;
        };
    }

    int i;
    int j;

    int** mat=malloc(height*sizeof(int*)); 
    for(i=0;i<width;++i){
        mat[i]=malloc(4*sizeof(int));
    }


    FILE *file;
    file=fopen("levels/1.dat", "r");

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++) 
        {
    //Use lf format specifier, %c is for character
        if (!fscanf(file, "%d", &mat[i][j])) 
            break;
        // mat[i][j] -= '0'; 
        printf("%d\n",mat[i][j]); //Use lf format specifier, \n is for new line
        }

    }
    fclose(file);
    return 0;
}

int main() {

    int length = 10;

    load_level();

    return 0;
}