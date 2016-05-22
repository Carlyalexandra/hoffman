#include "hoffman.h"
#include "house.xpm"
#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH strlen(text)-1
extern char* text;
extern char* phrase;

// Driver program to test above functions
int main()
{
//    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
//    int freq[] = {5, 9, 12, 13, 16, 45};
//    int size = sizeof(arr)/sizeof(arr[0]);
//    HuffmanCodes(arr, freq, size);
    frequency();
    return 0;
}
