//To find whether the sum of any two nodes is equal to the target or not


#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
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
***************/

void inOrderArr(BinaryTreeNode<int> *root, int target, vector<int> &arr) {
    //base case
    if (root == NULL) {
        return;
    }

    //left
    inOrderArr(root->left, target, arr);

    //save
    arr.push_back(root->data);

    //right
    inOrderArr(root->right, target, arr);   

}


//approach 1 - time limit exceeded
// bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
// 	//Write your code here
//         if (root == NULL) {
        
//         return false;
//         }
//     vector<int> arr;
//     inOrderArr(root, target, arr);

//     for (int i = 0; i < arr.size(); i++) {
        
//         for (int j = i + 1; j < arr.size(); j++) {
//           if (arr[i] + arr[j] == target) {
//               return true;
//           }
//         }
//     }

//     return false;
// }

//approach 2 
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
        if (root == NULL) {
        
        return false;
        }
    vector<int> arr;
    inOrderArr(root, target, arr);

        int i = 0 ; 
        int j = arr.size() - 1;
    while (i<j) {

        if(arr[i] + arr[j] == target){
            return true;
        }else if(arr[i] + arr[j] > target){
            j--;
        } else {
            i++; //condition when sum is less than the target
        }
    }

    return false;
}