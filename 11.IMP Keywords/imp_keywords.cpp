#include <iostream>
using namespace std;

#define Greet() (cout<<"This is a execution of macro function")
#define PI 3.14 //defining a Object macro
#define X100(x) ((x)*(100)) //defining function as macro

inline int square(int x){
    return x*x;
}


int main() {
    int rad = 10;
    int area = PI * square(rad); //using inline function to cal sq
    cout<<area<<endl;

    cout<<"100 times of rad is : "<<X100(rad)<<endl;//using function macro

    Greet();


    
}