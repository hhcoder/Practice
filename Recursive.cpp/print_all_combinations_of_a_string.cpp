#include <iostream>
#include <string>

using namespace std;

void PrintAllComb(const string i)
{
    if(i.length() == 1)
    {
        cout << i;
    }
    else
    {
        string p(i.begin()+1, i.end());
        PrintAllComb(p);
    }
}

int main(int argc, char* argv[])
{
    PrintAllComb("abc");

    return 1;
}
