
//  Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 }
class Solution {
public:
    pair<bool, int> isBalancedOP(TreeNode* root) {

        if (root == nullptr) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> leftPair = isBalancedOP(root->left);
        pair<bool, int> rightPair = isBalancedOP(root->right);

        bool leftanser = leftPair.first;
        bool rightanser = rightPair.first;

        bool diff = abs(leftPair.second - rightPair.second) <= 1;

        pair<bool, int> Ans;
        Ans.second = max(leftPair.second, rightPair.second) + 1;

        if (leftanser && rightanser && diff) {
            Ans.first = true;

        } else {
            Ans.first = false;
        }

        return Ans;
    };

    bool isBalanced(TreeNode* root) {

        return isBalancedOP(root).first;
    }
};