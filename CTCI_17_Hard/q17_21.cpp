#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int FindMax(const int array[], const int st_idx, const int ed_idx)
{
    if(st_idx == ed_idx)
        return st_idx;

    int min = 0;
    int max_idx = -1;
    for(int i=st_idx; i<ed_idx; i++)
    {
        if(array[i]>min)
        {
            max_idx = i;
            min = array[i];
        }
    }

    return max_idx;
}

int CalculatePoolSize(const int array[], const int st_idx, const int ed_idx)
{
    int top = array[st_idx] < array[ed_idx] ? array[st_idx] : array[ed_idx];
    int sum = 0;

    for(int i=st_idx+1; i<ed_idx; i++)
    {
        sum +=  top - array[i];
    }
    printf("st_idx = %d, ed_idx = %d, sum = %d\n", st_idx, ed_idx, sum);

    return sum;
}

int main(void)
{
    const int input[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
    const int input_len = sizeof(input)/sizeof(int);

    const int expected_output = 26;

    int max_idx = FindMax(input, 0, input_len); 
    printf("max_idx = %d\n", max_idx);

    for(int i=0; i<input_len; i++)
        printf("%3d,", input[i]);
    printf("\n");
    for(int i=0; i<input_len; i++)
        printf("%3d,",i);
    printf("\n");

    int pool_size = 0;

    int left_max_idx = max_idx;
    while(1)
    {
        int left_max_2nd_idx = FindMax(input, 0, left_max_idx-1);
        if(left_max_2nd_idx==0 || left_max_2nd_idx==-1)
            break;
        pool_size += CalculatePoolSize(input, left_max_2nd_idx, left_max_idx);
        left_max_idx = left_max_2nd_idx;
    }

    int right_max_idx = max_idx;
    while(1)
    {
        int right_max_2nd_idx = FindMax(input, right_max_idx+1, input_len-1);
        if(right_max_2nd_idx==input_len-1 || right_max_2nd_idx==-1)
            break;
        pool_size += CalculatePoolSize(input, right_max_idx, right_max_2nd_idx);
        right_max_idx = right_max_2nd_idx;
    }

    printf("Answer is %d\n", pool_size);

    return 0;
}
