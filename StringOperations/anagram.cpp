#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class CharacterHistogram
{
public:
    CharacterHistogram(const char* str)
    {
        memset(hist, 0x00, sizeof(unsigned int)*26);

        size_t len = strlen(str);
        for(size_t i=0; i<len; i++)
        {
            IncrementBin(str[i]);
        }
    }

    ~CharacterHistogram()
    {
    }

public:
    void Print()
    {
        for(size_t i=0; i<26; i++)
        {
            if(hist[i]!=0)
            {
                char c = i+0x61;
                printf("%c: %d\n", c, hist[i]);
            }
        }
    }

    static bool Compare(const CharacterHistogram& hist1, const CharacterHistogram& hist2)
    {
        for(size_t i=0; i<26; i++)
        {
            if(hist1.hist[i] != hist2.hist[i])
                return false;
        }
        return true;
    }

private:
    void IncrementBin(const char c)
    {
        const char c_lower = ToLower(c);
        if(0x00!=c_lower)
        {
            int idx = FindIndex(c_lower);
            hist[idx]++;
        }
    }

    char ToLower(const char c)
    {
        if(c>=0x41&&c<=0x5A)
            return c+0x20;
        if(c>=0x61&&c<=0x7A)
            return c;
        return 0x00;
    }

    int FindIndex(const char c)
    {
        return c-0x61;
    }

private:
    unsigned int hist[26];
};

bool IsAnagram(const char* str1, const char* str2)
{
    CharacterHistogram hist_1(str1);
    CharacterHistogram hist_2(str2);
    return CharacterHistogram::Compare(hist_1, hist_2);
}

void TestAnagram(const char* str1, const char* str2, bool expect_result)
{
    if( expect_result != IsAnagram(str1, str2))
    {
        printf("Fail!\n");
    }
    else
    {
        // printf("Success!\n");
    }
}

int main(int argc, char* argv[])
{
    TestAnagram("hello", "world", false);
    TestAnagram("hello", "hello", true);
    TestAnagram("hello", "lohle", true);
    TestAnagram("Hello", "lohle", true);
    TestAnagram("He,l;lo", "l oh le", true);
    TestAnagram("William Shakespeare", " I am a weakish speller", true);
    TestAnagram("silent", "LISTEN", true);
    return 0;
}
