#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CountSpace(const char* str)
{
    int len = strlen(str);
    int count = 0;

    for(int i=0; i<len; i++)
    {
        if(str[i]==' ')
            count++;
    }

    return count;
}

void ReplaceFun(char* str)
{
    int orig_len = strlen(str);

    int count_of_space = CountSpace(str);

    int i=orig_len-1;
    int j=orig_len-1+2*count_of_space;

    str[j+1] = '\0';

    while(j!=0)
    {
        if(str[i]!=' ')
        {
            str[j] = str[i];
            j--;
        }
        else
        {
            str[j] = '0';
            j--;
            str[j] = '2';
            j--;
            str[j] = '%';
            j--;
        }
        i--;
    }
}

int main(int argc, char* argv[])
{
    char str[512];

    printf("Input string:\n");
    strcpy(str, "hello world is the first c++ program you will write");

    printf("Original: %s\n", str);

    ReplaceFun(str);

    printf("After: %s\n", str);

    return 0;
}
