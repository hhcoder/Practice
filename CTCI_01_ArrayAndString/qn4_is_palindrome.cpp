#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Determine if input string is a permutation of palindrom
int main(int argc, char* argv[])
{
    const char* str = argv[1];

    size_t len = strlen(str);
    for(size_t i=0; i<len/2; i++)
    {
        if(str[i]!=str[len-i-1])
        {
            printf("Not palindrome\n");
            return -1;
        }
    }

    printf("Is palindrome\n");

    return 1;
}


