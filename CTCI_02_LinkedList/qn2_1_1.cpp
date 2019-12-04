#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class HashTable
{
public:
    HashTable()
    {
        memset(arr, 0, sizeof(int)*1000);
    }

    bool Contains(const int val)
    {
       return (arr[val]!=0);
    }

    void AddEntry(const int val)
    {
        if(!Contains(val))
            arr[val] = 1;
    }
private:
    int arr[1000];
};

struct Node
{
    Node(const int v)
        : next(NULL), val(v)
    {
    }

    void Print()
    {
        printf("%d, ", val);
    }

    Node* next;
    int val;
};

void PrintAll(Node* head)
{
    Node* p = head;
    printf("\n");
    while(p!=NULL)
    {
        p->Print();
        p = p->next;
    }
    printf("\n");
}

void AddNode(Node** head, const int in_val)
{
    Node* p = new Node(in_val);
    p->next = *head;
    *head = p;
}

void RemoveDuplicate(Node* head)
{
    HashTable tbl;
    Node* prev = head;
    Node* curr = head;
    while(curr!=NULL)
    {
        Node* t = NULL;
        if(tbl.Contains(curr->val))
        {
            prev->next = curr->next;
            t = curr;
        }
        else
        {
            tbl.AddEntry(curr->val);
            prev = curr;
        }
        curr = curr->next;
    }
}

void RemoveDuplicate2(Node* head)
{
    Node* p = head->next;

    if(p == NULL)
        return;

    HashTable tbl;

    while(p->next!=NULL)
    {
        Node* t = NULL;

        if(tbl.Contains(p->next->val))
        {
            p->next = p->next->next;
        }
        else
        {
            tbl.AddEntry(p->next->val);
            p = p->next;
        }
    }


}

int main(int argc, char* argv[])
{
    Node* head = new Node(3);

    AddNode(&head, 5);
    AddNode(&head, 5);
    AddNode(&head, 5);
    AddNode(&head, 5);
    AddNode(&head, 8);

    PrintAll(head);

    RemoveDuplicate2(head);

    PrintAll(head);

    return 0;
}
