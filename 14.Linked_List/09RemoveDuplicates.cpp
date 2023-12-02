#include <iostream>
using namespace std;
#include <vector>

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

// for sorted linked list
void removeDuplicatesSorted(Node *head)
{

    Node *curr = head;
    Node *prev = NULL;

    if (head == NULL)
    {
        cout << "The List is Empty\n";
        return;
    }

    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            prev = curr;
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
}

// for unsorted linked list
void removeDuplicatesUnsorted(Node *head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty\n";
        return;
    }

    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr;

        while (curr != NULL)
        {
            Node *temp = curr;
            while (temp->next != NULL)
            {
                if (temp->next->data == curr->data)
                {
                    Node *duplicate = temp->next;
                    temp->next = temp->next->next;
                    delete duplicate;
                }
                else
                {
                    temp = temp->next;
                }
            }
            curr = curr->next;
        }
    }
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

    // for sorted linked list
    // InsertionAtTail(2, tail);
    // InsertionAtTail(2, tail);
    // InsertionAtTail(3, tail);
    // InsertionAtTail(3, tail);
    // InsertionAtTail(3, tail);
    // InsertionAtTail(4, tail);

    // for unsorted linked list
    InsertionAtTail(3, tail);
    InsertionAtTail(2, tail);
    InsertionAtTail(4, tail);
    InsertionAtTail(3, tail);
    InsertionAtTail(1, tail);
    InsertionAtTail(4, tail);

    cout << "List with Duplicates\n";
    print(head);

    cout << endl
         << "List without Duplicates\n";
    // removeDuplicatesSorted(head);
    removeDuplicatesUnsorted(head);

    print(head);
}