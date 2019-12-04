#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Swap(char* a, char* b)
{
    if(a==b)
        return;
    *a = (*a) ^ (*b);
    *b = (*a) ^ (*b);
    *a = (*a) ^ (*b);
}

void ReverseString(char* in_str, const size_t in_end_idx)
{
    size_t st = 0;
    size_t ed = in_end_idx;
    char* p_st = &in_str[st];
    char* p_ed = &in_str[ed];

    for(; st <= ed; st++, ed--)
    {
        Swap(&in_str[st], &in_str[ed]);
    }
}

void ReverseWordSequence(char* in_str)
{
    char* str = in_str;

    size_t end_idx = strlen(str)-1;
    ReverseString(str, end_idx);

    size_t word_end = 0;

    char* p_start = in_str;
    char* p_end = p_start;
    do
    {
        if(*p_end==' '||*p_end=='\0')
        {
            ReverseString(p_start, word_end-1);
            word_end = 0;
            p_start = p_end+1;
        }
        else
        {
            word_end++;
        }

        p_end++;

    }while(*p_end!='\0');

}

int main(void)
{
    const char* input = "five little kites flying high in the sky, said hi to the cloud as it passed by";
    char the_string[256];

    strcpy(the_string, input);

    printf("%s\n", the_string);

    ReverseWordSequence(the_string);

    printf("%s\n", the_string);

    return 0;
}
