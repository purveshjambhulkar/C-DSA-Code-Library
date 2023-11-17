#include <iostream>
#include <cmath>
#include <vector>
using namespace std ;  

int getpivot(vector<int> &arr, int n){
    
    int low = 0;
    int high = n -1;
    int mid = low + (high - low)/2;
    while (low < high){
      if (arr[mid] >= arr[0]) {
          low = mid+ 1;
          
      }
      else{
          high = mid;
      }
      mid = low + (high - low)/2;
      
    }
    return low;
}

int binarysearch(vector<int> &arr, int low, int high, int k) {
   
    int mid = low + (high - low)/2;
    while (low <= high) {
      if (arr[mid] == k) {
          return mid;
      }
      if (k > arr[mid]) {
          low = mid + 1;
      } else {
          high = mid - 1 ;
      }
     mid = low + (high - low)/2;

    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    int pivot = getpivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1]) {
        return binarysearch(arr, pivot, n-1, k);
    }
    else{
        return binarysearch(arr, 0, pivot - 1, k);
    }
}

int main(){
    
}