#include <iostream>
#include <stack>

using namespace std;

int main() {
  // Create a stack of integers
  stack<int> myStack;

  // Push some elements onto the stack
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);

  // Print the top element of the stack
  cout << myStack.top() << endl;

  // Pop an element off the stack
  myStack.pop();

  // Print the top element of the stack again
  cout << myStack.top() << endl;

  return 0;
}
