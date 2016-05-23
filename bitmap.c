#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hoffman.h"
#include "image.xpm"


int printPicLines()
{
    int i,l = 0;
    for(;i<1;i++){
        printf("%s\n", image[0]);
    }
    printf("%d\n", sizeof(image)/sizeof(image[0]));

}

