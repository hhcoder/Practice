#include <stdio.h>
#include <stdlib.h>
#include <iostream>

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

int main(int argc, char* argv[])
{
    return 0;
};
