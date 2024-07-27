/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/

//inorder Traversal
void inOrderArr(TreeNode<int> *root,vector<int> &arr ) {
    //base case
    if (root == NULL) {
        return;
    }

    //left
    inOrderArr(root->left, arr);

    //save
    arr.push_back(root->data);

    //right
    inOrderArr(root->right , arr);

}

TreeNode<int>* inOrderTOBSt(int s , int e , vector<int> arr){
    //base case
    if(s>e){
        return NULL;
     }

     int mid = (s+e)/2;

     TreeNode<int>* newNode = new TreeNode<int>(arr[mid]);
     newNode->left = inOrderTOBSt(s, mid-1, arr);
     newNode->right = inOrderTOBSt(mid+1, e, arr);

    return newNode;

}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> arr;
    inOrderArr(root , arr);

    return inOrderTOBSt(0, arr.size()-1, arr);


}
