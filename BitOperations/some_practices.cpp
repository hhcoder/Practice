#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void OnesComplement()
{
    time_t t;
    srand(time(&t));
    int a = rand()%100;
    int b = ~a;

    printf("\n===================\n");

    printf("a: %d\n", a);
    printf("~a: %d\n", b);
    printf("a + ~a is: %d", a+b);

    printf("\n===================\n");
}

bool IsPowerOf2(const unsigned int a)
{
    return !(a & a-1);
}

void PrintTest(const unsigned int in_val)
{
    if(IsPowerOf2(in_val))
        printf("%d is power of 2\n", in_val);
}

void PowerOf2()
{
    printf("\n===================\n");
    for(unsigned int i=0; i<65537; i++)
        PrintTest(i);
    printf("\n===================\n");
}

int NumberOfSetBits(int i)
{
    i = i - ((i >> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int MyNumberOfSetBis(int i)
{
    int count = 0;
    for(int j=0; j<8*sizeof(int); j++)
    {
        if(i&(1<<j))
            count++;
    }

    return count;
}

void PrintNumberOfBitTest(int i)
{
    int v1 = NumberOfSetBits(i);
    int v2 = MyNumberOfSetBis(i);

    if(v1!=v2)
        printf("Error!\n");
    else
        printf("value %d contains %d of bits\n", i, v2);
}

void NumberOfBitsTest()
{
    PrintNumberOfBitTest(1024);
    PrintNumberOfBitTest(256);
    PrintNumberOfBitTest(512);
    PrintNumberOfBitTest(3);
    PrintNumberOfBitTest(0xFF);
    PrintNumberOfBitTest(0xFFFF);
    PrintNumberOfBitTest(0xFFFE);
}

int main(int argc, char* argv[])
{
    OnesComplement();

    PowerOf2();

    NumberOfBitsTest();

    return 0;
}
