#include <iostream>
using namespace std;


int main(){

    //Creating a Dynamic 2D array by Dynamic memory allocation

    int rows , cols;
    cout<<"Enter the rows : ";
    cin>>rows;
    cout<<"Enter the cols : ";
    cin>>cols;

    //declaring the rows
    int **arr = new int*[rows];

    //declaring the cols
    for (int i = 0; i < rows; i++)
    {
        
        arr[i] = new int[cols];
    }


    //initializing the array
    cout<<endl<<"Enter the elements\n";
    for (int  i = 0; i < rows; i++)
    {
        for (int  j = 0; j < cols; j++)
        {
            int num;
            cin>>num;
            arr[i][j] = num;
        }
        
    }


    //printing the array

    for (int  i = 0; i < rows; i++)
    {
        for (int  j = 0; j < cols; j++)
        {
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    


}