//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  
  
    bool isSafe(int row , int col ,vector<vector<int>> &visited ,vector<vector<int>> &mat , int n ){
        if(row >= 0 && row < n && col >=0 && col < n && !visited[row][col] && mat[row][col]){
            return true;
        }else {
            return false;
        }
    }
  
    void solve(int row , int col ,int n,vector<string> &ans , vector<vector<int>> &visited , string &path ,vector<vector<int>> &mat ){
        //base case
        if(row == n-1 && col == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[row][col] = 1;
        
        //down movement
        string newPath = path + 'D';
        if(isSafe(row +1 , col , visited , mat , n)){
            solve(row + 1 , col , n , ans , visited , newPath, mat);
        }
        //up movement
          newPath = path + 'U'; 
        if(isSafe(row - 1 , col , visited , mat , n)){
            solve(row - 1 , col , n , ans , visited ,newPath, mat);
        }
        //right movement
         newPath = path + 'R';
        if(isSafe(row , col + 1 , visited , mat , n)){
            solve(row  , col + 1  , n , ans , visited , newPath , mat);
        }
        //left movement
        newPath = path + 'L';
        if(isSafe(row  , col - 1 , visited , mat , n)){
            solve(row , col - 1 , n , ans , visited ,newPath , mat);
        }
        
          visited[row][col] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string> ans;
        string path = "";
        int n = mat.size();
        if(mat[0][0] == 0){
            return ans;
        }
       vector<vector<int>> visited(n , vector<int>(n , 0));
        solve(0 , 0 ,n,ans , visited , path , mat);
        return ans;
        
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends