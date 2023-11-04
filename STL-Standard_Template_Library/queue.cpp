#include <iostream>
#include <queue>

using namespace std;

int main() {
  // Create a queue of integers
  queue<int> myQueue;

  // Enqueue some elements onto the queue
  myQueue.push(1);
  myQueue.push(2);
  myQueue.push(3);

  // Print the front element of the queue
  cout << myQueue.front() << endl;

  // Dequeue an element off the queue
  myQueue.pop();

  // Print the front element of the queue again
  cout << myQueue.front() << endl;

  return 0;
}
