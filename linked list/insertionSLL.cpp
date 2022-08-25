#include <bits/stdc++.h>
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

void insertAtStart(Node *&head, int new_data)
{
    Node *node = new Node(new_data);
    node->next = head;
    head = node;
}

void insertAfter(Node *&head, int key, int new_data)
{
    Node *node = new Node(new_data);

    if (head->data == key)
    {
        node->next = head->next;
        head->next = node;
        return;
    }

    Node *temp = head;

    while (temp->data != key)
    {
        temp = temp->next;
        if (temp == NULL)
            return;
    }

    node->next = temp->next;
    temp->next = node;
}

void insertAtEnd(Node *&head, int new_data)
{
    Node *node = new Node(new_data);
    if (head == NULL)
    {
        head = node;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
}

void insertAtPosition(Node *&head, int pos, int new_data)
{
    Node *node = new Node(new_data);
    if (head == NULL)
    {
        head = node;
        return;
    }

    Node *temp = head;
    int count = 0;

    while (count != pos)
    {
        temp = temp->next;
        count++;
    }

    node->next = temp->next;
    temp->next = node;
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
    Node *head = NULL;

    printList(head);

    insertAtStart(head, 2);
    printList(head);

    insertAtStart(head, 1);
    printList(head);

    insertAtEnd(head, 3);
    printList(head);

    insertAtEnd(head, 4);
    printList(head);

    insertAfter(head, 2, 5);
    printList(head);

    insertAfter(head, 0, 6);
    printList(head);

    insertAtPosition(head, 0, 10);
    printList(head);

    return 0;
}