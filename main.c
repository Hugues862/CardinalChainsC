#include "cell.h"

#include <stdio.h>
#include <stdlib.h>



int load_level()
{
    FILE *pf;
    char* buff;
    pf = fopen ("levels/1.dat", "r");
    if (pf == NULL)
        return 0;

    


    fclose (pf); 
    return 1;
}

int main() {

    int length = 10;
    int** currentLevel = malloc(10 * sizeof(struct Cell));

    FILE *fin;

    fin = fopen( "levels/1.dat", "r" );
    if( fin == NULL )
        return 1;

    printf( "Character count: %d.\n", get_length_from_file_line( fin ) );

    fclose( fin );
    return 0;
}