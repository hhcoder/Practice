#include <stdio.h>
#include <stdlib.h>

class SinglyLinkedList
{
private:
    struct Node
    {
        Node(const int in_val, Node* in_next)
            : val(in_val), next(in_next)
        {
        }
        void Print()
        {
            printf("%d  ", val);
        }
        int val;
        Node* next;
    };

    Node* RemoveHead()
    {
        if(NULL==head)
        {
            tail = NULL;
            return NULL;
        }
        Node* tmp = head;
        head = head->next;
        return tmp;
    }

    void InsertHead(const int in_val)
    {
        if(NULL==head)
        {
            head = new Node(in_val, NULL);
            tail = head;
        }
        else
        {
            Node* tmp = new Node(in_val, head);
            head = tmp;
        }
    }

    void PushTail(const int in_val)
    {
        if(NULL==head)
        {
            head = new Node(in_val, NULL);
            tail = head;
        }
        else
        {
            Node* tmp = new Node(in_val, NULL);
            tail->next = tmp;
            tail = tmp;
        }
    }

public:
    SinglyLinkedList()
        : head(NULL), tail(NULL)
    {
    }

    SinglyLinkedList(const SinglyLinkedList& rhs)
        : head(NULL), tail(NULL)
    {
        Node* curr = rhs.head;
        while(curr!=NULL)
        {
            PushTail(curr->val);
            curr = curr->next;
        }
    }

    ~SinglyLinkedList()
    {
        do
        {
            Node* curr = RemoveHead();
            if(NULL!=curr)
                delete curr;
            else
                break;
        }while(1);
    }

    void Stack(const int in_val)
    {
        InsertHead(in_val);
    }

    void Enque(const int in_val)
    {
        PushTail(in_val);
    }

    void Print()
    {
        printf("Linked list: ");
        Node* curr = head;
        while(curr!=NULL)
        {
            curr->Print();
            curr = curr->next;
        }
        printf("\n");
    }

private:
    Node* head;
    Node* tail;
};

void InterviewQuestion3()
{
    SinglyLinkedList list_forward;
    for(int i=0; i<5; i++)
        list_forward.Stack(i);
    list_forward.Print();

    SinglyLinkedList list_backward;
    for(int i=0; i<5; i++)
        list_backward.Enque(i);
    list_backward.Print();

    SinglyLinkedList list_copy(list_forward);
    list_copy.Print();

}

int main(void)
{
    InterviewQuestion3();

    return 0;
}
