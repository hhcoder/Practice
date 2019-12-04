#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RandRange(int start, int end)
{
    float v = rand()/(float)RAND_MAX;
    return start + (int)((float)(end-start)*v);
}

void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void Shuffle(int array[], const int start, const int end)
{
    srand(time(NULL)+time(NULL));
    for(int i=start; i<end; i++)
    {
        int idx = RandRange(start, i);
        Swap(&array[i], &array[idx]);
    }
}

int main(int argc, char* argv[])
{
    const int len = 10;
    int array[len];
    for(size_t i=0; i<len; i++)
        array[i] = i;

    printf("\n\n");
    for(size_t i=0; i<len; i++)
        printf("%d ", array[i]);
    printf("\n\n");

    Shuffle(array, 0, len);

    printf("\n\n");
    for(size_t i=0; i<len; i++)
        printf("%d ", array[i]);
    printf("\n\n");
    return 0;
}
