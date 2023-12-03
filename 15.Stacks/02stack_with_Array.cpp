#include <iostream>
using namespace std;

// Implementing Stack using Array

class Stack
{
public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (top == size - 1)
        {
            cout << "Stack Overloaded\n";
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack UnderFlow\n";
        }
        else
        {
            top--;
        }
    }

    int gettop()
    {
        if (top == -1)
        {
            cout << "Stack Empty\n";
        }
        else
        {
            return arr[top];
        }
    }

    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // s.push(5);will return stack overloaded

    s.pop(); // pops 5

    cout << "Top : " << s.gettop() << endl;

    if (s.empty())
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Stack is not empty\n";
    }
}