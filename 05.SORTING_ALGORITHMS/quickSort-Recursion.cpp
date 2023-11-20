#include <iostream>
using namespace std;

// Implementing QuickSort

int partition(int *arr, int start, int end) {
    int pivot = arr[start];
    int count = start;

    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < pivot) {
            count++;
            swap(arr[i], arr[count]);
        }
    }

    swap(arr[start], arr[count]);

    return count;
}

void quickSort(int *arr, int start, int end) {
    if (start < end) {
        int p = partition(arr, start, end);

        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);
    }
}

int main() {
    int arr[7] = {4, 2, 6, 8, 4, 3, 1};
    int size = 7;

    quickSort(arr, 0, size - 1);

    cout << "Printing the sorted array\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
