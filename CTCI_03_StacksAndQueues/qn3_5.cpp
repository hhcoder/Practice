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

class Queue
{
public:
    Queue()
    {
    }

    void Add(int v)
    {
        a.Push(v);
    }

    int Remove()
    {
        if(b.IsEmpty())
            while(!a.IsEmpty())
                b.Push(a.Pop());
        return b.Pop();
    }

    int Peek()
    {
        return b.Peek();
    }

    bool IsEmpty()
    {
        return a.IsEmpty() && b.IsEmpty();
    }

private:
    Stack<int> a;
    Stack<int> b;
};

int main(int argc, char* argv[])
{
    Queue a;

    a.Add(1);
    a.Add(2);
    a.Add(3);
    a.Add(4);

    while(!a.IsEmpty())
    {
        std::cout << a.Remove() << std::endl;
    }

    return 0;
};

