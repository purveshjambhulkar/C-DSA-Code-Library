#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


void selectionSort(vector<int>& arr, int n)
{   
    for(int i = 0; i < n-1 ; i++){
        int min_index = i ;

        for(int j = i + 1 ; j < n ; j++){
            if(arr[j] < arr[min_index]){
                min_index = j ;
            }
        }
        swap(arr[min_index] , arr[i]);
    }
}