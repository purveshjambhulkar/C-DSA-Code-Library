#include <iostream>
#include <array>

using namespace std;

int main() {
  // Create an array of 10 integers
  std::array<int, 10> myArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // Print the array to the console
  for (int element : myArray) {
    std::cout << element << " ";
  }
  std::cout << endl;

  

  // Print the sorted array to the console
  for (int element : myArray) {
    std::cout << element << " ";
  }
  std::cout << endl;

  
  return 0;
}
