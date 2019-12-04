#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

main()
{
    uint32_t all_ones = ~0;
    printf("all_ones: %u\n", all_ones);

    uint32_t mask = all_ones >> (32-3);
    printf("mask: %u\n", mask);
}
