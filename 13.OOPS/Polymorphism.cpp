#include <iostream>
using namespace std;

//compile time polymorphism -> Method Overloading 

class A {

    public :
        void hello(){
            cout<<"Hello\n";
        }
        void hello(string name){
            cout<<"Hello "<<name<<endl;
        }
        
};


//run time polymorphism -> Method Overloading

class B  : public A{

    public : 
        void hello()  {
            cout<<"hello from class B\n";
        }
};

int main() {
     A a1 ;
     a1.hello();

     A a2 ;
     a2.hello("Purvesh");

     B b1 ;
     b1.hello();
    
}