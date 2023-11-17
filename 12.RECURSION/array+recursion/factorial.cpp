#include <iostream>
using namespace std;

int factiorial(int x){
    if (x == 0) //base case
    {
        return 1;
    }

    return x * factiorial(x-1);
    
}

int print(int x){ //printing numbers using recursion
    if (x == 0)
    {
        return 1;
    }

    cout<<x<<" ";       //Tail Recursion

    print(x-1);



    
    
}

int main() {
     int num = 6;
     
     cout<<factiorial(num)<<endl;

     print(num);
   
}