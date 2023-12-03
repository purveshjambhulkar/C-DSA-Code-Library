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
/***************************************************************/
// Approach 1
bool isPalindrome1(Node *head)
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
/*********************************************************************/
// Approach 2
Node *getMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
bool isPalindrome2(Node *head)
{

    Node *Middle = getMiddle(head);

    Node *temp = Middle->next;

    Middle->next = reverse(temp);

    Node *firstHalf = head;
    Node *secondHalf = Middle->next;

    while (secondHalf->next != NULL)
    {
        if (firstHalf->data != secondHalf->data)
        {
            return false;
        }

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }


    return true;
}
/****************************************************/
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

    if (isPalindrome2(head))
    {
        cout << "Palindrome\n";
    }
    else
    {
        cout << "Not Palindrome\n";
    }
}