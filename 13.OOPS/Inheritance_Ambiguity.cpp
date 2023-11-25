#include <iostream>
using namespace std;

//Inheritance Abiguity

class base_class1 {
    public : 
        void func (){
            cout<<"base-class1"<<endl;
        }
};
class base_class2 {
    public : 
        void func (){
            cout<<"base-class2"<<endl;
        }
};
class derived_class : public base_class1 , public base_class2 {
   
};





int main() {

    derived_class obj1 ; 
    //obj1.func(); //there is a Ambiguity that which functio will be called 


    //this Ambiguity can be resolved using :: 'Scope Resolution Opt'
    obj1.base_class1 :: func();
    obj1.base_class2 :: func();
     
   
}