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

Node *ReverseKorder(Node *head, int k, int length)
{
    Node *link = NULL;
    Node *first = NULL;
    Node *NewHead = NULL;
    Node *curr = head;
    Node *forward = NULL;
    Node *prev = NULL;

    for (int i = 0; i < length / k; i++)
    {
        first = curr;
        for (int j = 0; j < k - 1; j++)
        {

            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            link = curr->next;
        }
        if (i == 0)
        {
            NewHead = curr;
        }
        first->next = link;
        link = NULL ;
        curr = curr->next;
        forward = NULL;
        prev = NULL;

        
    }
    return NewHead;
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

    Node *Newhead = ReverseKorder(head, orderK, length);
    print(Newhead);
}