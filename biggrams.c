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
    int bigram_frequency_table[92][92];//only a-z considered
    populate_bigrams_freq_table(bigram_frequency_table, bigrams);
    find_max (bigram_frequency_table);
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
        char *text_ptr = text;
        while (*(text_ptr)) {
            bigrams[i][0] = *text_ptr;
            bigrams[i][1] = *(text_ptr + 1);
            text_ptr++;
            text_ptr++;
            i++;
        }
    }

}

int populate_bigrams_freq_table(int bigram_frequency_table[92][92], char bigrams[WIDTH*HEIGHT-1][2])
{
    int i,j;
    for(i = 0; i < 92; i++)
    {
        for(j=0;  j < 92;  j++)
        {
            bigram_frequency_table[i][j] = freq_of_bigram(' '+i, ' '+j, bigrams);
        }
    }
    return 0;
}




int freq_of_bigram(char a, char b, char bigrams[WIDTH*HEIGHT-1][2])
{
    int i = 0;
    int count = 0;
    for(;i<HEIGHT*WIDTH;i++)
    {
        if ((bigrams[i][0] == a) && (bigrams[i][1] == b) )
        {
            count++;
        }
    }
    return count;
}

void find_max (int bigram_frequency_table[92][92])
{
    int i, j, k;
    k = 1;
    char a, b ;
    int max = 0;
    printf("The twenty most frequent combinations in image:\n");
    while(k<20)
    {
        max= 0;
        for(i=0; i<92; i++)
        {
            for (j=0; j<92; j++)
            {
                if(bigram_frequency_table[i][j] > max)
                {
                    max = bigram_frequency_table[i][j];
                    a = 32+i;
                    b = 32+j;
                }
            }
        }
        printf("%c%c: %d\n", a,b,max);
        k++;
        bigram_frequency_table[a-' '][b-' '] = 0;
    }
}




























void print_bigrams(char bigrams[WIDTH*HEIGHT-1][2])
{
    int i = 0;
    for(;i<HEIGHT*WIDTH;i++)
    {
        printf("%d %d and %d\n", i, bigrams[i][0],bigrams[i][1]);
    }
}