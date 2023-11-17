#include <iostream>
#include <string>
using namespace std;

int reverse_string(string& str , int &i , int& j){

        //base case
        if (i >= j)
        {
            return 1;
        }
        
        
        //processing
        char temp = str[i] ; 
        str[i] = str[j] ; 
        str[j] =  temp ; 
        i++;
        j--;

        //recursive call
        return reverse_string(str , i , j);




}

int main() {
     string str = "purvesh"; 
     int i = 0 ;
     int j = str.length() - 1;
    cout<<"Before reverse : "<<str<<endl;
     reverse_string(str , i , j);
   cout<<"After reverse : "<<str<<endl;
}