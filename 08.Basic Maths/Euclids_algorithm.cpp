/*The Euclidean algorithm is used to find the greatest common divisor (GCD) of two integers*/


//Substraction based approach

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a; // or return b; (since a == b at this point)
}

int main() {
    int num1, num2;
    cout << "Enter num 1\n";
    cin >> num1;
    cout << "Enter num 2\n";
    cin >> num2;

    cout << "GCD: " << gcd(num1, num2) << endl;

    return 0;
}
