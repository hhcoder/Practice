#include <stdio.h>
#include <stdlib.h>

struct Node
{
    Node(const int in_val)
        : val(in_val), next(NULL)
    {
    }

    void Print()
    {
        printf("%d ", val);
    }

    int val;
    Node* next;
};

void AddNode(Node** in_head, const int in_val)
{
    Node* t = new Node(in_val);
    t->next = *in_head;
    *in_head = t;
}

void PrintNode(Node* in_head)
{
    Node* p = in_head;
    printf("\n");
    while(NULL!=p)
    {
        p->Print();
        printf("\n");
        p = p->next;
    }
    printf("\n");
}

Node* PickNode(Node* in_head, const int index)
{
    Node* p = in_head;

    for(int i=0; i<index; i++)
    {
        if(NULL!=p)
            p = p->next;
        else
            return NULL;
    }

    return p;
}

bool RemoveNode(Node* p)
{
    if(NULL!=p->next)
    {
        Node* t = p->next;

        p->val = t->val; //copy value
        p->next = t->next;

        delete t;

        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char* argv[])
{
    Node* head = NULL;

    for(int i=0; i<15; i++)
        AddNode(&head, i);

    PrintNode(head);

    Node* to_remove = PickNode(head, 13);

    if(NULL!=to_remove)
    {
        if( RemoveNode(to_remove) )
        {
            PrintNode(head);
        }
        else
        {
            printf("Remove fail\n");
        }

    }

    return 0;
}

