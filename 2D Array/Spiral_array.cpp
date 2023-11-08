#include <iostream>
#include <vector>
using namespace std;

//Print the array in spiral form 
//Leetcode Question

int main(){
    int arr[3][3] = {{1,2,3} , {4,5,6} , {7,8,9}};
    int row = 3;
    int col = 3;
    int a = 0;

    int start_row = 0 ;
    int end_col = col-1;
    int end_row = row - 1;
    int start_col = 0;

    vector<int> ans;

    while (a < row*col)
    {
       for (int i = start_col ;a < row*col && i < col; i++)
       {
          ans.push_back(arr[start_row][i]);
          a++;
       }

       start_row++;

       for(int i = start_row ;a < row*col && i < row ; i++){
        ans.push_back(arr[i][end_col]);
        a++;
       } 

       end_col--;

       for(int i = end_col ;a < row*col && i >=0 ; i-- ){
        ans.push_back(arr[end_row][i]);
        a++;
       }

       end_row--;

       for(int i = end_row ; a < row*col && i <= start_row ; i++){
        ans.push_back(arr[i][start_col]);
        a++;
       } 

       start_col++;


       
    }

    for (int i = 0; i < 3; i++)
    {
       for (int j = 0; j < 3; j++)
       {
        cout<<arr[i][j]<<" ";

       }
       cout<<endl;
       
    }
    

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    


}