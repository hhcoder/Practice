#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Node
{
    Node(const int in_val)
        : val(in_val), left(NULL), right(NULL)
    {
    }

    void Print()
    {
        printf("%d, ", val);
    }

    int val;
    Node* left;
    Node* right;
};

class BST
{
public:
    BST()
        : root(NULL)
    {
    }

    bool Add(const int in_val)
    {
        if(NULL==root)
        {
            root = new Node(in_val);
        }
        else
        {
            return AddNode(root, in_val);
        }
    }

    void Print()
    {
        return PrintNode(root);
    }
    
    bool Remove(const int in_val)
    {
        if(NULL!=root)
        {
            if(in_val==root->val)
            {
                printf("Root removal is not supported yet\n");
                return false;
            }
            else
            {
                Node* t;

                if(in_val>root->val)
                    t = RemoveNode(root, root->right, in_val);
                else
                    t = RemoveNode(root, root->left, in_val);

                if(NULL!=t)
                {
                    delete t;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }

private:
    bool AddNode(Node* in_root, const int in_val)
    {
        if(in_val<in_root->val)
        {
            if(in_root->left!=NULL)
            {
                return AddNode(in_root->left, in_val);
            }
            else
            {
                in_root->left = new Node(in_val);
                return true;
            }
        }
        else if(in_val>in_root->val)
        {
            if(in_root->right!=NULL)
            {
                return AddNode(in_root->right, in_val);
            }
            else
            {
                in_root->right = new Node(in_val);
                return true;
            }

        }
        else //in_val==in_root->val
        {
            return false;
        }
    }

    Node* RemoveNode(Node* in_parent, Node* in_root, const int in_val)
    {
        if(in_root==NULL)
            return NULL;

        if(in_val>in_root->val)
        {
            return RemoveNode(in_root, in_root->right, in_val);
        }
        else if(in_val<in_root->val)
        {
            return RemoveNode(in_root, in_root->left, in_val);
        }
        else
        {
            if(in_root->left!=NULL && in_root->right!=NULL)
            {
                in_root->val = FindMin(in_root->right);
                return RemoveNode(in_root, in_root->right, in_root->val);
            }
            else if(in_root->right==NULL)
            {
                in_parent->left = in_root->left;
                return in_root;
            }
            else
            {
                in_parent->right = in_root->right;
                return in_root;
            }
        }
            
    }

    int FindMin(Node* in_root)
    {
        if(in_root->left==NULL)
            return in_root->val;
        else
            return FindMin(in_root->left);
    }

    void PrintNode(Node* in_root)
    {
        if(NULL!=in_root)
        {
            PrintNode(in_root->left);
            in_root->Print();
            PrintNode(in_root->right);
        }
    }


private:
    Node* root;
};

void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int PickInRange(int start, int end)
{
    srand(time(NULL)*time(NULL));
    float v = rand()/(float)RAND_MAX;
    return start + round(v*(end-start));
}

void Shuffle(int array[], const size_t len)
{
    for(size_t i=len-1; i>0; i--)
    {
        int j=PickInRange(0,i);
        Swap(&array[i], &array[j]);
    }
}

int main(int argc, char* argv[])
{
    const size_t len = 10;
    int array[len];
    for(int i=0; i<len; i++)
        array[i] = i;

    Shuffle(array, len);

    printf("Input sequence: \n");
    for(int i=0; i<len; i++)
        printf("%d ", array[i]);
    printf("\n");

    BST  my_bst;

    for(int i=0; i<len; i++)
        my_bst.Add(array[i]);

    my_bst.Print();

    printf("Input value to remove: ");
    int in_value;
    scanf("%d", &in_value);
    if( false == my_bst.Remove(in_value) )
    {
        printf("Cannot find node to remove!\n");
    }

    my_bst.Print();

    return 0;
}
