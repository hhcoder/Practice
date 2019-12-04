#include <stdio.h>
#include <stdlib.h>

class SinglyLinkedList
{
private:
    struct Node
    {
        Node(const int in_val)
            : next(NULL), val(in_val)
        {
        }

        void Print()
        {
            printf("%d ", val);
        }

        Node* next;
        int val;
    };
public:
    SinglyLinkedList()
        : head(NULL)
    {
    }

    ~SinglyLinkedList()
    {
        if(NULL!=head)
        {
            do
            {
                Node* next = head->next;
                delete head;
                head = next;
            } while(head!=NULL);
        }
    }

    void Add(const int in_val)
    {
        Node* t = new Node(in_val);
        t->next = head;
        head = t;
    }

    void Print()
    {
        Node* c = head;
        while(NULL!=c)
        {
            c->Print();
            c = c->next;
        }
    }

private:
    Node* head;
};

int main(void)
{
    const size_t len = 10;
    int array[len];

    for(size_t i=0; i<len; i++)
        array[i] = i;

    for(size_t i=0; i<len; i++)
        printf("%d ", array[i]);
    printf("\n");

    SinglyLinkedList sll;

    for(size_t i=0; i<len; i++)
        sll.Add(array[i]);

    sll.Print();

    return 0;
}
