#include <stdio.h>
#include <ctype.h>
const char* phrase = "this is just a test of frequency\n";


int  frequency()
{
    char c;
    int freq[26] = {0};
    int total = 0;
    int i = 0;
    while(c = tolower(phrase[i]))
    {
        freq[c-'a']++; total++; i++;
    }
    printf("Computing letter frequency for the phrase: \n %s\n",phrase);
    for(i=0;i<26;i++)
    {
        printf("%c frequency: %d\n",'a'+i, freq[i]);
    }
    return 0;
}