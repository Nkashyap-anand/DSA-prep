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

// insertion in singly linked list

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

// deletion in singly linked list

void deleteVal(Node *&head, int val)
{
    Node *temp = head;
    Node *prev = NULL;

    // if head is to be deleted
    if (temp != NULL && temp->data == val)
    {
        head = temp->next;
        delete temp;
        return;
    }

    else
    {
        while (temp != NULL && temp->data != val)
        {
            prev = temp;
            temp = temp->next;
        }

        // if there is no such value in list
        if (temp == NULL)
            return;

        prev->next = temp->next;
        delete temp;
    }
}

void deletePos(Node *&head, int pos)
{
    Node *temp = head;
    Node *prev = NULL;

    int count = 0;

    // if deleting head
    if (pos == 0)
    {
        head = temp->next;
        delete temp;
        return;
    }

    else
    {

        while (count != pos)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }

        prev->next = temp->next;
        delete temp;
    }
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

    deleteVal(head, 4);
    printList(head);

    deletePos(head, 2);
    printList(head);

    return 0;
}