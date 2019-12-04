#include <stdio.h>
#include <stdlib.h>

#include <string.h>

class Item
{
public:
    Item(const char* in_name, const float in_val)
    {
        strcpy(name, in_name);
        val = in_val;
    }

    Item()
    {
        memset(name, 0x00, sizeof(name));
        val = 0.0f;
    }

    Item(const Item& rhs)
    {
        strcpy(name, rhs.name);
        val = rhs.val;
    }

    const Item& operator=(const Item& rhs)
    {
        if(&rhs==this)
            return *this;
        val = rhs.val;
        strcpy(name, rhs.name);
        return *this;
    }

    inline const char* GetStr() const { return name; }
    inline const float GetVal() const { return val; }

    int Same(const char* str)
    {
        return !strcmp(str, name);
    }

private:
    static const unsigned int len = 64;
    char name[len];
    float val;
};

class SinglyLinkedList
{
private:
    struct InternalItem
    {
        InternalItem(void)
            : next(NULL)
        {
        }

        InternalItem(const Item& in_val)
            : val(in_val), next(NULL)
        {
        }

        const InternalItem& operator=(const Item& rhs)
        {
            val = rhs;
            next = NULL;
        }

        Item val;
        InternalItem* next;
    };

    void RemoveAll()
    {
        InternalItem* c = head;
        while(NULL!=c)
        {
            InternalItem* p = c;
            c = c->next;
            delete p;
        }
    }

public:
    SinglyLinkedList()
        : head(NULL), tail(NULL)
    {
    }

    ~SinglyLinkedList()
    {
        if(NULL!=head)
        {
            RemoveAll();
        }
    }

    void AddTail(const Item& in_val)
    {
        InternalItem* t = new InternalItem(in_val);
        if(NULL==head)
        {
            head = t;
            tail = head;
        }
        else
        {
            tail->next = t;
            tail = tail->next;
        }
    }

    bool FindMatch(const Item& in_val, int* ret_val)
    {
        InternalItem* curr = head;
        while(NULL!=curr)
        {
            if(curr->val.Same(in_val.GetStr()))
            {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    bool FindMatchByKey(const char* in_str, float* ret_val)
    {
        InternalItem* curr = head;
        while(NULL!=curr)
        {
            if(curr->val.Same(in_str))
            {
                *ret_val = curr->val.GetVal();
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

private:
    InternalItem* head;
    InternalItem* tail;

};

class HashTable
{
private:
public:
    enum ADD_RESULT
    {
        ALREADY_EXISTED,
        ADDED,
    };

    enum QUERY_RESULT
    {
        NO_ENTRY,
        FOUND,
    };

    HashTable()
    {
        for(unsigned int i=0; i<length; i++)
            list[i] = new SinglyLinkedList();
    }

    int AddEntry(const Item& in_item)
    {
        SinglyLinkedList* p = list[Index(in_item.GetStr())];

        float ret_val;
        if(p->FindMatchByKey(in_item.GetStr(), &ret_val))
        {
            return ALREADY_EXISTED;
        }
        else
        {
            p->AddTail(in_item);
            return ADDED;
        }
    }

    int GetValue(const char* in_str, float* ret_val)
    {
        SinglyLinkedList* p = list[Index(in_str)];

        if(p->FindMatchByKey(in_str, ret_val))
        {
            return FOUND;
        }
        else
        {
            return NO_ENTRY;
        }
    }

private:
    unsigned int Index(const char* key)
    {
        unsigned int key_sum = 0;
        const char* p = key;
        while(*p!='\0')
        {
            key_sum += *p;
            p++;
        }
        return (key_sum % length);
    }

private:
    static const unsigned int length = 10;
    SinglyLinkedList* list[length];
};

int ExpectToFind(HashTable& my_table, const char* in_str, const float in_val)
{
    float out_val;
    if(HashTable::FOUND!=my_table.GetValue(in_str, &out_val))
    {
        printf("Cannot find %s!, something is wrong\n", in_str);
        return -1;
    }
    else
    {
        if(in_val!=out_val)
        {
            printf("Item value is different! expected: %f, val: %f\n", in_val, out_val);
            return -1;
        }
    }
    return 0;
}

int main(void)
{
    HashTable my_table;

    Item a("tommy", 1.0f);

    if(HashTable::ADDED!=my_table.AddEntry(a))
    {
        printf("Not added correctly\n");
        return -1;
    }

    if(HashTable::ALREADY_EXISTED!=my_table.AddEntry(a))
    {
        printf("Same item should be existed already\n");
        return -1;
    }

    Item b("tomym", 1.2f);
    if(HashTable::ADDED!=my_table.AddEntry(b))
    {
        printf("something wrong in AddTail\n");
        return -1;
    }

    if( 0!=ExpectToFind(my_table, a.GetStr(), a.GetVal()) )
        return -1;

    if( 0!=ExpectToFind(my_table, b.GetStr(), b.GetVal()) )
        return -1;

    return 0;
}
