#include <stdio.h>
#include <stdlib.h>

class MemAlloc
{
public:
    static void* Alloc(const size_t sz, const char* loc)
    {
        void* p = malloc(sz);
        if(NULL==p)
            return NULL;

        list.Add(p, loc);
        return p;
    }

    static bool Free(void* p)
    {
        if(NULL!=p)
        {
            if( list.Remove(p) )
            {
                free(p);
                return true;
            }
        }
        return false;
    }

private:
    struct MemItem
    {
        MemItem(void* p, const char* inloc)
            : prev(NULL), next(NULL), ptr(p), loc(inloc)
        {
        }

        MemItem* prev;
        MemItem* next;
        void* ptr;
        const char* loc;
    };

    class List
    {
        public:
            List() : head(NULL), count(0) {}
            ~List(){ }
            void Add(void* p, const char* loc){ count++; }
            bool Remove(void* p) { count--; return true; }
            size_t Count() const { return count; }
        private:
            MemItem* head;
            size_t count;
    };

    static List list;

    static void CheckMemStatus()
    {
        if(list.Count() > 0)
        {
            printf("Something is wrong!\n");
        }
    }

    class Delegate
    {
        public:
            Delegate(){};
            ~Delegate(){ MemAlloc::CheckMemStatus(); }
    };

    static Delegate d;
};

MemAlloc::Delegate MemAlloc::d;
MemAlloc::List MemAlloc::list;

int main(int argc, char* argv[])
{

    int* p = (int*)MemAlloc::Alloc(100, "hello");
    int* o = (int*)MemAlloc::Alloc(102, "world");

    return 0;
}
