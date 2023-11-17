#include <iostream>
using namespace std;

//implementing binary search will the help of recursion

bool binary_search(int *arr, int size, int target, int high, int low, int mid)
{

    // base case
    if (target == arr[mid])
    {
        return true;
    }
                                            //tail recursion
    if (low == high)
    {
        return false;
    }
    
    //processing
    if (target > arr[mid])
    {
        low = mid + 1;
    }else if (target < arr[mid])
    {
        high = high - 1 ;
    }

    mid = low + (high - low) / 2;
    
    
    //recursive call
    return binary_search(arr, size , target, high , low , mid);
    
    
}

int main()
{
    int arr[] = {1, 2, 3, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(int);
    int target = 8;
    int high = size - 1;
    int low = 0;
    int mid = low + (high - low) / 2;

    bool answer = binary_search(arr, size, target, high, low, mid);

    if (answer)
    {
        cout << "Target is present in the array\n";
    }
    else
    {
        cout << "Target is not present in the array\n";
    }
}