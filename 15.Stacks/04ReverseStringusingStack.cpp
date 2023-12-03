#include <iostream>
#include <string>
#include <stack>
using namespace std;

// class Stack
// {
// public:
//     char data;
//     char *arr;
//     int top;
//     int size;
//     Stack(int size)
//     {
//         this->size = size;
//         arr = new char[size];
//         top = -1;
//     }
//     void push(char data)
//     {
//         if (top == size - 1)
//         {
//             cout << "OverFlow\n";
//             return;
//         }
//         else
//         {
//             top++;
//             arr[top] = data;
//         }
//     }
//     char pop()
//     {
//         if (top == -1)
//         {
//             cout << "UnderFlow\n";
//         }
//         else
//         {
//             char c = arr[top];
//             top--;
//             return c;
//         }
//     }

//     string Reverse()
//     {
//         char *rev = new char[size];
//         for (int i = 0; i < size; i++)
//         {
//             rev[i] = pop();
//         }
//         string anser = rev;
//         return anser;
//     }
// };

int main()
{
    // Stack s(7);
    // s.push('p');
    // s.push('u');
    // s.push('r');
    // s.push('v');
    // s.push('e');
    // s.push('s');
    // s.push('h');

    stack<char> d;
    d.push('p');
    d.push('u');
    d.push('r');
    d.push('v');
    d.push('e');
    d.push('s');
    d.push('h');

    int size = d.size();

    char *rev = new char[size];
    for (int i = 0; i < size; i++)
    {
        char c = d.top();
        rev[i] = c;
        d.pop();
    }
    string anser = rev;

    cout << anser;
}