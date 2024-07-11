#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
/*****************************************************************/
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {

            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
/*****************************************************************/
Node *xreate(Node *&root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (root->data > d)
    {
        root->left = xreate(root->left, d);
    }
    else
    {
        root->right = xreate(root->right, d);
    }

    return root;
}
void CreateBst(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        xreate(root, data);
        cin >> data;
    }
}
/*****************************************************************/
void InorderTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    // L
    InorderTraversal(root->left);

    // N
    cout << root->data << " ";

    // R
    InorderTraversal(root->right);
}

void PreorderTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    // N
    cout << root->data << " ";

    // L
    PreorderTraversal(root->left);

    // R
    PreorderTraversal(root->right);
}
void PostorderTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    // L
    PostorderTraversal(root->left);

    // R
    PostorderTraversal(root->right);

    // N
    cout << root->data << " ";
}

/*****************************************************************/
bool search(Node *root, int target)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    if (root->data > target)
    {
        return search(root->left, target);
    }
    else
    {
        return search(root->right, target);
    }
}

/*****************************************************************/
void DisplayLeafNodes(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                cout << temp->data << " ";
            }

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

/*****************************************************************/
Node *MinVal(Node *root)
{

    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
Node *MaxVal(Node *root)
{

    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

/*****************************************************************/
void InorderTraversalforPrecedence(Node *root, vector<int> &inordr)
{

    if (root == NULL)
    {
        return;
    }

    // L
    InorderTraversalforPrecedence(root->left, inordr);

    // N
    inordr.push_back(root->data);

    // R
    InorderTraversalforPrecedence(root->right, inordr);
}

int findInorderPrecedence(Node *root, int element)
{
    vector<int> inordr;
    InorderTraversalforPrecedence(root, inordr);
    for (int i = 0; i < inordr.size(); i++)
    {
        if (inordr[i] == element)
        {
            return inordr[i - 1];
        }
    }
}
/*****************************************************************/
void InorderTraversalforSuccessor(Node *root, vector<int> &inordr)
{

    if (root == NULL)
    {
        return;
    }

    // L
    InorderTraversalforSuccessor(root->left, inordr);

    // N
    inordr.push_back(root->data);

    // R
    InorderTraversalforSuccessor(root->right, inordr);
}

int findInorderSuccessor(Node *root, int element)
{
    vector<int> inordr;
    InorderTraversalforSuccessor(root, inordr);
    for (int i = 0; i < inordr.size(); i++)
    {
        if (inordr[i] == element)
        {
            return inordr[i + 1];
        }
    }
}

/*****************************************************************/

Node *deletefromBST(Node *root, int element)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == element)
    {
        // No Child
        if (root->left == NULL && root->right == NULL)
        {
            Node *temp = root;
            delete root;
            return temp;
        }

        // 1 child

        // Right child
        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Left child
        if (root->right == NULL && root->left != NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int min = MinVal(root->right)->data;
            root->data = min;
            root->right = deletefromBST(root->right, element);
            return root;
        }
    }
    else if (root->data > element)
    {
        root->left = deletefromBST(root->left, element);
        return root;
    }
    else
    {
        root->right = deletefromBST(root->right, element);
        return root;
    }
}
/*****************************************************************/

int main()
{
    Node *root = NULL;
    cout << "Enter data to create BST\n";
    CreateBst(root);

    cout << "Printing Level Order Traversal\n";
    levelOrderTraversal(root);
    cout << endl;

    // cout << "Inorder Traversal\n";
    // InorderTraversal(root);
    // cout << endl;

    // cout << "Preorder Traversal\n";
    // PreorderTraversal(root);
    // cout << endl;

    // cout << "Postorder Traversal\n";
    // PostorderTraversal(root);
    // cout << endl;

    // int target;
    // cout << "Enter element you want to search : ";
    // cin >> target;
    // if (search(root, target))
    // {
    //     cout << "Target Found" << endl;
    // }
    // else
    // {
    //     cout << "Target not found" << endl;
    // }

    // cout << "Displaying the Leaf Nodes\n";
    // DisplayLeafNodes(root);
    // cout << endl;

    // Node *Max = MaxVal(root);
    // Node *Min = MinVal(root);

    // cout << "Max : " << Max->data << endl;
    // cout << "Min : " << Min->data << endl;

    // cout << "Enter the element of which you want to find Inorder Precedence : ";
    // int element1;
    // cin >> element1;
    // int ans1 = findInorderPrecedence(root, element1);
    // cout << "InorderPrecedence : " << ans1 << endl;

    // cout << "Enter the element of which you want to find Inorder Successor : ";
 
    // cin >> element2;
    // int ans2 = findInorderSuccessor(root, element2);
    // cout << "InorderSuccessor : " << ans2 << endl;

    cout << endl;
    cout << "Enter the element you want to delete from the BST : ";
    int ele;
    cin >> ele;
    Node *del = deletefromBST(root, ele);
    cout << "The deleted Node was " << del->data << endl;
    cout << endl;

    cout << "Printing Level Order Traversal\n";
    levelOrderTraversal(root);
    cout << endl;
}
