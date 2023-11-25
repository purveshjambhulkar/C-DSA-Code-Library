#include <iostream>
using namespace std;

// 4 Pillars of Oops
// 1.Ecapsulation
// 2.Abstraction
// 3.Inheritance
// 4.Polymorphism

class name
{
public:
    string name = "Purvesh";

    void getName()
    {
        cout<<name<<" ";
    }
};

class education{
    public : 
        string education = "IT";

        void getEducation(){
            cout<<endl<<"Education : "<<education<<endl;
        }

};

//Inheritance Implementation
class surname : public name ,public education {

    public : 
        string surname = "Jambhulkar";

        void getSurname(){
            cout<<surname<<" ";
        }
};



int main()
{
    surname me;
    me.getName();
    me.getSurname();
    me.getEducation();
}