#include <iostream>
#include <map>
using namespace std;

// Detecting whether loop is present or not

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

Node *getStartingLoopNode(Node *head);

// FUNCTION TO DETECT THE LOOP - USING FLOYDS ALGORITHM
Node * detectLoop(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "LOOP NOT DETECTED\n";
        return NULL;
    }

    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // cout << "Loop start at : " << slow->data << endl;
            // cout << "LOOP DETECTED\n";
            return slow;
        }
    }

    // cout << "LOOP NOT DETECTED\n";
    return slow;
}

void removeLoop(Node *head){

    Node *startingLoopNode = getStartingLoopNode(head);
    Node *temp = startingLoopNode ;

    while (temp->next == startingLoopNode )
    {
        temp = temp->next ;
    }
    
    temp->next = NULL;
}

Node *getStartingLoopNode(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        cout << "LOOP NOT DETECTED\n";
        return NULL;
    }

    Node *intersection = detectLoop(head);
    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void print(Node *&head)
{
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{

    Node *node1 = new Node(1);
    Node *head = node1;
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    Node *node5 = new Node(5);

    // Looped Linked List
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;

    // Non-Looped Linked List
    //  node1->next = node2;
    //  node2->next = node3;
    //  node3->next = node4;

    detectLoop(head);
    

    Node *LoopStart = getStartingLoopNode(head);
    cout<<LoopStart->data<<endl;
    // print(head);

    removeLoop(head);
    print(head); //print the linked list without loop
}