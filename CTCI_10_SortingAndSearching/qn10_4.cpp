#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int Minus(int a, int b)
{
    int large = a>b?a:b;
    int small = a<=b?a:b;

    int d = 0;
    for(int i=small; i<large; i++)
        d++;

    return a>b?d:-d;
}

int Multiply(int a, int b)
{
    int t = 0;
    int absa = abs(a);
    int absb = abs(b);
    for(int i=0; i<absb; i++)
        t+=absa;
    if(a<0&&b<0 || a>0&&b>0)
        return t;
    if(a>0&&b<0 || a<0&&b>0)
        return -t;
}

int Divide(int a, int b)
{
    if(b==0)
        return 0;
    int t = 0;
    int absa = abs(a);
    int absb = abs(b);
    while(absa>absb)
    {
        absa -=absb;
        t++;
    }
    if(a<0&&b<0 || a>0&&b>0)
        return t;
    if(a>0&&b<0 || a<0&&b>0)
        return -t;

}

int main(int argc, char* argv[])
{
    printf("enter numbers:");
    int a;
    scanf("%d", &a);
    int b;
    scanf("%d", &b);

    printf("%d - %d = %d\n", a, b, Minus(a,b));

    printf("%d * %d = %d\n", a, b, Multiply(a,b));

    printf("%d / %d = %d\n", a, b, Divide(a,b));

    return 0;
}
