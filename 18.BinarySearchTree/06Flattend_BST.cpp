// You have been given a Binary Search Tree (BST). Your task is to flatten the given BST to a sorted list. More formally, you have to make a right-skewed BST from the given BST, i.e., the left child of all the nodes must be NULL, and the value at the right child must be greater than the current node.



#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

//inorder traversal to store the nodes
void inOrderArr(TreeNode<int> *root, vector<int> &arr) {
    //base case
    if(root == NULL){
        return ;
    }

    //left
    inOrderArr(root->left, arr);

    //save Node
    arr.push_back(root->data);

    //right
    inOrderArr(root->right, arr);

}


TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> arr;
    inOrderArr(root, arr);

   TreeNode<int>* newRoot = new TreeNode<int>(arr[0]);
   TreeNode<int>* curr = newRoot;

   for (int i = 1; i < arr.size(); i++) {

       TreeNode<int>* temp = new TreeNode<int>(arr[i]);

       curr->left = NULL;
       curr->right = temp;
       curr = temp;
    }

    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}
