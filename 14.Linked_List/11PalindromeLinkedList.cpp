#include <iostream>
#include <vector>
using namespace std;

// TO CHECK WHETHER THE GIVEN LINKED LIST IS PALINDROME OR NOT

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool isPalindrome(Node *head)
{
    Node *start = head;
    vector<int> palindrome;
    while (start != NULL)
    {
        palindrome.push_back(start->data);
        start = start->next;
    }

    int begin = 0;
    int end = palindrome.size() - 1;

    while (begin <= end)
    {
        if (palindrome[begin] != palindrome[end])
        {
            return false;
        }
        begin++;
        end--;
    }

    return true;
}

void InsertionAtTail(int data, Node *&tail)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{

    Node *node1 = new Node(1);
    Node *head = node1; // starting of the node
    Node *tail = node1; // ending of the node

    InsertionAtTail(0, tail);
    InsertionAtTail(2, tail);
    InsertionAtTail(2, tail);
    InsertionAtTail(0, tail);
    InsertionAtTail(1, tail);

    print(head);

    if (isPalindrome(head))
    {
        cout << "Palindrome\n";
    }
    else
    {
        cout << "Not Palindrome\n";
    }
}