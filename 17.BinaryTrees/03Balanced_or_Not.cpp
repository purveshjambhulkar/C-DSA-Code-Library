#include <iostream>
using namespace std;

/*A tree is height balanced if difference between heights
of left and right subtrees is not more than one for all nodes of tree. */

class Solution
{
public:
    int height(struct Node *node)
    {
        // code here
        // base case
        if (node == NULL)
        {
            return 0;
        }

        int l = height(node->left);
        int r = height(node->right);

        if (l > r)
        {
            return (l + 1);
        }
        else if (l < r)
        {
            return (r + 1);
        }
        else
        {
            return (l + 1);
        }
    }
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here

        if (root == NULL)
        {
            return true;
        }

        bool l = isBalanced(root->left);
        bool r = isBalanced(root->right);

        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        if (l && r && diff)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{

    return 0;
}