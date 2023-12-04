#include <iostream>
#include <stack>
using namespace std;

/***************************************************/
// Approach 1
void deleteMiddle1(stack<int> &inputStack, int N)
{

    int size = N + 1;
    int top = size - 1;

    stack<int> dummy;

    for (int i = 1; i <= size; i++)
    {

        int data = inputStack.top();
        dummy.push(data);
        inputStack.pop();
    }

    if (size % 2 == 0)
    {
        int mid = size / 2;
        for (int i = 0; i < size; i++)
        {
            if (i != mid)
            {
                int data1 = dummy.top();
                inputStack.push(data1);
            }
            dummy.pop();
        }
    }
    else
    {
        int mid = (size / 2) + 1;
        for (int i = 1; i <= size; i++)
        {
            if (i != mid)
            {
                int data1 = dummy.top();
                inputStack.push(data1);
            }
            dummy.pop();
        }
    }
}
/**********************************************************/
// Approach 2 - Recursive Call
void deleteMiddle2(stack<int> &inputStack, int size, int count = 0)
{

    // base case
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // RECURSIVE CALL

    deleteMiddle2(inputStack, size, count + 1);

    inputStack.push(num);
}

/*************************************************************/
int main()
{

    stack<int> s;

    // adding element in the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int N = (s.size()) - 1;

    // deleteMiddle1(s, N);
    deleteMiddle2(s, N);
}