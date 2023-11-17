#include <iostream>
using namespace std;

/*Problem Statement

You have been given a number of stairs. Initially, you are at the 0th stair, and you
need to reach the Nth stair. Each time you can either climb one step or two
steps. You are supposed to return the number of distinct ways in which you can
climb from the 0th step to Nth step.*/

int countclimbways(int x){

    //base case
    if (x < 0)
    {
        return 0 ; 
    }
    if (x == 0)
    {
        return 1;
    }

    return countclimbways(x-1) + countclimbways(x-2);
    
    

}

int main() {
    int x = 4;

    cout<<"Answer : "<<countclimbways(x);
}