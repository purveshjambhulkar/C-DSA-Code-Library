#include <iostream>
#include <stack>
using namespace std;

int main()
{

    stack<int> s;

    // adding element in the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // removing element in the stack
    s.pop();

    // printing top element
    cout << "Printing the top element " << s.top() << endl;

    // empty or not
    if (s.empty())
    {
        cout << "Empty stack\n";
    }
    else
    {
        cout << "Not empty\n";
    }

    cout << "the size of the stack is " << s.size() << endl;
}