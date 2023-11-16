//Dynamic memory allocation

#include <iostream>
using namespace std;
int func(int& ref){
        ref = 100;
        return ref;
 }

int main(){

    //reference variable

    int i = 199;

    int& refvar = i ;
    cout<<refvar<<endl;

  
    cout<<func(i);


    cout<<endl<<endl;


    //dynamically creating array

    int num ;
    cout<<"Enter the num : ";
    cin>>num;

    int *arr = new int[num];


    cout<<"Initialize the array\n";
    for (int i = 0; i < num; i++)
    {
        int num;
        cin>>num;
        arr[i] = num;
    }

    cout<<endl<<"Printing the array\n";
    for (int i = 0; i < num; i++)
    {
        cout<<arr[i]<<" ";
    }
    




}