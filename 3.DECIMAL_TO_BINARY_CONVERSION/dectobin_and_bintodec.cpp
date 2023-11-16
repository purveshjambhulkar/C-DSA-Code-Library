#include <iostream>
#include <cmath>
using namespace std;

// Function to convert decimal to binary and print the result
void dectobin(int dec);

// Function to convert binary to decimal and print the result
void bintodec(int bin);

int main()
{
    // Convert decimal to binary and print
    dectobin(5);

    // Convert binary to decimal and print
    bintodec(101);
}

void dectobin(int dec) {
    cout << "BINARY NUMBER IS" << endl;
    int bin = 0;
    int i = 0;
    
    while (dec > 0) {
        int bit = 1&dec; // Calculate the least significant bit
       
        bin =bin + (bit * pow(10 , i)); 
        
        dec = dec>>1; // Shift the decimal number to the right (equivalent to dec >> 1)
        i++;
    }
    
    cout << bin << endl;
}

void bintodec(int bin) {
    cout << "DECIMAL NUMBER IS" << endl;
    int dec = 0;
    int i = 0;
    
    while (bin > 0) {
        int dig = bin % 10; // Extract the rightmost digit
        bin = bin / 10; // Remove the rightmost digit
        if (dig == 1) {
            dec = dec + pow(2, i); // Calculate the decimal value
        }
        i++;
    }
    
    cout << dec << endl;
}
