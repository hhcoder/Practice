#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

template <typename Type> class Stack
{
public:
    Stack()
        : index(-1)
    {
    }

    bool IsEmpty()
    {
        return (index==-1);
    }

    void Push(const Type v)
    {
        index++;
        array[index] = v;
    }

    Type Pop()
    {
        Type v = array[index];
        index--;
        return v;
    }

    Type Peek()
    {
        return array[index];
    }

    void Print()
    {
        if(!IsEmpty())
        {
            for(size_t i=0; i<=index; i++)
            {
                std::cout << array[i] << std::endl;
            }
        }
    }

private:
    int index;
    Type array[1024];
};

static void SortStack(Stack<int>& a, Stack<int>& b)
{
    while(!a.IsEmpty())
    {
        int t = a.Pop();
        if(!b.IsEmpty()&&b.Peek()<t)
        {
            while(!b.IsEmpty())
                a.Push(b.Pop());
        }
        b.Push(t);
    }
}

int main(int argc, char* argv[])
{
    Stack<int> a;
    Stack<int> b;

    srand(time(NULL));
    for(int i=0; i<10; i++)
    {
        int t = round(rand()/(float)RAND_MAX*10);
        a.Push(t);
    }

    a.Print();

    SortStack(a, b);

    printf("After sort: \n");
    b.Print();
    return 0;
};
