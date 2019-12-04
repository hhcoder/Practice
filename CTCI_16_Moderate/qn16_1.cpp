#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int a = 35;
    int b = 96;

    printf("a=%d, b=%d\n", a, b);

    a = a^b;
    b = a^b;
    a = a^b;

    // a = a - b;
    // b = a + b;
    // a = b - a;

    printf("a=%d, b=%d\n", a, b);
    return 0;
}
