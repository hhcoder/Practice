#include <stdio.h>
#include <stdlib.h>

class CharStack
{
private:
    struct Node
    {
        Node(const char in_val)
            : val(in_val), next(NULL)
        {
        }
        char val;
        Node* next;
    };

    void push(Node* curr, const char c)
    {
        Node* p = new Node(c);
        p->next = head;
        head = p;
    }

    Node* remove_head()
    {
        Node* p = head;
        head = head->next;
        return p;
    }

public:
    CharStack()
        : head(NULL)
    {
    }

    void push(const char c)
    {
        if(NULL==head)
            head = new Node(c);
        else
            push(head, c);
    }

    char pop()
    {
        if(NULL!=head)
        {
            Node* p = remove_head();
            char c = p->val;
            if(p==head)
            {
                delete head;
                head = NULL;
            }
            else
            {
                delete p;
            }
            return c;
        }
        else
        {
            return '\n';
        }
    }

    bool empty()
    {
        return (head==NULL);
    }

private:
    Node* head;
};

void ClearStack(CharStack& s)
{
    while(!s.empty())
    {
        char c = s.pop();
        printf("%c", c);
    }
}

void ReverseWordPrint(const char* str)
{
    const char* p = str;

    CharStack word_stack;

    while(*p!='\0')
    {
        if(*p==' ')
        {
            ClearStack(word_stack);
            printf(" ");
        }
        else
        {
            word_stack.push(*p);
        }
        p++;
    }

    ClearStack(word_stack);
}

int main(void)
{
    const char* str1 = "good morning, Google campus";

    printf("String before reverse: %s\n", str1);

    printf("String after reverse:  ");
    ReverseWordPrint(str1);
    printf("\n");

    return 0;
}
