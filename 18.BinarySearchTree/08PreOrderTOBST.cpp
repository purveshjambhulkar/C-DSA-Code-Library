#include <bits/stdc++.h>
/*
    Following is the class structure of BinaryTreeNode class for referance:

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

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/

// APPROACH1 - USING INORDER TO BST -  BEST APPROACH

// inorder
BinaryTreeNode<int> *inToBST(int s, int e, vector<int> inArr) {
  // base case
  if (s > e) {
    return NULL;
  }

  // find mid
  int mid = (s + e) / 2;

  // create rootNode
  BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(inArr[mid]);

  // left
  newNode->left = inToBST(s, mid - 1, inArr);

  // right
  newNode->right = inToBST(mid + 1, e, inArr);

  return newNode;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder) {
  // Write your code here.

  sort(preorder.begin(), preorder.end());

  return inToBST(0, preorder.size() - 1, preorder);
}

// APPROACH 2 --NOT MUch efficient

// BinaryTreeNode<int> *SOLVE(vector<int> preorder, int mini, int maxi, int &i) {
//   // base case
//   if (i >= preorder.size()) {
//     return NULL;
//   }

//   if (preorder[i] < mini || preorder[i] > maxi) {
//     return NULL;
//   }

//   // create node
//   BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(preorder[i++]);
//   newNode->left = SOLVE(preorder, mini, newNode->data, i);
//   newNode->right = SOLVE(preorder, newNode->data, maxi, i);
//   return newNode;
// }

// BinaryTreeNode<int> *preorderToBST(vector<int> &preorder) {
//   // Write your code here.
//   int mini = INT_MIN;
//   int maxi = INT_MAX;
//   int i = 0;

//   return SOLVE(preorder, mini, maxi, i);
// }