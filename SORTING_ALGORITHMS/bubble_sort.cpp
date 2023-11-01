#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   bool already_sorted = true ;//optimisation of code
    for(int i = 0 ; i< n-1 ; i++){
        for(int j = 0 ; j < n-i-1 ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
                already_sorted = false;
            }

        }
        if(already_sorted){
            break;
        }
    }
}
