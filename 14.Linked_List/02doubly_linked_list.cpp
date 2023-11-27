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
    // if the list is emplty i.e no nodes

    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
    }

    Node *temp = new Node(data);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertionAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
    }
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
        InsertionAtTail(head, tail, data);
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

void deletionAtHead(Node *&head, Node *&tail)
{

    // if only one node
    if (head == tail)
    {
        delete head;
        return;
    }

    Node *temp = head;

    temp = temp->next;
    temp->prev = NULL;
    delete head;
    head = temp;
}

void deletionAtPosition(Node *&head, Node *&tail, int position)
{
    //delete node at first position
    if (position == 1)
    {
        deletionAtHead(head ,tail);
        return;
    }

    // deleting the node at ay position or last

    Node *curr = head;
    Node *prev = NULL;

    int count = 1;
    while (count <= position - 1)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    prev->next = curr->next;

    // check whether the curr is tail
    if (curr->next == NULL)
    {
        delete tail;
        tail = prev;
        return;
    }
    else
    { // if not tail
        curr->next = NULL;
        delete curr;
    }
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

    InsertionAtTail(head, tail, 15);
    InsertionAtTail(head, tail, 20);
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

    // deletionAtHead(head, tail);
    // cout << "Printing after deleting at Head\n";
    // print(head);
    // cout << "Head : " << head->data << endl;
    // cout << "Tail : " << tail->data << endl;
    // cout << endl;

    int position = 1 ;
    deletionAtPosition(head , tail , position);
    cout<<"Printing after deletion at Position : "<<position<<endl;
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    cout << endl;
}
