#include <bits/stdc++.h> 
#include <vector>
using namespace std;
#include<iostream>
bool isPossible(vector<int> &arr, int n, int m ,int mid){
	int pagesum = 0;
	int studentcount = 1;
	for(int i = 0; i<n; i++){
		if(pagesum + arr[i] <= mid){
			pagesum += arr[i];
		}
		else {
			studentcount++;
			pagesum = arr[i];
			if(studentcount > m || arr[i] > mid){
				return false;
			}
		}
	}
	return true;
}


int allocateBooks(vector<int> &arr, int n, int m)
{
	int start = 0;
	int sum = 0;
	for(int i = 0 ; i <n ; i++){
		sum += arr[i];
	}
	int end = sum;
	int ans = -1;
        while (start <= end) {
			int mid = start + (end-start)/2;
			if(isPossible(arr , n , m ,mid)){
				ans  = mid ;
				end =  mid - 1;

			}
			else{
				start = mid = 1;
			}


			
        }
		return ans;
}