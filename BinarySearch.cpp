#include <stdio.h>
#include <stdlib.h>

#include <time.h>

static void quickSort(int arr[], int left, int right) {
  int i = left, j = right;
  int tmp;
  int pivot = arr[(left + right) / 2];

  /* partition */
  while (i <= j) {
        while (arr[i] < pivot)
              i++;
        while (arr[j] > pivot)
              j--;
        if (i <= j) {
              tmp = arr[i];
              arr[i] = arr[j];
              arr[j] = tmp;
              i++;
              j--;
        }
  };

  /* recursion */
  if (left < j)
        quickSort(arr, left, j);
  if (i < right)
      quickSort(arr, i, right);
}


static int binarySearch(int arr[], int s, int left, int right)
{
    if(left>right)
        return -1;

    unsigned int mid = left + (right-left)/2;
    int mid_val = arr[mid];
    if(s > mid_val)
        return binarySearch(arr, s, mid+1, right);
    else if(s < mid_val)
        return binarySearch(arr, s, left, mid-1);
    else
        return mid;
}



class IntArray
{
public:
    IntArray(int* ibuf, const size_t ilen)
        : buf(ibuf), len(ilen)
    {
    }

    void Randomize()
    {
        time_t t;
        srand(time(&t));
        for(unsigned int i=0; i<len; i++)
        {
            buf[i] = rand()%50;
        }
    }

    void Sort()
    {
        quickSort(buf, 0, len-1);
    }

    void Print()
    {
        printf("\n");
        for(unsigned int i=0; i<len; i++)
        {
            printf("%6d ", buf[i]);
        }
        printf("\n");
    }

    int BinarySearch(const int val_to_search)
    {
        return binarySearch(buf, val_to_search, 0, len-1);
    }

    ~IntArray()
    {
    }

private:
    size_t len;
    int* buf;
};

int main(int argc, char* argv[])
{
    const size_t ARRAY_LEN = 10;
    int src[ARRAY_LEN];

    time_t t;
    srand(time(&t));
    for(unsigned int iter=0; iter<2000; iter++)
    {
        IntArray array_a(src, ARRAY_LEN);

        array_a.Randomize();

        array_a.Sort();

        srand(time(&t) + iter);
        unsigned int check_idx = ((unsigned int)rand())%ARRAY_LEN;
        int val_to_find = src[check_idx];

        int loc = array_a.BinarySearch(val_to_find);
        if(loc==-1)
            printf("Not found\n");
        else
        {
            if(val_to_find != src[loc])
            {
                printf("Value to find: %d\n", val_to_find);
                array_a.Print();
                printf("Error! Loc:%d\n", loc);
            }
        }
    }
    return 0;
}
