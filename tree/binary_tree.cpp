#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void inorder(struct Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
void postorder(struct Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    inorder(root->right);
    cout << root->data << endl;
}

void preorder(struct Node *root)
{
    if (!root)
        return;
    cout << root->data << endl;
    inorder(root->left);
    inorder(root->right);
}

int main()
{
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);

    return 0;
}