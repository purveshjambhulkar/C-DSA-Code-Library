#include <iostream>
using namespace std;
//CODE STUDIO QUESTION
int unique_ele (int *arr ,int size) {
    //find unique element of the array

    
    int flag;
    for (int i = 0; i < size; i++)
    {int sum = 0 ;
       for (int j = 0; j < size; j++)
       {
          if (arr[i] == arr[j])
          {
            sum++;
          }
          
       }
       if (sum == 2)
       {
        flag = 0 ;
       }
       else {
        flag = 1;
        return arr[i];
        break;
       }
       
       
    }

    


    
    }
int main(){
     int arr[5] = {1,2,1,2,3 };
     cout<<unique_ele(arr , 5);
}
    

