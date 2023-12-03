/*Given two numbers represented by two linked lists of size N and M, The
task is to return a sum list,
The sum tist is a linked list representation of the addition of two
input numbers trom the*/

#include <iostream>
using namespace std;

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

/*****************************************************/
// Approach 1

int LengthLinkedList(Node *head)
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

Node *AddNum(Node *num1, Node *num2)
{

    if (num1 == NULL)
    {
        return num2;
    }

    if (num2 == NULL)
    {
        return num1;
    }

    Node *num1Curr = num1;
    Node *num1Prev = NULL;

    Node *num2Curr = num2;
    Node *num2Prev = NULL;

    int num1Length = LengthLinkedList(num1);
    int num2Length = LengthLinkedList(num2);

    if (num1Length > num2Length)
    {
        for (int i = 0; i < num1Length - num2Length; i++)
        {
            num1Prev = num1Curr;
            num1Curr = num1Curr->next;
        }

        for (int i = 0; i < num2Length; i++)
        {
            int Carry = 0;
            num1Curr->data = num1Curr->data + num2Curr->data;
            if (num1Curr->data >= 10)
            {
                int tempSum = num1Curr->data - 10;
                num1Curr->data = tempSum;
                Carry = 1;
                num1Prev->data = num1Prev->data + Carry;
            }
            num1Prev = num1Curr;
            num1Curr = num1Curr->next;
            num2Curr = num2Curr->next;
        }
        return num1;
    }
    else if (num1Length < num2Length)
    {
        for (int i = 0; i < num2Length - num1Length; i++)
        {
            num2Prev = num2Curr;
            num2Curr = num2Curr->next;
        }

        for (int i = 0; i < num1Length; i++)
        {
            int Carry = 0;
            num2Curr->data = num2Curr->data + num2Curr->data;
            if (num2Curr->data >= 10)
            {

                int tempSum = num2Curr->data - 10;
                num2Curr->data = tempSum;
                Carry = 1;
                num2Prev->data = num2Prev->data + Carry;
            }
            num2Prev = num2Curr;
            num2Curr = num2Curr->next;
            num1Curr = num1Curr->next;
        }
        return num2;
    }
    else if (num1Length == num2Length)
    {
        for (int i = 0; i < num1Length; i++)
        {
            int Carry = 0;
            num1Curr->data = num1Curr->data + num2Curr->data;

            if (num1Curr->data >= 10)
            {
                int tempSum = num1Curr->data - 10;
                num1Curr->data = tempSum;
                Carry = 1;
                num1Prev->data = num1Prev->data + Carry;
            }
            num2Curr = num2Curr->next;
            num1Curr = num1Curr->next;
        }
        return num1;
    }
}

/******************************************************/

// Approach 2
Node *reverse(Node *head)
{

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtTail(struct Node *&head, struct Node *&tail, int val)
{

    Node *temp = new Node(val);
    // empty list
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

struct Node *add(struct Node *first, struct Node *second)
{
    int carry = 0;

    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {

        int val1 = 0;
        if (first != NULL)
            val1 = first->data;

        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        // create node and add in answer Linked List
        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;
        if (first != NULL)
            first = first->next;

        if (second != NULL)
            second = second->next;
    }
    return ansHead;
}
struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    // step 1 -  reverse input LL
    first = reverse(first);
    second = reverse(second);

    // step2 - add 2 LL
    Node *ans = add(first, second);

    // step 3
    ans = reverse(ans);

    return ans;
}
/**********************************************************/
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
    // Num 1
    Node *node1 = new Node(1);
    Node *head1 = node1; // starting of the node
    Node *tail1 = node1; // ending of the node
    InsertionAtTail(1, tail1);
    InsertionAtTail(1, tail1);
    InsertionAtTail(6, tail1);
    cout << "Num1 : ";
    print(head1);
    cout << endl;

    // Num 2
    Node *node2 = new Node(4);
    Node *head2 = node2;
    Node *tail2 = node2;
    InsertionAtTail(4, tail2);
    // InsertionAtTail(1, tail2);
    // InsertionAtTail(1, tail2);
    cout << "Num2 : ";
    print(head2);
    cout << endl;

    Node *sum = AddNum(head1, head2);
    cout << "Sum : ";
    print(sum);
}