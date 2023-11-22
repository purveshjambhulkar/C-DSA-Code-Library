#include <iostream>
#include <vector>
using namespace std ;

class Solution {

private :
    void solve(vector<int>& nums ,vector<int> output, int index,vector<vector<int>> &ans ) {
        //base case 
        if(index >= nums.size()){
            ans.push_back(output);
            return ;
        }

        //exclude

        solve(nums  , output , index+1 , ans);

        int element = nums[index] ;
        output.push_back(element);
        solve(nums , output , index+1 , ans);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> output;
        int index = 0 ; 
        solve(nums , output , index , ans);
        return ans ;     }
};



int main(){
    Solution s1 ; 
    vector<int> nums = {1,2,3};
    cout<<"The subsets are : "<<endl;
    vector<vector<int>> ans = s1.subsets(nums);
    for(vector<int> i : ans){
        cout<<"[";
        for(int j : i){
            
            cout<<j;
            if (i.size() == 1)
            {
                break;
            }
            cout<<",";
            
            
        }
        cout<<"]";
        cout<<endl;

    }
   

}