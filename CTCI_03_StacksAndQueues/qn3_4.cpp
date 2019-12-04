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

    Stack(const char* iname)
        : index(-1), name(iname)
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
        printf("%s\n", Name());
        if(!IsEmpty())
        {
            for(size_t i=0; i<=index; i++)
            {
                std::cout << array[i] << std::endl;
            }
        }
        else
        {
            printf("empty\n");
        }
    }

    const char* Name() { return name; }

private:
    int index;
    Type array[1024];
    const char* name;
};

void MovePlates(int n, Stack<int>* src, Stack<int>* buf, Stack<int>* dst)
{
    if(n>0)
    {
        MovePlates(n-1, src, dst, buf);
        int t = src->Pop();
        dst->Push(t);
        printf("Move %d from %s to %s\n", t, src->Name(), dst->Name());
        MovePlates(n-1, buf, src, dst);
    }
}

int main(int argc, char* argv[])
{
    Stack<int> src("src");
    Stack<int> buf("buf");
    Stack<int> dst("dst");

    for(int i=3; i!=0; i--)
        src.Push(i);

    src.Print();
    buf.Print();
    dst.Print();

    MovePlates(3, &src, &buf, &dst);

    printf("========\n");
    src.Print();
    buf.Print();
    dst.Print();

    return 0;
};
