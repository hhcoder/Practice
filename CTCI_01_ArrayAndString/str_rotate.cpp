#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char* in_str = argv[1];

    printf("In Str: %s\n", in_str);

    size_t len = strlen(in_str);
    for(int i=0; i<len/2; i++)
     {
         char t = in_str[i];
         in_str[i] = in_str[len-1-i];
         in_str[len-1-i] = t;
     }

    printf("Out Str: %s\n", in_str);

    return 1;
}

