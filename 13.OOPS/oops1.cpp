#include <iostream>
#include <string.h>
using namespace std;

class calci
{
private:
    int num1;
    int num2;
    int ans;

public:
    //static int and static function
    static int count ;
    static void whatsthis(){
        cout<<"This is OOPs code \n";
    }

    calci()
    { // Constructor
        cout << "Welcome to calci\n";
    }

    ~calci(){
        //Destructor
        cout<<"Destructor is call\n";
    }

   

    char *name = new char[10];
    
     // Copy Constructor
    calci(calci &temp)
    {
        char *ch = new char[10];
        strcpy(ch , temp.name);
        this->num1 = temp.num1;
        this->num2 = temp.num2;
    }

    void setNUM(int A, int B, char name1[]) // setter
    {
        this->num1 = A; // use of THIS keyword
        this->num2 = B;
        this->name = name1;
    }
    void add()
    {
        cout << "Addition : " << num1 + num2 << endl;
    }
    void sub()
    {
        cout << "Subtraction : " << num1 - num2 << endl;
    }
    void print(){
        cout<<"Name : "<<name<<endl;

    }};

//Initializing Static int count

int calci :: count = 5 ;





int main()
{
    // static
    char name[10] = "Purvesh";
    calci c1;
    c1.setNUM(3, 5 , name);
    c1.add();
    c1.sub();

    // dynamic
    calci *c2 = new calci();
    (*c2).setNUM(5, 8 ,name);
    (*c2).add();
    (*c2).sub();

    //Implementing Copy Constructor
    //Copy constructor is in-built constructor
    //it creates a copy object of the existing object

    //this is nothing but shallow copy where the address is copied

    calci o1;
    o1.setNUM(10, 9 ,name);
    calci o2(o1);//OR calci o2 = o1;
    o2.add();

    //Implementing custom copy constructor
    //by using Custom Copy Constructor we can implement Deep Copy where new copies are made 

    calci dq1 ;
    dq1.setNUM(10,10 ,name);
    calci dq2(dq1) ;
    dq2.add(); 


    //Copy Assignment Operator 

    calci p1;
    p1.setNUM(3 , 5, "rohan");
    calci p2;
    p2 = p1; //all values of p1 are copied in p2
    p2.add(); //answer will be 8


    cout <<"Static count : "<<calci::count << endl ; //:: -> Resolution Operator
    calci::whatsthis();


    
}
