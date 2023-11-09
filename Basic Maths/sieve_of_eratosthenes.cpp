/*The Sieve of Eratosthenes is an ancient algorithm for
 finding all prime numbers up to a given limit.
 It's an efficient way to eliminate multiples of prime
  numbers to identify all prime numbers within a certain range. */

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> prime(n+1 , true);

        prime[0] = prime[1] = false;

        for(int i = 2 ; i < n ; i++){
            if(prime[i]){
                count++;
                for(int j = 2*i ; j < n ; j=j+i ){
                    prime[j] = 0;
                } 
            }
        }
        return count;
    
    }
};

int main(){
    Solution obj1 ;
    cout<<obj1.countPrimes(400);
}
