#include <stdio.h>
#include <stdlib.h>

//Split stack;

class BaseIntStack
{
public:
    BaseIntStack(const size_t in_length, int* in_buf)
        : len(in_length), buf(in_buf), index(0)
    {
    }

    bool Push(const int in_val)
    {
        if(index<len)
        {
            buf[index] = in_val;
            index++;
            return true;
        }
        else
        {
            //Full
            return false;
        }
    }

    bool Pop(int* out_val)
    {
        if(NULL==out_val)
            return false;

        if(index!=0)
        {
            *out_val = buf[index];
            index--;
            return true;
        }
        else
        {
            //Empty
            return false;
        }
    }

private:
    size_t len;
    int* buf;
    size_t index;
};

class SubStack
{
public:
    SubStack()
    {
    }

    static const int available_slots = 10;
    static const int length_of_slot = 1000/10;

    bool Push(const int in_val)
    {
        if(stack_index<length_of_slot)
        {
            array[slot_index*length_of_slot + stack_index] = in_val;
            index++;
        }
        else
        {
            int t = available_slots.Pop();
            slot_stack.Push(t);
            slot_index = t;
            index = 0;
            array[slot_index*length_of_slot + stack_index] = in_val;
        }
    }

private:
    static BaseIntStack available_slots;

private:
    BaseIntStack slot_stack;
    size_t slot_index;
    size_t stack_index;
};

int main(int argc, char* argv[])
{
    return 0;
}
