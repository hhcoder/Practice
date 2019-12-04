#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

struct Node
{
    Node(const int in_val)
        : val(in_val), next(NULL)
    {
    }
    int val;
    Node* next;
    void Print(void)
    {
        printf("%d\n", val);
    }
};

class SinglyLinkedList
{
private:
    void Insert(Node* curr, const int in_val)
    {
        Node* p = curr;
        while(p->next!=NULL)
        {
            p = p->next;
        }
        p->next = new Node(in_val);
    }

    void Print(Node* curr)
    {
        if(NULL!=curr)
            curr->Print();
    }

    Node* Find(Node* curr, const int in_val)
    {
        Node* p = curr;
        while(p!=NULL)
        {
            if(p->val == in_val)
                return p;
            p = p->next;
        }
        return NULL;
    }

public:
    SinglyLinkedList()
        : head(NULL)
    {
    }

    ~SinglyLinkedList()
    {
        ClearList();
    }

    void Insert(const int in_val)
    {
        if(NULL==head)
        {
            head = new Node(in_val);
        }
        else
        {
            Insert(head, in_val);
        }
    }

    Node* RemoveHead()
    {
        if(NULL!=head)
        {
            Node* p = head;
            head = p->next;
            return p;
        }
        else
        {
            return NULL;
        }
    }

    Node* Find(const int in_val)
    {
        if(NULL==head)
            return NULL;
        return Find(head, in_val);
    }

    void Print()
    {
        printf("Value of linked list: \n");
        Node* p = head;
        if(p!=NULL)
            Print(head);
        while(p->next!=NULL)
        {
            p=p->next;
            Print(p);
        }
        printf("====\n");
    }

    SinglyLinkedList& operator=(const SinglyLinkedList& rhs)
    {
        if(this!=&rhs)
        {
            ClearList();
            Node* p = rhs.head;
            while(p!=NULL)
            {
                Insert(p->val);
                p = p->next;
            }
        }

        return *this;
    }

protected:
    void ClearList()
    {
        while(1)
        {
            Node* p = RemoveHead();
            if(NULL!=p)
                delete p;
            else
                break;
        }
        head = NULL;
    }

    Node* head;
};

// Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
void InterviewQuestion1()
{
    printf("InterviewQuestion1\n");

    SinglyLinkedList my_list;

    my_list.Insert(3);
    my_list.Insert(8);
    my_list.Insert(9);
    my_list.Insert(0);
    my_list.Insert(1);
    my_list.Insert(2);
    my_list.Insert(5);

    my_list.Print();

    Node* to_delete = my_list.Find(0);
    to_delete->Print();

    //In middle of a single linked list, so don't worry about end of list problem
    Node* to_delete_next = to_delete->next;
    memcpy(to_delete, to_delete_next, sizeof(Node));
    delete(to_delete_next);

    my_list.Print();
}

// You have two numbers represented by a linked list, where each node contains a single
// digit. The digits are stored in reverse order, such that the 1's digit is at the head of
// the list. Write a function that adds the two numbers and returns the sum as a linked
// list.

//Q: unsigned or signed?
// -> To simplify, unsigned


// in fact, implement digits in link list should be a has-a not a is-a
// -> can you apply + operator on singlylinkedlist? no, then it's not is-a relation
class DigitsInLinkList : public SinglyLinkedList
{
private:
    void Assign(const DigitsInLinkList& rhs)
    {
        printf("Assign\n");
        if(this!=&rhs)
        {
            ClearList();
            Node* p = rhs.head;
            while(p!=NULL)
            {
                Insert(p->val);
                p = p->next;
            }
        }
    }

public:
    DigitsInLinkList()
    {
    }

    DigitsInLinkList(const DigitsInLinkList& rhs)
    {
        Assign(rhs);
    }

    DigitsInLinkList(const unsigned int in_val)
    {
        unsigned int val = in_val;
        do
        {
            unsigned int to_push = val % 10;
            Insert(to_push);
            val = val/10;
        } while(val!=0);
    }

    DigitsInLinkList& operator=(const DigitsInLinkList& rhs)
    {
        printf("Copy!\n");
        Assign(rhs);
        return *this;
    }

    DigitsInLinkList operator+(const DigitsInLinkList& rhs)
    {
        if(head==NULL)
            return rhs;
        if(rhs.head==NULL)
            return *this;

        DigitsInLinkList return_list;

        Node* p1 = head;
        Node* p2 = rhs.head;

        unsigned int to_carry = 0;

        while(1)
        {
            if(p1==NULL && p2==NULL && to_carry==0)
                break;

            unsigned int p1_val;
            if(p1!=NULL)
                p1_val = p1->val;
            else
                p1_val = 0;

            unsigned p2_val;
            if(p2!=NULL)
                p2_val = p2->val;
            else
                p2_val = 0;

            unsigned int val = p1_val + p2_val + to_carry;
            unsigned int to_push = val % 10;

            to_carry = val/10;
            // printf("val=%d, p1_val=%d, p2_val=%d, to_push=%d, to_carry=%d\n", val, p1_val, p2_val, to_push, to_carry);

            return_list.Insert(to_push);

            if(p1!=NULL)
                p1 = p1->next;
            if(p2!=NULL)
                p2 = p2->next;
        }

        return_list.Print();
        return return_list;
    }

    void Print()
    {
        unsigned int val = 0;
        unsigned int count = 1;
        Node* p = head;
        printf("Digits is:\n");
        if(p!=NULL)
        {
            while(1)
            {
                val += p->val*count;
                p = p->next;
                if(p!=NULL)
                    count*=10;
                else
                    break;
            }
        }
        printf("%d\n", val);
        printf("====\n");
    }
};

void InterviewQuestion2()
{
    printf("InterviewQuestion2\n");

    DigitsInLinkList dig_1(190);
    dig_1.Print();

    DigitsInLinkList dig_2(0);
    dig_2.Print();

    DigitsInLinkList dig_3 = dig_2 + dig_1;
    dig_3.Print();
}

//Reverse a singly linked list without using any C pointer
void InterviewQuestion3()
{
    SinglyLinkedList list_forward;
    list_forward.Insert(0);
    list_forward.Insert(1);
    list_forward.Insert(2);
    list_forward.Insert(3);
    list_forward.Insert(4);
    list_forward.Insert(5);
    list_forward.Print();
}

void TestAssignmentOperator()
{
    printf("TestAssignmentOperator\n");

    SinglyLinkedList list_a;
    list_a.Insert(3);
    list_a.Insert(5);
    list_a.Insert(7);
    list_a.Insert(9);

    list_a.Print();

    SinglyLinkedList list_b;
    list_b = list_a;

    list_b.Print();
}

int main(void)
{
    // InterviewQuestion1();

    // TestAssignmentOperator();

    // InterviewQuestion2();

    InterviewQuestion3();

    return 0;
}
