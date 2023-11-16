#include <iostream>
#include <vector>
using namespace std;

int saynum(int x, string str[])
{

    if (x == 0)
    {
        return 1;
    }

    int dig = x % 10;
    x = x / 10;

    saynum(x, str);
    cout << str[dig] << " ";
}

int main()
{
    string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int num = 143;
    cout << "all ok" << endl;

    saynum(num, str);
}