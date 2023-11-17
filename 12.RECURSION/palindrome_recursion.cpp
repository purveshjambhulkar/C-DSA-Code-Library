#include <iostream>
using namespace std;

bool isPalindrome(string& str , int& i , int& j){

    //base case
    if (str[i] != str[j])
    {
        return false;
    }

    if (i >= j)
    {
        return true;
    
    }

    //processing
    i++;
    j--;


    //resursive call

    return isPalindrome(str , i , j);
    
    

}
int main() {
     string str ;
     cout<<"Enter a String to check whether it is Palindrome or not\n"<<endl;
     cin>>str;
     int i = 0 ; 
     int j = str.length() - 1 ;

     if (isPalindrome(str , i , j))
     {
        cout<<"The given String is Palindrome\n";
     }else{
        cout<<"The given String is not Palindrome\n";
     }
     
    
}