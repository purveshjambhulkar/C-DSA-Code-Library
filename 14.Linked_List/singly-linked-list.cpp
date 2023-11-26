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
//function to find the length (will define later)
int Length_linkedlist(Node* &head);

//function to head at head
void InsertionAtHead(int data, Node *&head)
{

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

//function to insert at tail
void InsertionAtTail(int data, Node *&tail)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

//function to insert a given position
void InsertionAtPositon(int position , int data , Node* &head , Node* &tail){


    Node* temp = head ; 
    int count = 1 ;

    if (position == 1)
    {
        InsertionAtHead(data , head);
    }

    if (position == Length_linkedlist(head))
    {
        InsertionAtTail(data ,tail);
    }
    
    

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    Node* NodeToBeInserted =  new Node(data);
    NodeToBeInserted->next = temp->next;
    temp->next = NodeToBeInserted;    
    

}

//defining the function to calculate length of linked list
int Length_linkedlist(Node* &head){
    int length = 0;
    Node* temp = head ;
    while (temp != NULL)
    {
        temp = temp->next ;
        length++;
    }

    return length ; 
    
}

//function to iterate and print the linked list
void print(Node *&head )
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
    
    
    //InsertionAtHead(15 , head);
    

    InsertionAtTail(25, tail);
    InsertionAtTail(35, tail);
    cout<<"Printing after insertion in Tial\n";
    print(head );
    InsertionAtPositon(3 , 99 , head , tail);
    cout<<"Printing after insertion in Position\n";
    print(head );
    

}