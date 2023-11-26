#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void InsertionAtHead(Node *&head, int data)
{

    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertionAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void InsertionAtPosition(Node *&head, Node *&tail, int data, int position)
{

    if (position == 1)
    {
        InsertionAtHead(head, data);
        return;
    }

    Node *temp1 = head;
    int count = 1;
    while (count < position - 1)
    {
        temp1 = temp1->next;
        count++;
    }

    if (temp1->next == NULL)
    {
        InsertionAtTail(tail, data);
        return;
    }

    Node *temp2 = temp1;
    temp2 = temp2->next;

    // temp1 = previous node
    // temp2 = next node

    // creating a new node
    Node *NodeTObeInserted = new Node(data);
    temp1->next = NodeTObeInserted;
    NodeTObeInserted->prev = temp1;
    NodeTObeInserted->next = temp2;
    temp2->prev = NodeTObeInserted;
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    // cout<<head->data ;
    //  print(head);

    // InsertionAtHead(head , 15);
    // print(head);
    // cout<<"Head : "<<head->data<<endl;
    // cout<<"Tail : "<<tail->data<<endl;

    InsertionAtTail(tail, 15);
    InsertionAtTail(tail, 20);
    cout << "Printing after insertion at Tail\n";
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    cout << endl;

    InsertionAtPosition(head, tail, 99, 4);
    cout << "Printing after insertion at Position\n";
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    cout << endl;

}