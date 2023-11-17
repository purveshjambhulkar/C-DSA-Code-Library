#include <iostream>
using namespace std;

//linear search using recursion

bool linear_search(int *arr , int size ,int ele){

    //base case
    if (arr[0] == ele)
    {
        
        return true;
    }

    
    if (size == 0) {
        return false; 
    }

    


    return linear_search(arr+1 , size - 1 , ele);

    
    
}

int main() {

    int arr[] = {1,2,3,4,5,5,6,7,5,6,4,5,7};
    int size = sizeof(arr)/sizeof(int);

    bool ans = linear_search(arr , size ,5);

    if (ans)
    {
        cout<<"yes the element is present in the array\n";
    }
    else{
        cout<<"no the element is not present in the array\n";
    }



    
     
}