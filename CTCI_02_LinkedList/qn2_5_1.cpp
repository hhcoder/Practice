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

void AddTail(Node** head, int in_val)
{
    if(NULL==*head)
    {
        *head = new Node(in_val);
        return;
    }

    Node* p = *head;
    Node* tail = p;
    while(p!=NULL)
    {
        tail = p;
        p=p->next;
    }

    Node* t = new Node(in_val);
    tail->next = t;
}

Node* AddTwoLists(Node* pa, Node* pb)
{
    if(NULL==pa && NULL==pb)
        return NULL;

    Node* head = NULL;

    int carry = 0;
    int sum = 0;

    while(pa!=NULL || pb!=NULL)
    {
        int v = carry;

        if(pa!=NULL)
            v += pa->val;

        if(pb!=NULL)
            v += pb->val;

        sum = v%10;
        carry = v/10;

        AddTail(&head, sum);
        if(pa != NULL)
            pa = pa->next;

        if(pb != NULL)
            pb = pb->next;
    }

    if(carry!=0)
        AddTail(&head, carry);

    return head;
}

int main(int argc, char* argv[])
{
    Node* head1 = NULL;

    AddNode(&head1, 1);
    AddNode(&head1, 1);
    AddNode(&head1, 1);

    PrintNode(head1);
    Node* head2 = NULL;

    AddNode(&head2, 1);
    AddNode(&head2, 2);
    AddNode(&head2, 3);

    PrintNode(head2);

    Node* result = AddTwoLists(head1, head2);
    // Node* result = NULL;
    // AddTail(&result, 9);
    // AddTail(&result, 8);
    // AddTail(&result, 5);
    PrintNode(result);

    return 0;
}

