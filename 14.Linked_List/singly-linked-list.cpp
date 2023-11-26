#include <iostream>
using namespace std;

// Implemeting Singly Linked List

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
// function to find the length (will define later)
int Length_linkedlist(Node *&head);

// function to head at head
void InsertionAtHead(int data, Node *&head)
{

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

// function to insert at tail
void InsertionAtTail(int data, Node *&tail)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// function to insert a given position
void InsertionAtPositon(int position, int data, Node *&head, Node *&tail)
{

    if (position == 1)
    {
        InsertionAtHead(data, head);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // if (position == Length_linkedlist(head))   //AMBIGUITY//
    // {
    //     InsertionAtTail(data ,tail);
    //     return;
    // }

    // OR
    // if the element is to be addded at last position
    if (temp->next == NULL)
    {
        InsertionAtTail(data, tail);
        return;
    }

    Node *NodeToBeInserted = new Node(data);
    NodeToBeInserted->next = temp->next;
    temp->next = NodeToBeInserted;
}

// deletion of first element (head)
void deleteHead(Node *&head)
{
    Node *temp = head;
    temp = temp->next;
    delete head;
    head = temp;
}

// deletion of last element (tail)
void deleteTail(Node *&tail, Node *&head)
{
    Node *temp = head;
    while (true)
    {
        if (temp->next == tail)
        {
            break;
        }

        temp = temp->next;
    }
    delete tail ;
    tail = temp;
    tail->next = NULL;
    
}

void deletetionAtPosition(int position, Node *&head, Node *&tail)
{
    // delete at position 1 - head
    if (position == 1)
    {
        deleteHead(head);
        return;
    }

    Node *temp1 = head;
    // Node *mid = head;
    Node *temp2 = head;
    int count = 1;
    while (count < position - 1)
    {
        temp1 = temp1->next;
        count++;
    }

    // deletion at last position - tail
    if (temp1->next == NULL)
    {
        deleteTail(tail, head);
        return;
    }

    // deletion for other position
    temp2 = temp1;
    // mid = temp1 ;
    // mid = mid->next ;
    temp2 = temp2->next;
    temp2 = temp2->next;

    temp1->next = temp2;
}

// defining the function to calculate length of linked list
int Length_linkedlist(Node *&head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }

    return length;
}

// function to iterate and print the linked list
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

    Node *node1 = new Node(10);
    Node *head = node1; // starting of the node
    Node *tail = node1; // ending of the node

    // InsertionAtHead(15 , head);

    InsertionAtTail(25, tail);
    InsertionAtTail(35, tail);
    cout << "Printing after insertion in Tail\n";
    print(head);
    InsertionAtPositon(4, 99, head, tail);
    cout << "Printing afheter insertion in Position\n";
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;

    // cout << endl;
    // deleteHead(head);
    cout << "Printing after deleting head\n";
    // print(head);
    // cout << "head : " << head->data << endl;
    // cout << "tail : " << tail->data << endl;

    // deleteTail(tail, head);
    // cout << "Printing after deleting tail\n";
    // print(head);
    // cout << "head : " << head->data << endl;
    // cout << "tail : " << tail->data << endl;

    deletetionAtPosition(4, head, tail);
    print(head);
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
}