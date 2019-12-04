#include <stdio.h>
#include <stdlib.h>

struct Node
{
    Node(const int in_val)
        : val(in_val), prev(NULL), next(NULL)
    {
    }

    void Print()
    {
        printf("%d ", val);
    }

    bool Equal(const int in_val)
    {
        return in_val == val;
    }

    Node* prev;
    Node* next;
    int val;
};

class DLL
{
public:
    DLL()
        : head(NULL), tail(NULL)
    {
    }

private:
    void CreateHead(const int in_val)
    {
        head = new Node(in_val);
        tail = head;
    }

    Node* Search(const int in_val)
    {
        Node* p = head;
        while(p!=NULL)
        {
            if(p->Equal(in_val))
                return p;
            p=p->next;
        }
        return NULL;
    }

public:
    void InsertAfterTail(const int in_val)
    {
        if(NULL==head)
        {
            CreateHead(in_val);
        }
        else
        {
            Node* new_node = new Node(in_val);

            tail->next = new_node;
            new_node->prev = tail;

            tail = new_node;
        }
    }

    void InsertBeforeHead(const int in_val)
    {
        if(NULL==head)
        {
            CreateHead(in_val);
        }
        else
        {
            Node* new_node = new Node(in_val);

            new_node->next = head;
            head->prev = new_node;

            head = new_node;
        }
    }

    int InsertBefore(const int in_search, const int in_val)
    {
        Node* p = Search(in_search);
        if(NULL==p)
            return FAIL;

        if(p==head)
        {
            InsertBeforeHead(in_val);
            return SUCCESS;
        }

        Node* new_node = new Node(in_val);

        new_node->prev = p->prev;
        p->prev->next = new_node;

        new_node->next = p;
        p->prev = new_node;

        return SUCCESS;
    }

    int InsertAfter(const int in_search, const int in_val)
    {
        Node* p = Search(in_search);

        if(NULL==p)
            return FAIL;

        if(p==tail)
        {
            InsertAfterTail(in_val);
            return SUCCESS;
        }

        Node* new_node = new Node(in_val);

        new_node->next = p->next;
        p->next->prev = new_node;

        new_node->prev = p;
        p->next = new_node;

        return SUCCESS;
    }

    void Remove(const int in_val)
    {
        Node* p = Search(in_val);
        if(NULL!=p)
        {
            if(NULL!=p->prev)
            {
                p->prev->next = p->next;
            }
            if(NULL!=p->next)
            {
                p->next->prev = p->prev;
            }
            delete p;
        }
    }

    const static int SUCCESS = 0;
    const static int FAIL = 1;

    int IsInList(const int in_val)
    {
        Node* p = Search(in_val);
        if(NULL!=p)
            return SUCCESS;
        else
            return FAIL;
    }

    void Print()
    {
        printf("\n");
        Node* p = head;
        while(p!=NULL)
        {
            p->Print();
            p = p->next;
        }
    }
private:
    Node* head;
    Node* tail;
};

int main(int argc, char* argv[])
{
    DLL dll;

    dll.InsertAfterTail(10);
    dll.InsertAfterTail(16);
    dll.InsertAfterTail(3);
    dll.InsertAfterTail(93);

    dll.Print();

    // int a;
    // printf("input value to find\n");
    // scanf("%d", &a);
    // if( DLL::SUCCESS==dll.IsInList(a))
    // {
    //     printf("found!\n");
    // }
    // else
    // {
    //     printf("not found!\n");
    // }
    //
    // int b;
    // printf("input value to remove\n");
    // scanf("%d", &b);
    // dll.Remove(b);
    // dll.Print();

    // printf("input value to insert before\n");
    // int c;
    // scanf("%d", &c);
    // printf("input value\n");
    // int d;
    // scanf("%d", &d);
    // dll.InsertBefore(c, d);
    //
    // dll.Print();

    printf("input value to insert after\n");
    int e;
    scanf("%d", &e);
    printf("input value\n");
    int f;
    scanf("%d", &f);
    dll.InsertAfter(e, f);

    dll.Print();

    return 0;
}
