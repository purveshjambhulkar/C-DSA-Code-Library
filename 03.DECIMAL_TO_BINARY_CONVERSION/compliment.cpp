#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1; // Special case: the complement of 0 is 1
        }

        int bin1 = dectobin(n);
        int bin2 = 0;
        int i = 0;

        while (bin1 != 0) {
            int dig = bin1 % 10;
            bin1 = bin1 / 10;
            if (dig == 0) {
                bin2 = (1 * pow(10, i)) + bin2;
            }
            else {
                bin2 = (0 * pow(10, i)) + bin2;
            }
            i++;
        }

        int dec = bintodec(bin2);
        cout << dec;
        return dec;
    }

    int dectobin(int dec) {
        cout << "BINARY NUMBER IS\n";
        int bin = 0;
        int i = 0;
        while (dec != 0) {
            int bit = dec % 2;
            bin = (bin * 10) + bit;
            dec = dec / 2;
            i++;
        }
        return bin;
    }

    int bintodec(int bin) {
        cout << "DECIMAL NUMBER IS\n";
        int dec = 0;
        int i = 0;
        while (bin != 0) {
            int dig = bin % 10;
            bin = bin / 10;
            if (dig == 1) {
                dec = dec + pow(2, i);
            }
            i++;
        }
        return dec;
    }
};

int main() {
    Solution si;
    si.bitwiseComplement(5);
}
