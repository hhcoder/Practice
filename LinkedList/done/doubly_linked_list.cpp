#include <stdio.h>
#include <stdlib.h>

class DoublyLinkedList
{
private:
    struct Node
    {
        Node(const int in_val)
            : prev(NULL), next(NULL), val(in_val)
        {
        }

        void Print()
        {
            printf("%d ", val);
        }

        Node* prev;
        Node* next;
        int val;
    };

    void InsertBefore(Node* curr, const int in_val)
    {
        Node* tmp = new Node(in_val);
        if(NULL==curr->prev)
        {
            tmp->next = curr;
            curr->prev = tmp;
            head = tmp;
        }
        else
        {
            tmp->next = curr;
            tmp->prev = curr->prev;
            curr->prev->next = tmp;
            curr->prev = tmp;
        }
    }

    void InsertAfter(Node* curr, const int in_val)
    {
        Node* tmp = new Node(in_val);
        if(NULL==curr->next)
        {
            tmp->prev = curr;
            curr->next = tmp;
            tail = tmp;
        }
        else
        {
            tmp->prev = curr;
            tmp->next = curr->next;
            curr->next->prev = tmp;
            curr->next = tmp;
        }
    }

    Node* Find(const int in_val)
    {
        Node* curr = head;
        while(NULL!=curr)
        {
            if(in_val == curr->val)
                return curr;
            curr = curr->next;
        }
        return curr;
    }

    void RemoveHead()
    {
        Node* tmp = head;
        head = head->next;
        if(NULL==head)
            tail = NULL;
        else
            head->prev = NULL;
        delete tmp;
    }

    void RemoveTail()
    {
        Node* tmp = tail;
        tail = tail->prev;
        if(NULL==tail)
            head = NULL;
        else
            tail->next = NULL;
        delete tmp;
    }

    void RemoveMiddle(Node* curr)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
    }

    void Remove(Node* curr)
    {
        if(NULL==curr)
            return;

        if(head==curr)
        {
            RemoveHead();
        }
        else if(tail==curr)
        {
            RemoveTail();
        }
        else
        {
            RemoveMiddle(curr);
        }
    }

public:
    DoublyLinkedList()
        : head(NULL), tail(NULL)
    {
    }

    ~DoublyLinkedList()
    {
        if(NULL!=head)
        {
            Node* curr = head;
            while(curr!=NULL)
            {
                Node* tmp = curr;
                curr = curr->next;
                delete tmp;
            }
        }
    }

    void InsertHead(const int in_val)
    {
        if(NULL==head)
        {
            head = new Node(in_val);
            tail = head;
        }
        else
        {
            InsertBefore(head, in_val);
        }
    }

    void InsertTail(const int in_val)
    {
        if(NULL==head)
        {
            head = new Node(in_val);
            tail = head;
        }
        else
        {
            InsertAfter(tail, in_val);
        }
    }

    void Remove(const int in_val)
    {
        Node* curr = Find(in_val);
        if(NULL!=curr)
            Remove(curr);
    }

    void PrintHeadToTail()
    {
        Node* curr = head;
        printf("-----\n");
        while(NULL!=curr)
        {
            curr->Print();
            curr = curr->next;
        }
        printf("\n-----\n");
    }

private:
    Node* head;
    Node* tail;
};

void TestInsertHead()
{
    DoublyLinkedList my_list;

    for(int i=0; i<10; i++)
        my_list.InsertHead(i);

    my_list.PrintHeadToTail();
}

void TestInsertTail()
{
    DoublyLinkedList my_list;

    for(int i=0; i<10; i++)
        my_list.InsertTail(i);

    my_list.PrintHeadToTail();
}

void TestRemove()
{
    DoublyLinkedList my_list;

    for(int i=0; i<10; i++)
        my_list.InsertTail(i);

    my_list.PrintHeadToTail();

    my_list.Remove(3);
    my_list.PrintHeadToTail();

    my_list.Remove(0);
    my_list.PrintHeadToTail();

    my_list.Remove(9);
    my_list.PrintHeadToTail();

    my_list.Remove(8);
    my_list.PrintHeadToTail();
}

int main(void)
{
    TestInsertHead();

    TestInsertTail();

    TestRemove();

    return 0;
}
