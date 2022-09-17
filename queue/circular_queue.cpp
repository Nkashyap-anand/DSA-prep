#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int val)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            cout << "queue is full" << endl;

        else if (front == -1) // first elm
            front = rear = 0;

        else if (rear == size - 1 && front != 0) // maintain cycle
            rear = 0;
        else
            rear++;
        arr[rear] = val;
    }

    void dequeue()
    {
        if (front == -1)
            cout << "queue is empty" << endl;

        arr[front] = -1;

        if (front == rear) // single elm is present
            front = rear = -1;

        else if (front == size - 1) // maintain cycle
            front = 0;

        else
            front++;
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
    CircularQueue q(5);

    q.enqueue(5);
    cout << q.qfront() << endl;
    q.dequeue();
    cout << q.qfront() << endl;
    q.enqueue(3);
    cout << q.qfront() << endl;

    return 0;
}