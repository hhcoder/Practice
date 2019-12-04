#include <stdlib.h>
#include <stdio.h>

#include <time.h>

class Array
{
public:
    Array(const size_t in_length)
        : len(in_length), range(100)
    {
        array = new int[len];

        time_t t;
        srand(time(&t));
        for(size_t i=0; i<len; i++)
        {
            array[i] = rand()%range;
        }
    }

    ~Array()
    {
        if(NULL!=array)
        {
            delete[] array;
        }
    }

    void QuickSort()
    {
        QuickSort(0, len);
    }

    void Print(const char* in_description)
    {
        printf("\n%s:\n", in_description);
        for(size_t i=0; i<len; i++)
        {
            printf("%d  ", array[i]);
        }
        printf("\n");
    }

    bool IsSorted()
    {
        if(len==1)
            return true;

        for(size_t i=0; i<len-1; i++)
        {
            if(array[i]>=array[i+1])
                return false;
        }
        return true;
    }

private:
    void Swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

    size_t Partition(const size_t st_idx, const size_t ed_idx)
    {
        int pivot = array[st_idx];

        size_t i = st_idx;
        size_t j = i+1;

        for(;j<ed_idx; j++)
        {
            if(array[j]<=pivot)
            {
                i++;
                Swap(&array[i], &array[j]);
            }
        }

        Swap(&array[st_idx], &array[i]);

        return i;
    }

    void QuickSort(const size_t st_idx, const size_t ed_idx)
    {
        if(st_idx >= ed_idx)
            return;

        size_t p = Partition(st_idx, ed_idx);

        QuickSort(st_idx, p);
        QuickSort(p+1, ed_idx);
    }


private:
    int* array;
    size_t len;
    int range;
};

int main(void)
{
    Array arr(10);

    arr.Print("before QuickSort");

    arr.QuickSort();

    arr.Print("after QuickSort");

    if(arr.IsSorted())
        printf("pass!\n");
    else
        printf("fail!\n");

    return 0;
}
