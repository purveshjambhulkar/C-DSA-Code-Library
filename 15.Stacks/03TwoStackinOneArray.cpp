#include <iostream>
using namespace std;
class TwoStack
{

public:
    int top1;
    int top2;
    int *arr;
    int size;
    // Initialize TwoStack.
    TwoStack(int s)
    {
        this->size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }

    // Push in stack 1.
    void push1(int num)
    {
        // Write your code here.
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = num;
        }
        else
        {
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        if (top2 > top1 + 1)
        {
            top2--;
            arr[top2] = num;
        }
        else
        {
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // Write your code here.
        if (top1 == -1)
        {
            return -1;
        }
        else
        {
            int top = arr[top1];
            top1--;
            return top;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // Write your code here.
        if (top2 == size)
        {
            return -1;
        }
        else
        {
            int top = arr[top2];
            top2++;
            return top;
        }
    }
};
