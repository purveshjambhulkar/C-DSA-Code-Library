#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void inOrderTraversal(BinaryTreeNode<int> *root , vector<int> &arr) {

    //base case
    if (root == NULL) {
        return ;
    }

    //recursive call
    inOrderTraversal(root->left , arr);

    arr.push_back(root->data);

    inOrderTraversal(root->right, arr);


}

bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<int> arr;
    inOrderTraversal(root , arr);

    return is_sorted(arr.begin(), arr.end());
}