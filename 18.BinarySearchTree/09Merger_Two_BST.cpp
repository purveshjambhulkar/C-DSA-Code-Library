/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left),
right(right) {}
    };

*************************************************************/
// vector1.insert(vector1.end(), vector2.begin(), vector2.end());


//APPROACH 1 - USING INORDER 


void inOrder(TreeNode *root, vector<int> &arr) {
  // base case
  if (root == NULL) {
    return;
  }

  // left
  inOrder(root->left, arr);

  arr.push_back(root->data);

  // right
  inOrder(root->right, arr);
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2) {
  // Write your code here.                  
  vector<int> arr1;
  vector<int> arr2;

  inOrder(root1, arr1);
  inOrder(root2, arr2);

  arr1.insert(arr1.end(), arr2.begin(), arr2.end());

  sort(arr1.begin(), arr1.end());
  return arr1;
}