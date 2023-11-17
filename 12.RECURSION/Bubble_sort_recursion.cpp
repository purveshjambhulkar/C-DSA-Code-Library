#include <iostream>
using namespace std;

void bubble_sort(int *arr , int size){

        //base case
        if (size == 1)
        {           
            return;
        }
        if (size == 0)
        {
            return;
        }

        //processing
        for (int  i = 0; i < size; i++)
        {
            if (arr[i] > arr[i+1])              
            {
                swap(arr[i] , arr[i+1]);
            }
            
        }
        
        //recursive call
        return bubble_sort(arr , size - 1);
        
        

}

void printArray(int *arr , int size){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main() {

    int arr[] = {1,2,3,4,6,5};
    int size = sizeof(arr)/sizeof(int);
    cout<<"Printing Array before Sorting : "<<endl;
    printArray(arr , size);
    cout<<endl;

    bubble_sort(arr , size);

    cout<<"Printing Array after Sorting : "<<endl;
    printArray(arr ,size);
    cout<<endl;

    
     

}