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

void AddNode(Node** in_head, const int in_val) {
    Node* t = new Node(in_val);
    t->next = *in_head;
    *in_head = t;
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

void RemoveDuplicate(Node* head)
{
    Node* base = head;

    while(NULL!=base)
    {
        Node* runner = base;
        while(NULL!=runner->next)
        {
            if(base->val == runner->next->val)
            {
                Node* t = runner->next;
                runner->next = t->next;
                delete t;
            }
            else
            {
                runner = runner->next;
            }
        }

        base = base->next;
    }
}

int main(int argc, char* argv[])
{
    Node* head = NULL;

    for(int i=0; i<8; i++)
    {
        AddNode(&head, i);
        AddNode(&head, i);
    }

    PrintNode(head);

    RemoveDuplicate(head);
    PrintNode(head);

    return 0;
}

