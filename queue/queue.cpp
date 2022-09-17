#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue()
    {
        size = 10;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        if (front == rear)
            return true;
        return false;
    }

    void enqueue(int val)
    {
        if (rear == size)
            cout << "queue is fulll" << endl;
        else
        {
            arr[rear] = val;
            rear++;
        }
    }

    void dequeue()
    {
        if (front == rear)
            cout << "queue is empty" << endl;
        else
        {
            arr[front] = -1;
            front++;

            if (front == rear) // now queue is empty so go to start
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int qfront()
    {
        if (front == rear)
            return -1;
        else
            return arr[front];
    }
};

int main()
{
    Queue q;

    q.enqueue(5);
    cout << q.qfront() << endl;
    q.enqueue(4);
    cout << q.qfront() << endl;
    q.enqueue(3);
    cout << q.qfront() << endl;

    return 0;
}