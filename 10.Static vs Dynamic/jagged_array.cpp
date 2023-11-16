#include <iostream>
#include <vector>
using namespace std;

/*Jagged Array - A jagged array, also known as an array of arrays,
 is a type of array in which the elements are also arrays.
  Unlike a regular 2D array where all rows have the same number of columns,
   a jagged array allows each row to have a different number of columns.*/
int main()
{

   
    int rows;
    cout << "Enter the rows : ";
    cin >> rows;
     vector<int> size ;

    int **jag_arr = new int *[rows];

    cout << endl;

    // creating a jagged array
    for (int i = 0; i < rows; i++)
    {
        cout << "Enter the col for row no " << i + 1<<" : ";
        int col;
        cin >> col;
        size.push_back(col);
        jag_arr[i] = new int[col];
        cout << endl
             << "Initilizing the array\n";

        for (int j = 0; j < col; j++)
        {
            cin >> jag_arr[i][j];
        }
    }

    // Printing the jagged array

    cout<<endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
           cout<<jag_arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
