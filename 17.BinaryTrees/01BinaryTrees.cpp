#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Implementing Binary tree

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }
};

// function to create binary tree
node *buildTree(node *root)
{

    cout << "Enter the data : ";
    int data;
    cin >> data;
    root = new node(data);

    // base case
    if (data == -1)
    {
        return NULL;
    }

    // recursive approach for left
    cout << "Enter the data for the left of " << data << endl;
    root->left = buildTree(root->left);

    // recursive approach for right
    cout << "Enter the data for the right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
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

void InorderTraversal(node *root) // LNR
{

    // base case
    if (root == NULL)
    {
        return;
    }

    InorderTraversal(root->left);
    cout << root->data << " ";
    InorderTraversal(root->right);
}

void PreorderTraversal(node *root) // NLR
{

    // base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}
void PostorderTraversal(node *root) // LRN
{

    // base case
    if (root == NULL)
    {
        return;
    }

    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    cout << root->data << " ";
}

// Iterative Inorder Traversal
void iterativeInorderTraversal(node* root) {
    // Base case
    if (root == nullptr) {
        return;
    }

    stack<node*> s;
    node* current = root;

    while (current != nullptr || !s.empty()) {
        // Reach the left most node of the current node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = s.top();
        s.pop();
        cout << current->data << " ";

        // We have visited the node and its left subtree.
        // Now, it's right subtree's turn
        current = current->right;
    }
}

node *buildTreefromLevelOrder(node *root)
{

    queue<node *> q;
    cout << "Enter the data for the Root : ";
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        cout << "Enter left node for the " << temp->data << endl;
        int leftdata;
        cin >> leftdata;

        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter right node for the " << temp->data << endl;
        int rightdata;
        cin >> rightdata;

        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

// Count Leaf nodes
void inorderTraversalforLeafCount(node *root, int &count)
{

    // base case
    if (root == NULL)
    {
        return;
    }

    inorderTraversalforLeafCount(root->left, count);

    if (root->left == NULL && root->right == NULL)
    {
        count++;
    }

    inorderTraversalforLeafCount(root->right, count);
}
void countLeafnodes(node *root)
{
    int count = 0;
    inorderTraversalforLeafCount(root, count);
    cout << "Leaf node : " << count << endl;
}

int main()
{
    // creating the root node
    node *root = NULL;
    root = buildTree(root); // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout << endl;
    // cout << "Level Order Traversal\n";
    // levelOrderTraversal(root);
    // cout << endl;
    // cout << "Inorder Traversal\n";
    // InorderTraversal(root);
    // cout << endl;
    // cout << "Preorder Traversal\n";
    // PreorderTraversal(root);
    // cout << endl;
    // cout << "Postorder Traversal\n";
    // PostorderTraversal(root);
    // cout << endl;

    // buildTreefromLevelOrder(root); // 1 35 7 11 17 -1 -1 -1 -1 -1 -1 -1
    countLeafnodes(root);
}