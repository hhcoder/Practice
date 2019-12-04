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

template <typename Type> void Sort(Stack<Type>& o, Stack<Type>& s)
{
    while(!o.IsEmpty())
    {
        Type t = o.Pop();
        while( !s.IsEmpty() && t<=s.Peek() )
        {
            o.Push(s.Pop());
        }
        s.Push(t);
    }
}

int main(int argc, char* argv[])
{
    Stack<int> s;

    s.Push(1);
    s.Push(3);
    s.Push(4);
    s.Push(2);

    s.Print();

    Stack<int> r;
    Sort(s, r);

    r.Print();

    return 0;
};

