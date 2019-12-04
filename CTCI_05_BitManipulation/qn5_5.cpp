#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int a = 31;
    int b = 14;

    int t = a^b;
    int c = 0;
    for(int i=0; i<sizeof(t)*8; i++)
        if(t&1<<i) c++;

    printf("%d\n", c);
    return 0;
}
