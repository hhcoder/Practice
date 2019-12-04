#include <stdio.h>
#include <stdlib.h>

class DoublyLinkedList
{
private:
    struct Node
    {
        Node(Node* in_prev, Node* in_next, const int in_val)
            : prev(in_prev), next(in_next), val(in_val)
        {
        }
        void Print()
        {
            printf("%d, ", val);
        }
        Node* prev;
        Node* next;
        int val;
    };

    void InsertBefore(Node* curr, const int in_val)
    {
        Node* t = new Node(NULL, head, in_val);
        head = t;
    }

public:
    DoublyLinkedList()
        : head(NULL), tail(NULL)
    {
    }

    void Insert(const int in_val)
    {
        if(NULL==head)
        {
            head = new Node(NULL, NULL, in_val);
            tail = head;
        }
        else
        {
            InsertBefore(head, in_val);
        }
    }

    void Print()
    {
        Node* curr = head;
        while(NULL!=curr)
        {
            curr->Print();
            curr = curr->next;
        }
    }

private:
    Node* head;
    Node* tail;
};

int main(void)
{
    DoublyLinkedList dlist;

    for(int i=0; i<100; i++)
        dlist.Insert(i);

    dlist.Print();

    return 0;
}
