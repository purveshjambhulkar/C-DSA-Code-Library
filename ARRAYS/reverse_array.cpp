#include <iostream>
using namespace std;

int main () {
    //reverse array by creating another array

    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    int revarr[10];
    int j = 0;
    for(int i = 9 ; i >= 0 ; i--){
        revarr[j] = arr[i] ;
        j++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout<<revarr[i]<<" ";
    }
    


}