#include <stdlib.h>
#include <stdio.h>
#include <iostream>

static int NumberOfBits(const int v)
{
    int count = 0;
    for(int i=0; i<sizeof(v)*8; i++)
    {
        if( v & 1<<i) count++;
    }
    return count;
}

//Solution 1: Count # of bits, if 1, it's power of 2
// static bool IsPowerOf2(const int v)
// {
//     if(NumberOfBits(v)==1)
//         return true;
//     else
//         return false;
// }
//

//Solution 2: XOR
// Stupid idea
// static bool IsPowerOf2(const int v)
// {
//     int all_ones = 0;
//     all_ones = ~all_ones;
//     if( v^v ==  all_ones)
//         return true;
//     else
//         return false;
// }

// Solution 3: best solution
// static bool IsPowerOf2(const int v)
// {
//     if( v & v-1 )
//         return false;
//     else
//         return true;
// }

// Solution 4: even simpler
static bool IsPowerOf2(const int v)
{
    return !(v & (v-1));
}

int main(int argc, char* argv[])
{
    std::cout << "Input a number: " << std::endl;

    int v;
    std::cin >> v;

    std::cout << " The number input: " << v << std::endl;

    if(IsPowerOf2(v))
        std::cout << "It's power of 2" << std::endl;
    else
        std::cout << "It's not" << std::endl;

    return 0;
}
