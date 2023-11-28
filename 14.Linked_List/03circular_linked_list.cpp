#include <iostream>
using namespace std;

// implementation of Circular(singly) Linked List

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

void insertionNode(Node *&tail, int element, int data)
{

    // if the list is empty
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
        return;
    }

    // insertion

    Node *temp = tail;
    while (temp->data != element)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node *&tail, int element)
{

    Node *prev = tail;
    Node *curr = prev->next;

    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    if (tail == curr)
    {
        tail = prev;
    }
    
    curr->next = NULL;
    delete curr;
}

void print(Node *&tail)
{

    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp->data != tail->data);

    cout << endl;
}

int main()
{

    Node *node1 = new Node(5);
    // Node *head = node1;
    Node *tail = node1;

    // insertion
    insertionNode(tail, 5, 10);
    insertionNode(tail, 10, 15);
    insertionNode(tail, 15, 20);
    insertionNode(tail, 10, 13);
    // cout << "Printing after insertion\n";
    // print(tail);//5 10 13 15 20

    deleteNode(tail, 5);
    cout << "Printing after deletion\n";
    print(tail);
}