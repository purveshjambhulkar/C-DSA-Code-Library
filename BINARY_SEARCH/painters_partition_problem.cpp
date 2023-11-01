#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool ispossible(vector<int> &arr, int k , int mid){
    int boardcount = 0;
    int painter = 1;
    int n = arr.size();
    for(int i = 0 ; i < n ;i++ ){
        if(boardcount + arr[i] <= mid){
            boardcount += arr[i];
        }
        else{
            painter++;
            if(painter > k || arr[i] > mid){
                return false;
            }
        }
    }
    return true;
}



int findLargestMinDistance(vector<int> &arr, int k)
{
   int start = 0;
   int sum = 0;
   int n = arr.size();
   for(int i =0 ; i< n;i++){
       sum += arr[i];
   }
   int end = sum;

   int ans = -1;
   int mid = start + (end-start)/2;
    while(start <= end){
        if(ispossible(arr , k , mid)){
                ans = mid;
                end = mid -1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (end-start)/2;

    }
    return ans;
}