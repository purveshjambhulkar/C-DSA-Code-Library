#include <iostream>
#include <list>

using namespace std;

int main() {
  // Create a list of 10 integers
  list<int> myList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Print the list using iterators
  for (auto it = myList.begin(); it != myList.end(); ++it) {
    cout << *it << " ";
  }

  // Add a new element to the beginning of the list
  myList.push_front(0);

  // Add a new element to the end of the list
  myList.push_back(11);

  // Print the list again using iterators
  for (auto it = myList.begin(); it != myList.end(); ++it) {
    cout << *it << " ";
  }

  return 0;
}
