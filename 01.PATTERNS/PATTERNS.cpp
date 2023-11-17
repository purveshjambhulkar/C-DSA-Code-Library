#include <iostream>
using namespace std;

int main()
{
    // THIS IS PROGRAM TO PRINT STAR PATTERNS
    cout << "1>> PRINTING 5X5 STAR PATTERN\n";
    for (int j = 0; j < 5; j++)
    {
        for (int l = 0; l < 5; l++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
    cout << "\n"
         << endl;

    // next pattern
    cout << "2>>PRINTING NUMBERS PATTERN \n";
    int num = 1;
    for (int q = 0; q < 3; q++)
    {
        for (int w = 0; w < 3; w++)
        {
            cout << num << " ";
        }
        num++;
        cout << "\n";
    }
    cout << "\n"
         << endl;

    // another pattern
    cout << "3>> PRINTING ANOTHER NUMBERS PATTERN\n";
    int num2 = 1;
    for (int e = 0; e < 4; e++)
    {
        for (int r = 0; r < 3; r++)
        {
            cout << num2 << " ";
            num2++;
        }
        cout << "\n";
        num2 = 1;
    }
    cout << "\n"
         << endl;

    // another pattern
    cout << "4>> PRINTING ANOTHER NUMBER PATTERN\n";
    int num3 = 1;
    for (int r = 0; r < 3; r++)
    {
        for (int t = 0; t < 3; t++)
        {
            cout << num3 << " ";
            num3++;
        }
        cout << "\n";
    }
    cout << "\n"
         << endl;

    // another star pattern
    cout << "5>> PRINTING ANOTHER STAR PATTERN\n";
    for (int y = 0; y < 4; y++)
    {
        for (int u = 0; u <= y; u++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    cout << "\n"
         << endl;

    // another pattern
    // 1
    // 22
    // 333
    // 4444
    cout << "6>> PRINTING ANOTHER NUMBER PATTERN\n";
    int num4 = 1;
    for (int o = 0; o < 4; o++)
    {
        for (int p = 0; p <= o; p++)
        {
            cout << num4;
        }
        num4++;
        cout << "\n";
    }
    cout << "\n"
         << endl;

    // another pattern
    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    cout << "7>> PRINTING ANOTHER NUMBER PATTERN\n";
    int num5 = 1;
    for (int a = 0; a < 4; a++)
    {
        for (int s = 0; s <= a; s++)
        {
            cout << num5 << " ";
            num5++;
        }
        cout << "\n";
    }
    cout << "\n"
         << endl;

    // another pattern
    // 1
    // 23
    // 345
    // 4567
    cout << "8>> PRINTING ANOTHER NUMBER PATTERN\n";
    int num6 = 1;
    int num6a = 1;
    for (int d = 1; d < 5; d++)
    {
        for (int f = 1; f <= d; f++)
        {
            cout << num6 << " ";
            num6++;
        }

        num6a++;
        num6 = num6a;
        cout << "\n";
    }

    cout << "\n"
         << endl;

    // another pattern
    // 1
    // 21
    // 321
    // 4321
    cout << "9>> PRINTING ANOTHER NUMBER PATTERN\n";
    int num7 = 1;
    int num7a = 1;
    for (int g = 0; g < 4; g++)
    {
        for (int h = 0; h <= g; h++)
        {
            cout << num7 << " ";
            num7--;
        }
        num7a++;
        num7 = num7a;
        cout << "\n";
    }
    cout << "\n"
         << endl;

    // another pattern
    cout << "10>> PRINTING PATTERN OF ALPHABETS\n";
    char ch = 'A';
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ch << " ";
        }
        ch++;
        cout << "\n";
    }

    cout << "\n"
         << endl;

    // another pattern
    ch = 'A';
    cout << "11>> PRINTING ANOTHER PATTERN\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ch << " ";
            ch++;
        }
        ch = 'A';
        cout << "\n";
    }
    cout << "\n"
         << endl;

    // another pattern
    ch = 'A';
    cout << "12>> PRINTING ANOTHER PATTERN\n";
    for (int a = 0; a < 4; a++)
    {
        for (int s = 0; s <= a; s++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << "\n";
    }
    cout << "\n"
         << endl;

    // another pattern
    ch = 'A';
    cout << "13>> PRINTING ANOTHER PATTERN\n";
    for (int o = 0; o < 4; o++)
    {
        for (int p = 0; p <= o; p++)
        {
            cout << ch;
        }
        ch++;
        cout << "\n";
    }
    cout << "\n"
         << endl;

    // another pattern
    ch = 'A';
    char ch1 = 'A';
    cout << "14>> PRINTING ANOTHER PATTERN\n";
    for (int d = 1; d < 5; d++)
    {
        for (int f = 1; f <= d; f++)
        {
            cout << ch << " ";
            ch++;
        }

        ch1++;
        ch = ch1;
        cout << "\n";
    }

    cout << "\n"
         << endl;

    // printing another pattern
    ch = 'D';
    ch1 = 'D';
    cout << "15>> PRINTING ANOTHER PATTERN\n";
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        ch1--;
        ch = ch1;
        cout << "\n";
    }

    cout << "\n"
         << endl;

    // printing another pattern

    cout << "16>> PRINTING ANOTHER PATTERN\n";
    int q = 3;
    int w = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << " ";
        }
        q--;
        for (int m = 1; m <= w; m++)
        {
            cout << "*";
        }
        w++;
        cout << "\n";
    }

    cout << "\n"
         << endl;

    // printing another pattern

    cout << "17>> PRINTING ANOTHER PATTERN\n";
    int n = 4;
    int n1 = 3;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <n1; j++)
        {
            cout<<" ";
            n1--;

        }
        int z = 0;
        while(z<=i)
        {
            cout<<z+1;
            z++;
        }
        int c = 1;
         while(c<=i){
            cout<<c;
            c++;
         }

         cout<<"\n";

        
        
    }
    
    
  
}