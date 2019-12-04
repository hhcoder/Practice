#include <stdio.h>
#include <stdlib.h>

struct image_t
{
    unsigned int width;
    unsigned int height;
    unsigned char* pbuf;
};

int main(int argc, char* argv[])
{
    // Notice it's , (comma), not ; (semicolon)
    // okay, this is really boring since C++ has way much better method to do this. Anyway...
    struct image_t img = { .width = 1024, .height = 768, .pbuf = NULL, };

    printf("width=%d, height=%d, ptr=%p\n", img.width, img.height, img.pbuf);

    return 0;
}
