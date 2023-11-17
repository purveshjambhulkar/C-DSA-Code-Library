#include <iostream>
#include <cmath>
using namespace std;

int main () {
    //to find max and min oif the aray

    int arr[10] = {2,4,5,7,55,4,33,4,66,-7};
    int max = arr[0]; 
    int mini= arr[0];
    for(int i = 0 ; i < 10 ; i++){
        if (arr[i] > max )
        {
           max = arr[i];
        }
        if (arr[i] < mini)
        {
           mini = min(mini , arr[i]); //another way(we can do same for max)
        }
        
        
    }
    cout<<"MAX: "<<max<<endl;
    cout<<"MIN "<<mini<<endl;
    
    

}