#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertHead(Node *&head, int d)
{
    if (head == NULL)
    {
        head = new Node(d);
        return;
    }
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertTail(Node *&head, int d)
{
    if (head == NULL)
    {
        insertHead(head, d);
    }
    Node *node = new Node(d);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
}

void insertAt(Node *&head, int pos, int val)
{
    if (pos == 1)
    {
        insertHead(head, val);
        return;
    }
    Node *node = new Node(val);
    Node *temp = head;
    int count = 1;

    while (count != pos)
    {
        temp = temp->next;
        count++;
    }

    Node *NEXT = temp->next;
    temp->next = node;
    node->prev = temp;
    node->next = NEXT;
    NEXT->prev = node;
}

void insertAfter(Node *&start, int value1, int value2)
{
    Node *new_node = new Node(value1);

    // Find node having value2 and next node of it
    Node *temp = start;
    while (temp->data != value2)
        temp = temp->next;
    Node *next = temp->next;

    // insert new_node between temp and next.
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}

void printList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node = new Node(10);
    Node *head = node;
    printList(head);
    insertHead(head, 2);
    printList(head);
    insertTail(head, 1);
    printList(head);
    insertHead(head, 4);
    printList(head);
    insertTail(head, 6);
    printList(head);
    insertAfter(head, 2, 4);
    printList(head);
    insertAt(head, 1, 7);
    printList(head);
    insertAt(head, 6, 7);
    printList(head);

    return 0;
}