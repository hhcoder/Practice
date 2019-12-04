#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool MatchStr(const char* str1, const char* str2)
{
    const char* p1 = str1;
    const char* p2 = str2;
    while(*p1!='\0' && *p2!='\0')
    {
        if(*p1!=*p2)
            return false;
        p1++;
        p2++;
    }
    return true;
}

const char* StrStr(const char* main_str, const char* sub_str)
{
    const size_t main_len = strlen(main_str);
    const size_t sub_len = strlen(sub_str);
    const char* p_main = main_str;

    for(size_t i=0; i<main_len-sub_len; i++)
    {
        if(MatchStr(p_main, sub_str))
            return p_main;
        p_main++;
    }
    return NULL;
}

int main(void)
{
    const char* str_main = "Five little kites flying high in the sky, said, hi to the cloud as it passed by";
    const char* str_sub = "morning";

    printf("\n Main string: %s\n", str_main);
    printf("\n Sub string: %s\n", str_sub);

    const char* p_sub = StrStr(str_main, str_sub);
    if(NULL!=p_sub)
    {
        printf("\n Sub string is: %s\n", p_sub);
    }
    else
    {
        printf("\n Cannot find sub string\n");
    }

    return 0;
}
