#include <iostream>

using namespace std;

bool IsSumInSubSet(const int set[], const size_t len, const int sum)
{
    for(int i=0; i<len; i++)
    {
        if(set[i]==sum)
        {
            cout << "it's (" << set[i] << ")" << endl;
            return true;
        }
    }

    for(int i=0; i<len; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(set[i]==(sum-set[j]))
            {
                cout << "it's (" << set[i] << "," << set[j] << ")" << endl;
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char* argv[])
{
    //Example
    const int set[] = { 1, 34, 4, 11, 8, -3};
    const size_t len = 6;
    const int sum = 9;

    cout << "set = ";
    for(size_t i=0; i<len; i++)
        cout << set[i] << "," ;
    cout << endl << "sum = " << sum << endl;

    if( IsSumInSubSet(set, len, sum) )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
