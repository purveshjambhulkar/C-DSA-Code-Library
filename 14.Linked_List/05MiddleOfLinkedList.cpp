#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

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

Node *findMiddle(Node *&head)
{
    Node *start = head;
    Node *anser = NULL;
    int lenght = LengthLinkedList(head);
    int mid = 0;

    if (lenght % 2 == 0)
    {
        mid = (lenght / 2);
        for (int i = 0; i < mid; i++)
        {
            start = start->next;
        }
        anser = start;
        cout << "Middle Node : " << anser->data << endl;
        return anser;
    }
    else
    {
        mid = lenght / 2;
        for (int i = 0; i < mid; i++)
        {
            start = start->next;
        }
        anser = start;
        cout << "Middle Node : " << anser->data << endl;
        return anser;
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
    Node *even = new Node(10);
    Node *headEven = even;
    Node *tailEven = even;

    Node *odd = new Node(10);
    Node *tailOdd = odd;
    Node *headOdd = odd;

    Node *MiddleODDNode = NULL;
    Node *MiddleEVENNode = NULL;

    // Initializing Even Linked List
    InsertionAtTail(20, tailEven);
    InsertionAtTail(30, tailEven);
    InsertionAtTail(40, tailEven);
    InsertionAtTail(50, tailEven);
    InsertionAtTail(60, tailEven);

    // Initializing Odd Linked List
    InsertionAtTail(20, tailOdd);
    InsertionAtTail(30, tailOdd);
    InsertionAtTail(40, tailOdd);
    InsertionAtTail(50, tailOdd);

    cout << "Finding the middle of the Even Linked List\n";
    MiddleEVENNode = findMiddle(headEven);

    cout << "Finding the middle of the Odd Linked List\n";
    MiddleODDNode = findMiddle(headOdd);
}