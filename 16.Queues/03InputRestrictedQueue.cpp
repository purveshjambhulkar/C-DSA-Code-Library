#include <iostream>
using namespace std;

class InputResQueue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    InputResQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_back(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue Overloaded\n";
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = data;
    }

    int pop_back()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        int pop = arr[rear];
        arr[rear] = -1;

        if (rear == front)
        {
            rear = front = -1;
        }
        else if (rear == 0)
        {
            rear = size - 1;
        }
        else
        {
            rear--;
        }
        return pop;
    }

    int pop_front()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        int pop = arr[front];
        arr[front] = -1;

        if (front == rear)
        {
            rear = front = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return pop;
    }

    void display()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }

        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < size; i++)
            {
                cout << arr[i] << " ";
            }

            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    InputResQueue Q(7);

    Q.push_back(1);
    Q.push_back(2);
    Q.push_back(3);
    Q.push_back(4);
    Q.push_back(5);
    Q.pop_front(); // Remove 1 from the front
    Q.display();

    return 0;
}
