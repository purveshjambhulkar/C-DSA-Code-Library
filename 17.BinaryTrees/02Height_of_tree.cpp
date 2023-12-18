#include <iostream>
using namespace std;

// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
   
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        //base case 
        if(node == NULL){
            return 0;
        }
        
        int l = height(node->left);
        int r = height(node->right);
        
        if(l>r){
            return (l+1);
        }else if(l<r){
            return (r+1);
        }else{
            return (l+1);
        }
    }
};

 