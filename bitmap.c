#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hoffman.h"
#include "image.xpm"
int width,height,color;

int printPicLines()
{
    int i,j,l = 0;
    for(;i<1;i++){
        printf("%s\n", image_xpm[0]);
    }
    char *str =  image_xpm[0], *p = str;
    while (*p) { // While there are more characters to process...
        if (isdigit(*p)) { // Upon finding a digit, ...
            long val = strtol(p, &p, 10); // Read a number, ...
            printf("%ld\n", val); // and print it.
            if(j== 0) {
               width = (int)val;
             }
            if(j == 1) {
                height = (int)val;
            }
            if(j == 2) {
                color = (int)val;
            }
            j++;

        } else { // Otherwise, move on to the next character.
            p++;
        }
    }
    printf("%d is width, %d is height. %d is number of character pairs.\n", width,height,color);
    return 0;
}

