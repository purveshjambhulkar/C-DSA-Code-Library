#include <iostream>
using namespace std;

int fibonacci(int x , int a , int b){
    
    if (x == 10)
    {
       return 1;
    }
    if (x==0)
    {
        cout<<"0 1 ";
    }
    
    
    int sum =  a + b ;

    a = b ;
    b = sum;
    x++;
    cout<<sum<<" ";
    fibonacci(x,a,b);
    


}



int main() {
     int a = 0;
    int b = 1;

    fibonacci(0 , a, b);
 
}