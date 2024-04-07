#include <iostream>
using namespace std;

int main() {
     
    struct node {
        int data;
        struct node * next;
        
    }

    node *top = NULL;

    int push(int data , node*top){

        node *temp = new node;
        temp->data = data;
        temp->next = top;
        top = temp;

    }

    int pop(node *top){
        int data = top.data;
        node *temp = new node;  
        temp = top;
        top = yop

    }

}