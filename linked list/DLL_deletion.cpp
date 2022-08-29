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

void deleteElm(Node *&head, int val)
{
    if (head == NULL)
    {
        cout << "Linked List Empty, nothing to delete" << endl;
        return;
    }
    Node *temp = head;
    Node *PREV = NULL;
    if (temp->data == val)
    {
        head = temp->next;
        head->prev = PREV;
        return;
    }

    while (temp->data != val)
    {
        PREV = temp;
        temp = temp->next;
    }

    PREV->next = temp->next;
    free(temp);
}

int main()
{
    Node *node = new Node(1);
    Node *head = node;
    printList(head);
    insertHead(head, 2);
    printList(head);
    insertTail(head, 3);
    printList(head);
    insertHead(head, 4);
    printList(head);
    insertTail(head, 5);
    printList(head);
    deleteElm(head, 2);
    printList(head);
    insertHead(head, 11);
    printList(head);
    deleteElm(head, 11);
    printList(head);

    return 0;
}