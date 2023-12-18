#include <iostream>
using namespace std;

/*Given two binary trees, the task is to find if both of them are identical or not.
Note: You need to return true or false, the printing is done by the driver code.*/

class Solution
{
public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // Your Code here
        if (r1 == NULL && r2 == NULL)
        {
            return true;
        }
        if (r1 != NULL && r2 == NULL)
        {
            return false;
        }
        if (r1 == NULL && r2 != NULL)
        {
            return false;
        }

        bool l = isIdentical(r1->left, r2->left);
        bool r = isIdentical(r1->right, r2->right);

        bool value = r1->data == r2->data;

        if (l && r && value)
        {

            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    return 0;
}