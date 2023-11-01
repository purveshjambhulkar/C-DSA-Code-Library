#include <iostream>
using namespace std;

int main()
{
    int n = 5;
    int num = 5;
    int numx = 5;
    int j = 1;
    int row = 5;
    for (int i = 0; i < row; i++)
    {
        while (j <= n)
        {
            cout << j;
            j++;
        }
        j = 1;
        n--;
        while (j <= i)
        {
            cout << "**";
            j++;
        }
        j = 1;

        while (num)
        {
            cout << num;
            num--;
        }
        numx--;
        num = numx;

        cout<<"\n";
    }
}