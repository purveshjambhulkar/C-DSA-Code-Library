#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &inputStack, int N)
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

    deleteMiddle(s, N);
}