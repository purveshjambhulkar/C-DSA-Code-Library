#include <iostream>
#include <vector>
using namespace std;

//Rotate matrix by 90 degree
//Leetcode question

void rotate(vector<vector<int>>& matrix) {

      

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> arr;
        

        for(int i = 0 ; i < col ; i++){

            vector<int> newrow;

            for(int j = row - 1 ; j >= 0 ; j--){
                newrow.push_back(matrix[j][i]);

            }
            arr.push_back(newrow);
        }

        matrix = arr;

        
    }

void print_matrix(vector<vector<int>>& matrix){
    int row = matrix.size();
    int col = matrix[0].size();

    for (int i = 0; i < row; i++)
    {
       for (int j = 0; j < col ;j++)
       {
           cout<<matrix[i][j]<<" ";
       }
       cout<<endl;
       
    }
    
}


int main(){
    vector<vector<int>> arr = {{1,2,3} ,{4,5,6} ,{7,8,9}};
    
    rotate(arr);
    print_matrix(arr);

 
    
}
