#include <iostream>
using namespace std;


//HEAP BASED ON 1 BASED INDEXING

class Heap {
public:
  int arr[100];
  int size;

  Heap() {
    arr[0] = -1; // We don't use index 0
    size = 0;
  }

  void insert(int ele) {
    size++;
    int index = size;
    arr[index] = ele;

    // Bubble up to maintain the Max-Heap property
    while (index > 1) {
      int parent = index / 2;

      if (arr[parent] < arr[index]) {
        swap(arr[parent], arr[index]);
        index = parent;
      } else {
        break;
      }
    }
  }

  void print() {
    for (int i = 1; i <= size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

  void deleteRoot() {
    if (size == 0) {
      cout << "Nothing to delete" << endl;
      return;
    }

    // Replace root with the last element
    arr[1] = arr[size];
    size--;

    // Bubble down to maintain the Max-Heap property
    int i = 1;
    while (i <= size) {
      int leftIndex = 2 * i;
      int rightIndex = 2 * i + 1;
      int largest = i;

      if (leftIndex <= size && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
      }
      if (rightIndex <= size && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
      }
      if (largest != i) {
        swap(arr[i], arr[largest]);
        i = largest;
      } else {
        break;
      }
    }
  }
};

void heapify(int arr[], int n, int i) {

  int largest = i;
  int left = 2 * i;
  int right = 2 * i + 1;
  if (left < n && arr[largest] < arr[left]) {
    largest = left;
  }
  if (right < n && arr[largest] < arr[right]) {
    largest = right;
  }

  if (largest != i) {
    swap(arr[largest], arr[i]);
    heapify(arr, n, largest);
  }
}

int main() {
  Heap h;
  // Insert some elements into the heap
  h.insert(50);
  h.insert(55);
  h.insert(53);
  h.insert(52);
  h.insert(54);

  // Print the heap
  h.print();

  // Delete the root element and print the heap again
  h.deleteRoot();
  h.print();

  int arr[6] = {-1, 54, 53, 55, 52, 50};
  int n = 5;
  for (int i = n / 2; i > 0; i--) {
    heapify(arr, n, i);
  }

  for (int i = 1; i < 6; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}
