#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    const char* in_str = argv[1];
    
    int count_table[256];
    memset(count_table, 0, sizeof(count_table));

    int i=0;
    while(in_str[i]!='\0')
    {
        if(count_table[in_str[i]]!=1)
        {
            count_table[in_str[i]]=1;
        }
        else
        {
            printf("no\n");
            return -1;
        }
        i++;
    }

    printf("yes");

    return 0;
}
