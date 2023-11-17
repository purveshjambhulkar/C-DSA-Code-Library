#include <iostream>
using namespace std;

// to find whether the array is sorted aor not with the help of Recursion

bool isSorted(int *arr, int size)
{

    // base case
    if (size == 0 || size == 1)
    {
        return true;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {

        bool remianingpart = isSorted(arr + 1, size - 1);
        return remianingpart;
    }
}

// to find the sum of the array

int sum_array(int *arr, int size, int i = 0)
{

    // base case
    if (i == size)
    {
        return 0;
    }

    if (size == 0)
    {
        return 0;
    }
    if (size == 1)
    {
        return arr[0];
    }

    return arr[i] + sum_array(arr, size, i + 1);
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int size1 = 5;
    int arr2[] = {1, 4, 4, 5, 2};
    int size2 = 5;

    bool ans1 = isSorted(arr1, size1);
    bool ans2 = isSorted(arr2, size2);

    if (ans1)
    {
        cout << "arr1 is sorted" << endl;
    }
    else
    {
        cout << "arr1 is not sorted" << endl;
    }
    if (ans2)
    {
        cout << "arr2 is sorted" << endl;
    }
    else
    {
        cout << "arr2 is not sorted" << endl;
    }
    int sum1 = sum_array(arr1, size1);
    int sum2 = sum_array(arr2, size2);

    cout << "Sum of arr1 : " << sum1 << endl;
    cout << "Sum of arr2 : " << sum2 << endl;
}