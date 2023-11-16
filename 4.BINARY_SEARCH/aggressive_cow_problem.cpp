
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool ispossible(vector<int> &stalls, int k , int mid){
    int cowcount = 1;
    int lastposition = stalls[0];

    for(int i=0 ; i < stalls.size() ; i++){
        if(stalls[i] - lastposition >= mid){
            cowcount++;
            lastposition = stalls[i];
            if(cowcount == k){
                return true;
            }
        }
    }
    return false;
}



int aggressiveCows(vector<int> &stalls, int k)
{
   sort(stalls.begin() , stalls.end());
   int start = 0;
   int maxi = 0;
   for(int i = 0 ; i < stalls.size() ; i++){
       maxi = max(maxi , stalls[i]);
   }
   int end = maxi;
    int ans = -1;
   while(start <= end){
       int mid = start + (end - start)/2;
       if(ispossible(stalls , k,mid)){
            ans = mid ;
            start = mid+1;
       }
       else{
           end = mid - 1;
       }
   }
   return ans;
}