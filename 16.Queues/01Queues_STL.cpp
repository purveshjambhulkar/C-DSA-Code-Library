#include <iostream>
#include <queue>
using namespace std;

// QUEUE - STL [FIRST IN FIRST OUT]

int main()
{

    queue<int> q;

    // adding elements to the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    // removing element from the queue
    // i.e popping first element
    q.pop();

    // printing the size of the array
    cout << "size : " << q.size() << endl;

    // checking if queue is empty or not
    if (q.empty())
    {
        cout << "Queue is Empty\n";
    }
    else
    {
        cout << "Queue is Not Empty\n";
    }

    // printing the First element of the Queue
    cout << "First : " << q.front() << endl;

    // printing the queue
    while (!q.empty())
    {
        int data = q.front();
        cout << data << " ";
        q.pop();
    }
}