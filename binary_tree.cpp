#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *insert(Node *root, int x)
{
    if (root == NULL)
        return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

bool search(Node *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (x < root->data)
        return search(root->left, x);

    return search(root->right, x);
}

Node *minNode(Node *root)
{
    while (root->left != NULL)
        root = root->left;

    return root;
}

Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);

    else if (x > root->data)
        root->right = deleteNode(root->right, x);

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        Node *temp = minNode(root->right);

        root->data = temp->data;

        root->right =
            deleteNode(root->right, temp->data);
    }

    return root;
}

void display(Node *root)
{
    if (root == NULL)
        return;

    display(root->left);
    cout << root->data << " ";
    display(root->right);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    display(root);

    root = insert(root, 25);
    display(root);

    cout << (search(root, 40) ? "Found" : "Not Found");

    cout << (search(root, 100) ? "Found" : "Not Found");

    root = deleteNode(root, 20);
    display(root);

    root = deleteNode(root, 30);
    display(root);

    cout << (search(root, 20) ? "Found" : "Not Found");

    root = deleteNode(root, 50);
    display(root);

    return 0;
}