#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Swap(char* buf, const size_t i, const size_t j)
{
    char t = buf[i];
    buf[i] = buf[j];
    buf[j] = t;
}

int main(void)
{
    const char* str = "abc";
    size_t len = strlen(str);
    char* buf = new char[len];
    strcpy(buf, str);

    for(size_t i=0; i<len; i++)
    {
        for(size_t j=i; j<len; j++)
        {
            Swap(buf, i, j);
            printf("%s\n", buf);
            Swap(buf, i, j);
        }
    }

    delete buf;

    return 0;
}
