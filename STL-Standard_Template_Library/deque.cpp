#include <iostream>
#include <deque>

using namespace std;

int main() {
  // Create a deque of 10 integers
  deque<int> myDeque = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Print the deque
  for (int i = 0; i < myDeque.size(); i++) {
    cout << myDeque[i] << " ";
  }

  // Add a new element to the front of the deque
  myDeque.push_front(0);

  // Add a new element to the back of the deque
  myDeque.push_back(11);

  // Print the deque again
  for (int i = 0; i < myDeque.size(); i++) {
    cout << myDeque[i] << " ";
  }

  return 0;
}
