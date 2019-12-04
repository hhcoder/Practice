#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

int main(int argc, char* argv[])
{
    const char* in_str = argv[1];

    size_t len = strlen(in_str);

    if(0==len || 1==len)
    {
        printf("no reverse performed\n");
        return 1;
    }

    char* t = (char*)malloc(len+1);
    strcpy(t, in_str);
    printf("\n %s \n", t);

    for(int i=0; i<len/2; i++)
    {
        Swap(&t[i], &t[len-i-1]);
    }
    
    printf("\n %s \n", t);

    return 1;
}

