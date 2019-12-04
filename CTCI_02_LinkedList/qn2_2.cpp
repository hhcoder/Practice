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

Node* FindNthToTail(Node* head, const int n)
{
    Node* fast = head;
    for(int i=0; i<n; i++)
    {
        if(NULL!=fast)
            fast = fast->next;
        else
            return NULL; //list shorter than N
    }

    Node* slow = head;
    while(fast!=NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main(int argc, char* argv[])
{
    Node* head = NULL;

    for(int i=0; i<15; i++)
        AddNode(&head, i);

    PrintNode(head);

    Node* p = FindNthToTail(head, 15);

    if(NULL!=p)
    {
        printf("\n");
        p->Print();
        printf("\n");
    }
    else
    {
        printf("\nN is longer than the list length\n");
    }

    return 0;
}
