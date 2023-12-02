#include <iostream>

using namespace std;

/*Floyd’s Cycle Detection Algorithm, often referred to
as the "tortoise and hare" algorithm, is a popular technique
used to detect cycles in a linked list or identify the presence
 of a cycle in constant space and with linear time complexity.*/

// Lets find whether the given linked list is circular or not

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

// FLOYD'S ALGORITHM

bool isCircular(Node *head) {
    if (head == nullptr || head->next == nullptr) {
        return false; // No cycle if no nodes or only one node
    }

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next; // Move slow pointer by one step
        fast = fast->next->next; // Move fast pointer by two steps

        if (slow == fast) {
            return true; // Cycle detected
        }
    }

    return false; // No cycle found
}

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

// function to insert at tail
void InsertionAtTail(int data, Node *&tail)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

int main()
{

    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;

    // insertion
    // insertionNode(tail, 5, 10);
    // insertionNode(tail, 10, 15);
    // insertionNode(tail, 15, 20);
    // insertionNode(tail, 10, 13);

     InsertionAtTail(25, tail);
    InsertionAtTail(35, tail);

    cout << "Checking whether Circular or Not\n";
    if (isCircular(head))
    {
        cout << "The given linked list is Circular\n";
    }
    else
    {
        cout << "The given linked list is not Circular\n";
    }
}