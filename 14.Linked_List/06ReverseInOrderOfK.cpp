#include <iostream>
using namespace std;

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

// Node *ReveseLinkedList(Node *head)
// {
//     Node *prev = NULL;
//     Node *curr = head;
//     Node *forward = NULL;

//     while (curr != NULL)
//     {
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     cout << "Head of the reversed Linked list is : " << prev->data << endl;
//     return prev;
// }

Node *RevKorder(Node *&head, int k)
{
    // base case
    if (head == NULL)
    {
        return NULL;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    int count = 0;
        
    // processing
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // recursive call
    if (next != NULL)
    {
        head->next = RevKorder(next, k);
    }

    return prev;
}

int LengthLinkedList(Node *&head)
{
    Node *start = head;
    int lenght = 0;

    while (start != NULL)
    {
        lenght++;
        start = start->next;
    }
    return lenght;
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

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    InsertionAtTail(20, tail);
    InsertionAtTail(30, tail);
    InsertionAtTail(40, tail);
    InsertionAtTail(50, tail);
    InsertionAtTail(60, tail);
    // print(head);

    int orderK = 2;
    int length = LengthLinkedList(head);

    Node *Newhead = RevKorder(head, orderK);
    print(Newhead);
}