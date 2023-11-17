// dealing with pointers

#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int *ptr = &i;
    int **doubleptr = &ptr;

    cout << "i = " << i << endl;
    cout << "*ptr = " << *ptr << endl;
    cout << "&i = " << &i << endl;
    cout << "**doubleptr = " << **doubleptr << endl;
    cout << "*doubleptr = " << *doubleptr << endl;
    cout << "&ptr = " << &ptr << endl;

    cout<<endl<<endl<<endl<<endl;

    //char and pointer
    char ch[] = "abcde";
    //char *ctr1 = &ch;
    char *ctr2 = &ch[0];
    char *ctr3 = ch;
    char **doublectr = &ctr2;


    //cout<<"*ctr1 = "<<*ctr1<<endl;
    //cout<<"&ch = "<<&ch<<endl;
    cout<<"*ctr2 = "<<*ctr2<<endl;
    cout<<"&ch[0] = "<<&ch[0]<<endl;
    cout<<"*ctr3 = "<<*ctr3<<endl;
    cout<<"ch = "<<ch<<endl;

    cout<<endl<<"Incrementing *ctr++"<<endl;
    ++(*ctr2);
    cout<<"*ctr2 = "<<*ctr2<<endl;


    cout<<endl<<"Dealing with double char pointers"<<endl;

    cout<<"**doublectr = "<<**doublectr<<endl;
    cout<<"*doublectr = "<<*doublectr<<endl;
    cout<<"&ctr2 = "<<&ctr2<<endl;



}