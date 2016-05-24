#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hoffman.h"
#include "image.xpm"

//const char* text = "The cricket flies at midnight.";


int WIDTH,HEIGHT,COLOR;

//space is 32 in dec -- code uses 92 uniques characters


int mainPopulate()
{
    getLineInfo();
    char bigrams[WIDTH*HEIGHT-1][2];
    populate_bigrams(bigrams);
    print_bigrams(bigrams);
    //int bigram_frequency_table[26][26];//only a-z considered
    return 0;
}

int getLineInfo()
{
    int j= 0;
    char *str =  image_xpm[0], *p = str;
    while (*p) { // While there are more characters to process...
        if (isdigit(*p)) { // Upon finding a digit, ...
            long val = strtol(p, &p, 10); // Read a number, ...
            if(j== 0) {
                WIDTH = (int)val;
            }
            if(j == 1) {
                HEIGHT = (int)val;
            }
            if(j == 2) {
                COLOR = (int)val;
            }
            j++;

        } else { // Otherwise, move on to the next character.
            p++;
        }
    }
    printf("%d is width, %d is height. %d is number of character pairs.\n", WIDTH,HEIGHT,COLOR);
    return 0;
}


void populate_bigrams(char bigrams[WIDTH*HEIGHT-1][2])
{
    int k = COLOR+1;
    int i = 0;
    for(;k<COLOR+HEIGHT+1;k++) {
        char *text = image_xpm[k];
//        printf("%d %s\n", i, text);
        char *text_ptr = text;
        while (*(text_ptr)) {
            bigrams[i][0] = *text_ptr;
            bigrams[i][1] = *(text_ptr + 1);
//            printf("%d %c%c\n", i, bigrams[i][0], bigrams[i][1]);
            text_ptr++;
            text_ptr++;
            i++;
        }
    }

}


void print_bigrams(char bigrams[WIDTH*HEIGHT-1][2])
{
    int i = 0;
    for(;i<HEIGHT*WIDTH;i++)
    {
        printf("%d %c%c\n", i, bigrams[i][0],bigrams[i][1]);
    }
}