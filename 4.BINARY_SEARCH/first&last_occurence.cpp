#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int firstocc(vector<int>& arr, int n, int k){
    int ans = -1;
    int key = k ;
    int low = 0 ; 
    int high = n-1 ;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (arr[mid] == key)
        {
            ans = mid;
            high = mid - 1;
        }
        if(arr[mid] < key){
            low = mid + 1;
        }
        if (arr[mid] > key)
        {
            high  = mid -1;
        }
        
        
    }
    return ans;
    
    


}
int lastocc(vector<int>& arr, int n, int k){
    int ans = -1;
    int key = k ;
    int low = 0 ; 
    int high = n-1 ;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (arr[mid] == key)
        {
            ans = mid;
            low = mid + 1;
        }
        if(arr[mid] < key){
            low = mid + 1;
        }
        if (arr[mid] > key)
        {
            high  = mid -1;
        }
        
        
    }
    return ans;
    
    


}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p ;
    p.first = firstocc(arr , n , k);
    p.second = lastocc(arr,  n, k);
    return p;
}

int main(){
        return 0;
}