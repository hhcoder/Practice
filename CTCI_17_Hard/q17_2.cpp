#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double Rand0To1()
{
    srand(time());
    return (double)rand()/(double)RAND_MAX;
}

int PickInRange(const int low, const int high)
{
    return (int)(low + (int)(Rand0To1()*(high-low));
}

void Shuffle(int[] cards, const size_t len)
{
    for(size_t i=1; i<len; i++)
    {
        int t = PickInRange(0, i);
    }
}

int main(int argc, char* argv[])
{


    return 0;
}
