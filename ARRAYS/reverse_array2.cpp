#include <iostream>
using namespace std;

int main () {
    //reverse array 

    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
   
    int j = 0;
    for(int i = 9 ; i >= 0 ; i--){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
        j++;
        if(j >= i){
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    


}