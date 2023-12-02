#include <iostream>
using namespace std;

// Sort 0s 1s 2s

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

void sort(Node *head)
{
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            count0++;
        }
        else if (curr->data == 1)
        {
            count1++;
        }
        else if (curr->data == 2)
        {
            count2++;
        }
        curr = curr->next;
    }

    curr = head;

    for (int i = 0; i < count0; i++)
    {
        curr->data = 0;
        curr = curr->next;
    }
    for (int i = 0; i < count1; i++)
    {
        curr->data = 1;
        curr = curr->next;
    }
    for (int i = 0; i < count2; i++)
    {
        curr->data = 2;
        curr = curr->next;
    }
}

void InsertionAtTail(int data, Node *&tail)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
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
    InsertionAtTail(1, tail);
    InsertionAtTail(0, tail);
    InsertionAtTail(2, tail);
    cout << "Before Sorting\n";
    print(head);
    sort(head);
    cout << "After Sorting\n";
    print(head);
}