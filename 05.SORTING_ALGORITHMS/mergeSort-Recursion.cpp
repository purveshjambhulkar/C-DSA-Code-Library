#include <iostream>

using namespace std;

//MergeSort Algorithm using recursion

//Creating a Global Variable to cal InversionCount

int inversionCount = 0;

int mergeArray(int *arr, int start, int end ) {
    int mid = start + (end - start) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];
    int inversionCount = 0 ;                /*In the context of merge sort, 
                                             an inversion count is a measure of the disorder or "sortedness" of an array.
                                             It represents the total number of pairs of elements in the array that
                                              are out of order, meaning that a smaller element comes before a larger element.
                                               A lower inversion count indicates a more sorted array, while a higher inversion 
                                              count indicates a more unsorted array.*/

    // Copying the first half of arr into *first
    int mainArrayIndex = start;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    // Copying the next half of arr into *second
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // Sorting and merging the two halves into the main array
    mainArrayIndex = start;
    int index1 = 0;
    int index2 = 0;

    //Merging the two halves into the main array
    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
                //Inversion Detected
                inversionCount += len1 - index1;

            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;

    return inversionCount;

    
}

int mergeSortalgo(int *arr, int start, int end) {
    // Base case
    if (start >= end) {
        return 0;
    }

    int mid = start + (end - start) / 2;

    // Sort left subarray
    int leftInversion = mergeSortalgo(arr, start, mid);

    // Sort right subarray
    int rightInversion = mergeSortalgo(arr, mid + 1, end);

    int mergeInversion = mergeArray(arr, start, end);

    inversionCount = leftInversion + rightInversion + mergeInversion ; 

     
    return inversionCount; 
}

int main() {
    int arr[7] = {9, 4, 3, 7, 1, 5, 8};
    int size = 7;
        

    mergeSortalgo(arr, 0, size - 1);

    cout << "Printing the sorted array:\n";

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    cout<<"Inversion Count : "<<inversionCount<<endl;
    return 0;
}

//TIME COMPLEXITIES EXPLANATION
/*The time complexity of merge sort is O(n log n), where n is the number of elements in the array. This means that the time it takes to sort an array using merge sort is directly proportional to the logarithm of the number of elements.

To understand why merge sort has a time complexity of O(n log n), let's consider the following steps:

Divide the array into two halves. This takes O(n) time.

Recursively sort the two halves. Each half is half the size of the original array, so this takes O(n/2 log n) time for the left half and O(n/2 log n) time for the right half.

Merge the two sorted halves. This takes O(n) time.

The total time for all three steps is:

O(n) + O(n/2 log n) + O(n/2 log n) + O(n)
Simplifying this expression, we get:

O(n) + O(n log n)
The dominant term in this expression is O(n log n), so the overall time complexity of merge sort is O(n log n).*/
