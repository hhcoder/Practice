// Given any integer, print and English pharse that describes the integer (e.g., "One-Thousand, Two Hundred Thirty Four")

#include <stdio.h>
#include <stdlib.h>

class Stack 
{
public:
    Stack()
        : idx(0), is_full(false)
    {
    }

    void Push(const int v)
    {
        array[idx] = v;
        idx++;
    }

    int Peek()
    {
        return array[idx-1];
    }

    int Pop()
    {
        idx--;
        return array[idx];
    }

    bool IsEmpty()
    {
        return (idx==0);
    }

    int Count()
    {
        return idx;
    }

    bool AllZeros()
    {
        for(int i=0; i<idx; i++)
            if(array[i]!=0)
                return false;
        return true;
    }

private:
    int idx;
    bool is_full;
    int array[16];
};

void PrintValue(const int d)
{
    switch(d)
    {
        case 1: printf(" One"); break;
        case 2: printf(" Two"); break;
        case 3: printf(" Three"); break;
        case 4: printf(" Four"); break;
        case 5: printf(" Five"); break;
        case 6: printf(" Six"); break;
        case 7: printf(" Seven"); break;
        case 8: printf(" Eight"); break;
        case 9: printf(" Nine"); break;
    }
}

void PrintHundreds(const int d)
{
    PrintValue(d);
    if(d!=0)
        printf(" Hundred");
}

void PrintTens(const int d1, const int d2)
{
    if(d1==1)
    {
        switch(d2)
        {
            case 0: printf(" Ten"); break;
            case 1: printf(" Eleven"); break;
            case 2: printf(" Tweleve"); break;
            case 3: printf(" Thirteen"); break;
            case 4: printf(" Forteen"); break;
            case 5: printf(" Fifteen"); break;
            case 6: printf(" Sixteen"); break;
            case 7: printf(" Seventeen"); break;
            case 8: printf(" Eighteen"); break;
            case 9: printf(" Ninteen"); break;
        }

    }
    else
    {
        switch(d1)
        {
            case 2: printf(" Twenty"); break;
            case 3: printf(" Thirty"); break;
            case 4: printf(" Forty"); break;
            case 5: printf(" Fifty"); break;
            case 6: printf(" Sixty"); break;
            case 7: printf(" Seventy"); break;
            case 8: printf(" Eighty"); break;
            case 9: printf(" Ninty"); break;
        }
        PrintValue(d2);
    }
}

void PrintUnits(const int c)
{
    switch(c/3)
    {
        case 1:
            printf(" Thousand");
            break;
        case 2:
            printf(" Million");
            break;
        case 3:
            printf(" Billion");
            break;
        case 4:
            printf(" Trillion");
            break;
    }

}

void PrintEnglish(const int v)
{
    Stack s;

    int t = v;
    while(t!=0)
    {
        int i = t%10;
        s.Push(i);
        t = t/10;
    }

    while(!s.IsEmpty())
    {
        switch(s.Count()%3)
        {
            case 0:
            {
                int d0 = s.Pop();
                int d1 = s.Pop();
                int d2 = s.Pop();
                PrintHundreds(d0);
                PrintTens(d1, d2);
            }
            break;

            case 2:
            {
                int d1 = s.Pop();
                int d2 = s.Pop();
                PrintTens(d1, d2);
            }
            break;
            
            case 1:
            {
                int d2 = s.Pop();
                PrintValue(d2);
            }
            break;
        }

        PrintUnits(s.Count());
        if(s.AllZeros())
            break;
    }

    printf("\n");
}

int main(int argc, char* argv[])
{
    if(argc<2)
    {
        printf("Input a number!\n");
        return -1;
    }

    int v = atoi(argv[1]);

    PrintEnglish(v);

    return 0;
}
