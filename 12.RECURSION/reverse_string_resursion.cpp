#include <iostream>
#include <string>
using namespace std;

void reverse_string(string& str , int &i , int& j){ //passing str as reference var

        //base case
        if (i >= j)
        {
            return;
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

bool check_palindrone(string str){
     int i = 0 ;
     int j = str.length() - 1;
    string strcpy = str ; 
    reverse_string(strcpy , i,j);
    if (str == strcpy)
    {
        return true;
    }else {
        return false;
    }
    
}

int main() {
     string str = "nitin"; 
     int i = 0 ;
     int j = str.length() - 1;
    cout<<"Before reverse : "<<str<<endl;
     reverse_string(str , i , j);
   cout<<"After reverse : "<<str<<endl;

   cout<<endl<<"Checking Palindrome\n";
   if(check_palindrone(str)){
    cout<<"The given string is a Palindrome\n";
   }else{
    cout<<"The given String is not a Palindrome\n";
   }
}