#include <stdio.h>
#include <stdlib.h>

int Add(int a, int b)
{
    if(b==0)
        return a;

    int sum = a^b;
    int carry = (a&b)<<1;

    return Add(sum, carry);
}

int main(int argc, char* argv[])
{
    printf("Input a and b:");
    int a;
    scanf("%d", &a);

    int b;
    scanf("%d", &b);

    int t = Add(a, b);
    printf("%d+%d = %d\n", a, b, t);

    if(t!=a+b)
        printf("Wrong!\n");

    return 0;
}
