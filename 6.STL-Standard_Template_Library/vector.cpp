#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Create a vector of 10 integers
  vector<int> myVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Print the vector
  for (int i = 0; i < myVector.size(); i++) {
    cout << myVector[i] << " ";
  }

  // Add a new element to the vector
  myVector.push_back(11);

  // Print the vector again
  for (int i = 0; i < myVector.size(); i++) {
    cout << myVector[i] << " ";
  }

  return 0;
}
