#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hoffman.h"
#include "house.xpm"
const char* text = "The abababab cricket flies at midnight.";
#define LENGTH strlen(text)-1




int getFrequency()
{
//    FILE * finp =  fopen("drac-strip.txt","r");
//    char phrase[200000];
//    int line = 0;
//    while(fgets (phrase, 200000,  finp) )
//    {
//        line++;
//    }
//    fclose(finp);
//    char* text = phrase;
    int size;
    char bigrams[LENGTH][2];
    double bigram_frequency_table[26][26];
    size = populate_alpha_bigrams(bigrams);
    populate_bigrams_freq_table(bigram_frequency_table, bigrams, size);
    find_max (bigram_frequency_table);
    return 0;
}


int populate_alpha_bigrams(char bigrams[][2])
{
    int i = 0;
    const char* text_ptr = text;
    while (*(text_ptr+1))
    {
        if (isalpha((*text_ptr)) && isalpha((*(text_ptr+1))))
        {
            if ((*text_ptr) == tolower(*text_ptr) && (*(text_ptr+1)) == tolower(*(text_ptr+1)))
            {
                bigrams[i][0] = (*text_ptr);
                bigrams[i][1] = (*(text_ptr+1));
                i++;
            }
        }
        text_ptr++;
    }

    return i;
}


void populate_bigrams_freq_table(double bigram_frequency_table[26][26], char bigrams[][2], int size)
{
    int i = 0;
    int j;
    for(i = 0; i < 26; i++)
    {
        for(j=0;  j < 26;  j++)
        {
            bigram_frequency_table[i][j] = freq_of_bigram('a'+i, 'a'+j, bigrams, size);
        }
    }
}


float freq_of_bigram(char a, char b, char bigrams[][2], int size)
{
    int i = 0;
    int count = 0;
    float freq;
    const char* text_ptr = text;
    while(*(text_ptr+1))
    {
        if ((bigrams[i][0] == a) && (bigrams[i][1] == b) )
        {
            count++;
        }
        i++;
        text_ptr++;
    }
    freq = (float) count/size;
    return freq;
}

void find_max (double bigram_frequency_table[26][26])
{
    int i, j, k;
    k = 1;
    char a, b ;
    double max = 0;
    printf("The 26 most frequent combinations in drac-strip.txt are:\n");
    while(k<27)
    {
        max= 0;
        for(i=0; i<26; i++)
        {
            for (j=0; j<26; j++)
            {
                if(bigram_frequency_table[i][j] > max)
                {
                    max = bigram_frequency_table[i][j];
                    a = 97+i;
                    b = 97+j;
                }
            }
        }
        printf("%d: %c%c: %f\n", k,a,b,max);
        k++;
        bigram_frequency_table[a-'a'][b-'a'] = 0;
    }
}

