#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CharSwap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void ReverseString(char* str)
{
    if(NULL==str)
        return;

    int len = strlen(str);
    int i=0;
    int j=len-1;
    for(;i<j; i++, j--)
    {
        CharSwap(&str[i], &str[j]);
    }
}

int main(int argc, char* argv[])
{
    char* n = NULL;
    ReverseString(n);

    char good[5] = {'g', 'o', 'o', 'd', '\0'};

    ReverseString(good);

    if(0!=strcmp(good, "doog"))
        printf("Fail!\n");

    char good_morning[13] = {'g', 'o', 'o', 'd', ' ', 'm', 'o', 'r', 'n', 'i', 'n', 'g', '\0'};

    ReverseString(good_morning);

    if(0!=strcmp(good_morning, "gninrom doog"))
        printf("Fail!\n");


    char a[2] = {'a', '\0'};

    ReverseString(a);

   if(0!=strcmp(a, "a"))
      printf("Fail!\n");

}
